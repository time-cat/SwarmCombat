/**
 * @file fw_logic_node.cpp
 * @author Tong
 * @brief Standalone ROS 2 node for a single fixed-wing UAV's logic in a swarm.
 *        Handles detection, communication, decision-making, and motion planning.
 *        Subscribes to its own simulator state and swarm messages, and publishes
 *        control commands and swarm messages.
 *
 * @version 2.0 (ROS 2)
 * @date 2025-09-08
 *
 * @license BSD 3-Clause License
 * @copyright (c) 2025, Your Name/Organization
 * All rights reserved.
 *
 */

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <mutex>
#include <stdexcept> // for std::runtime_error

// ROS 2 Standard Messages
#include <geometry_msgs/msg/point.hpp>
#include <nav_msgs/msg/odometry.hpp>

#include "fwp_planner/algorithms/base_algorithm.hpp"
#include "fwp_planner/algorithms/apf_algorithm.hpp"
#include "fwp_planner/algorithms/guidance_algorithm.hpp"

// Assumed Custom Swarm Messages (converted to ROS 2)
#include "fwp_planner/msg/dynamic_state.hpp"
#include "fwp_planner/msg/fused_enemy.hpp"
#include "fwp_planner/msg/fused_teammate.hpp"
#include "fwp_planner/msg/team_broadcast.hpp"
#include "fwp_planner/msg/team_multicast.hpp"

#include "sim_msgs/msg/perceived_state.hpp"
#include "sim_msgs/msg/explosion_report.hpp"
#include "sim_msgs/msg/fw_control.hpp"
#include "sim_msgs/msg/death_notice.hpp"

// TF2 for quaternion math
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "fwp_planner/types.hpp"


// The main logic node class
class FwLogicNode : public rclcpp::Node
{
public:
    FwLogicNode() : Node("fw_logic_node")
    {
        // --- 1. Declare and Get Parameters ---
        this->declare_parameter<int>("id", 1);
        this->declare_parameter<std::string>("team", "red");
        this->declare_parameter<double>("fov_range", 1000.0);
        this->declare_parameter<double>("fov_angle", 1.9); // radians
        this->declare_parameter<double>("com_range", 1200.0);
        this->declare_parameter<double>("exp_range", 80.0);
        this->declare_parameter<double>("stale_data_timeout", 5.0); // seconds
        this->declare_parameter<double>("logic_rate", 20.0); // Hz
        this->declare_parameter<std::string>("algorithm_type", "APF");

        id_ = this->get_parameter("id").as_int();
        team_ = this->get_parameter("team").as_string();
        fov_range_ = this->get_parameter("fov_range").as_double();
        fov_angle_ = this->get_parameter("fov_angle").as_double();
        com_range_ = this->get_parameter("com_range").as_double();
        exp_range_ = this->get_parameter("exp_range").as_double();
        stale_data_timeout_ = this->get_parameter("stale_data_timeout").as_double();
        algorithm_type_ = this->get_parameter("algorithm_type").as_string();
        
        RCLCPP_INFO(this->get_logger(), "Loading algorithm of type: %s", algorithm_type_.c_str());
        if (algorithm_type_ == "APF") {
            algorithm_ = std::make_unique<ApfAlgorithm>(this);
        }
        else if (algorithm_type_ == "Guidance") {
            algorithm_ = std::make_unique<GuidanceAlgorithm>(this);
        }
        else {
            RCLCPP_FATAL(this->get_logger(), "Unknown algorithm_type: '%s'. Shutting down.", algorithm_type_.c_str());
            throw std::runtime_error("Invalid algorithm_type specified");   // 抛出异常或直接关闭节点
        }

        RCLCPP_INFO(this->get_logger(), "Starting FwLogicNode for UAV ID %d on team '%s'", id_, team_.c_str());

        // --- 2. Initialize ROS 2 Communications ---
        std::string team_topic_prefix = std::string("/") + team_;
        std::string enemy_team = (team_ == "red") ? "blue" : "red";
        std::string enemy_topic_prefix = std::string("/") + enemy_team;

        // Publishers
        control_pub_ = this->create_publisher<sim_msgs::msg::FwControl>("fw_control", 10);   // sim_node
        perceivedstate_pub_ = this->create_publisher<sim_msgs::msg::PerceivedState>(team_topic_prefix + "/perceivedstate", 10);
        teambroadcast_pub_  = this->create_publisher<fwp_planner::msg::TeamBroadcast>(team_topic_prefix + "/teambroadcast", 10);
        teammulticast_pub_  = this->create_publisher<fwp_planner::msg::TeamMulticast>(team_topic_prefix + "/teammulticast", 10);
        explosion_pub_      = this->create_publisher<sim_msgs::msg::ExplosionReport>("/simulation/explosions", 10);

        // Subscribers
        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "odom", 10, std::bind(&FwLogicNode::odom_callback, this, std::placeholders::_1));  // sim_node
        perceivedstate_sub_ = this->create_subscription<sim_msgs::msg::PerceivedState>(
            enemy_topic_prefix + "/perceivedstate", 100, std::bind(&FwLogicNode::detection_callback, this, std::placeholders::_1));
        teambroadcast_sub_ = this->create_subscription<fwp_planner::msg::TeamBroadcast>(
            team_topic_prefix + "/teambroadcast", 50, std::bind(&FwLogicNode::teambroadcast_callback, this, std::placeholders::_1));
        teammulticast_sub_ = this->create_subscription<fwp_planner::msg::TeamMulticast>(
            team_topic_prefix + "/teammulticast", 50, std::bind(&FwLogicNode::teammulticast_callback, this, std::placeholders::_1));
        explosion_sub_     = this->create_subscription<sim_msgs::msg::ExplosionReport>(
            "/simulation/explosions", 10, std::bind(&FwLogicNode::explosion_callback, this, std::placeholders::_1));

        // Death Notice
        deathnotice_pub_ = this->create_publisher<sim_msgs::msg::DeathNotice>("deathnotice", rclcpp::QoS(1).transient_local());

        // --- 3. Setup Main Logic Timer ---
        double logic_rate          = this->get_parameter("logic_rate").as_double();
        auto node_base_interface   = this->get_node_base_interface();
        auto node_timers_interface = this->get_node_timers_interface();
        logic_timer_ = rclcpp::create_timer(
            node_base_interface,
            node_timers_interface,
            this->get_clock(),
            rclcpp::Duration::from_seconds(1.0 / logic_rate),
            std::bind(&FwLogicNode::logic_loop, this)
        );
    }

private:
    // --- Main Logic Loop (driven by timer) ---
    void logic_loop()
    {
        if (!state_received_) {
            return;
        }
        if (!is_alive_) {
            // 退出循环，删除可视化相关内容，删除自身节点
            // RCLCPP_WARN(this->get_logger(), "UAV %d is shutting down!", id_);
            logic_timer_->cancel();  // 停止主循环
            PreShutdown();           // 关闭前的准备
            rclcpp::shutdown();      // 请求 ROS 关闭本节点
            return;
        }

        bool trigger_hit = false;
        std::lock_guard<std::mutex> lock(state_mutex_);  // Lock to ensure state data is consistent during the logic cycle
        // 1. 感知：获取战场态势信息（自己、队友、敌方）
        // detection_callback     更新邻近敌方的态势信息
        // teambroadcast_callback 更新邻近友方的态势信息
        // teammulticast_callback 更新全局敌方友方的态势信息
        // 2. 预测：利用战场态势信息（将延迟的态势信息估计到当前）
        // TODO:
        CleanStaleData();
        // 3. 决策：是否自爆或者决定打击目标
        target_id_ = algorithm_->select_target(dynamic_state_, known_enemies_, known_teammates_);
        trigger_hit = algorithm_->decide_explode(target_id_, exp_range_, dynamic_state_, known_enemies_);
        // 4. 规划：规划飞行轨迹
        sim_msgs::msg::FwControl ctrl_cmd = algorithm_->calculate_motion(target_id_, dynamic_state_, known_enemies_, teambroadcast_info_);
        // 5. 控制：发布控制指令（给内环控制）
        // TODO: 外环控制器
        control_pub_->publish(ctrl_cmd);
        // 6. 自身状态信息发布
        if(trigger_hit) {
            RCLCPP_INFO(this->get_logger(), "UAV %d: Target %d is in blast radius!", id_, target_id_);
            is_alive_ = false;
            explosion_publish();
            RCLCPP_WARN(this->get_logger(), "UAV %d: BOOM! Shutting down logic loop.", id_);
            return; // Stop further processing after self-destruct
        }
        perceivedstate_publish();
        if (mainloop_cnt_ % 3 != 0) {  // 组播广播通信
            teambroadcast_publish();
        } else {
            teammulticast_publish();
        }
        mainloop_cnt_++;
    }

    // --- Callbacks ---
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        std::lock_guard<std::mutex> lock(state_mutex_);
        
        // Convert ROS2 Odometry to  DynamicState (NED)
        dynamic_state_.posi_n = msg->pose.pose.position.x;
        dynamic_state_.posi_e = msg->pose.pose.position.y;
        dynamic_state_.posi_d = msg->pose.pose.position.z;

        position_ = geometry_msgs::build<geometry_msgs::msg::Point>()
            .x(dynamic_state_.posi_n)
            .y(dynamic_state_.posi_e)
            .z(dynamic_state_.posi_d);
        
        dynamic_state_.orient_x = msg->pose.pose.orientation.x;
        dynamic_state_.orient_y = msg->pose.pose.orientation.y;
        dynamic_state_.orient_z = msg->pose.pose.orientation.z;
        dynamic_state_.orient_w = msg->pose.pose.orientation.w;

        auto vel = msg->twist.twist.linear;
        dynamic_state_.vel = std::sqrt(vel.x*vel.x + vel.y*vel.y + vel.z*vel.z);

        state_received_ = true;
    }
    
    void detection_callback(const sim_msgs::msg::PerceivedState::SharedPtr msg)
    {
        if (!is_alive_ || !msg->is_alive) return;
        
        if (IsInFov(msg)) {
            StoredEnemyInfo info;
            info.position = msg->position;
            info.timestamp = this->get_clock()->now();
            known_enemies_[msg->id] = info;
        }
    }
    
    void teambroadcast_callback(const fwp_planner::msg::TeamBroadcast::SharedPtr msg)
    {
        if (!is_alive_ || msg->sender_id == id_ || !msg->is_alive) return;

        if (IsInBroadcast(msg)) {
            StoredBroadcastInfo info;
            info.dynamic_state = msg->dynamic_state;
            info.timestamp = msg->header.stamp;
            teambroadcast_info_[msg->sender_id] = info;
        }
    }

    void teammulticast_callback(const fwp_planner::msg::TeamMulticast::SharedPtr msg)
    {
        if (!is_alive_ || msg->sender_id == id_ || !msg->is_alive) return;
        
        if (IsInMulticast(msg)) {
            // Fuse enemy info
            for (const auto& enemy : msg->known_enemies) {
                if (!known_enemies_.count(enemy.id) || 
                    rclcpp::Time(enemy.timestamp) > known_enemies_[enemy.id].timestamp) {
                    StoredEnemyInfo info;
                    info.position = enemy.position;
                    info.timestamp = enemy.timestamp;
                    known_enemies_[enemy.id] = info;
                }
            }
            // Fuse teammate target info
            for (const auto& mate : msg->known_teammates) {
                if (mate.id == id_) continue;
                if (!known_teammates_.count(mate.id) || 
                    rclcpp::Time(mate.timestamp) > known_teammates_[mate.id].timestamp) {
                    StoredTeammateInfo info;
                    info.target_id = mate.target_id;
                    info.timestamp = mate.timestamp;
                    known_teammates_[mate.id] = info;
                }
            }
            // Update teammate state from multicast message
            StoredBroadcastInfo info;
            info.dynamic_state = msg->dynamic_state;
            info.timestamp = msg->header.stamp;
            teambroadcast_info_[msg->sender_id] = info; // std::map::operator[] overwrites, no memory leak.
        }
    }
    
    void explosion_callback(const sim_msgs::msg::ExplosionReport::SharedPtr msg)
    {
        if (!is_alive_) return;

        // 检查时间戳
        rclcpp::Duration delay = this->get_clock()->now() - msg->header.stamp;
        if (delay.seconds() > 1.0) {
            RCLCPP_FATAL(this->get_logger(), "UAV %d: Received STALE explosion report from UAV %d! Latency: %.2f s.", 
                 id_, msg->attacker_id, delay.seconds());
        }

        if (IsInExplosion(msg)) {
            RCLCPP_WARN(this->get_logger(), "UAV %d: HIT by explosion from UAV %d! Shutting down.", id_, msg->attacker_id);
            is_alive_ = false;
        }
    }
    
    // --- Logic & Helper Functions (adapted from ROS 1 version) ---

    bool IsInFov(const sim_msgs::msg::PerceivedState::SharedPtr& msg)
    {
        // 1. 计算从无人机指向目标的向量 (在NED坐标系下)
        double dx = msg->position.x - dynamic_state_.posi_n;
        double dy = msg->position.y - dynamic_state_.posi_e;
        double dz = msg->position.z - dynamic_state_.posi_d;
        
        // 2. 计算目标距离，并进行范围检查
        double dist_sq = dx*dx + dy*dy + dz*dz; // 先用平方距离避免开方
        if (dist_sq > fov_range_ * fov_range_ || dist_sq < 1e-12) {
            return false;
        }
        double dist = std::sqrt(dist_sq);

        // 3. 使用四元数计算无人机的前向向量 (在NED坐标系下)
        // 无人机在自身坐标系(body frame)的前向向量是 [1, 0, 0]
        // 我们需要用姿态四元数 q = (w, x, y, z) 将这个向量旋转到NED坐标系
        double qw = dynamic_state_.orient_w;
        double qx = dynamic_state_.orient_x;
        double qy = dynamic_state_.orient_y;
        double qz = dynamic_state_.orient_z;

        // 这是通过旋转矩阵的第一列得到的标准公式，用于将向量[1,0,0]从机体坐标系转换到世界坐标系
        double heading_x = 1.0 - 2.0 * (qy*qy + qz*qz);
        double heading_y = 2.0 * (qx*qy + qw*qz);
        double heading_z = 2.0 * (qx*qz - qw*qy);

        // 4. 计算前向向量和目标向量的点积
        double dot_product = heading_x * dx + heading_y * dy + heading_z * dz;

        // 5. 计算两个向量夹角的余弦值
        // 因为 heading 向量是单位向量，所以 |heading| = 1
        // dot_product = |heading| * |target_vec| * cos(angle) = 1 * dist * cos(angle)
        double cos_angle = dot_product / dist;

        // 6. 检查夹角是否在FoV的一半以内
        // 直接比较余弦值可以避免反余弦(acos)的计算，效率更高
        // angle <= fov_angle / 2  等价于 cos(angle) >= cos(fov_angle / 2)
        return cos_angle >= std::cos(fov_angle_ / 2.0);
    }

    bool IsInBroadcast(const fwp_planner::msg::TeamBroadcast::SharedPtr& msg)
    {
        double dx = msg->dynamic_state.posi_n - dynamic_state_.posi_n;
        double dy = msg->dynamic_state.posi_e - dynamic_state_.posi_e;
        double dz = msg->dynamic_state.posi_d - dynamic_state_.posi_d;
        double dist = std::sqrt(dx*dx + dy*dy + dz*dz);
        return dist <= msg->broadcast_range;
    }
    
    bool IsInMulticast(const fwp_planner::msg::TeamMulticast::SharedPtr& msg)
    {
        double dx = msg->dynamic_state.posi_n - dynamic_state_.posi_n;
        double dy = msg->dynamic_state.posi_e - dynamic_state_.posi_e;
        double dz = msg->dynamic_state.posi_d - dynamic_state_.posi_d;
        double dist = std::sqrt(dx*dx + dy*dy + dz*dz);
        return dist <= msg->multicast_range;
    }

    bool IsInExplosion(const sim_msgs::msg::ExplosionReport::SharedPtr& msg)
    {
        double dx = msg->exp_center.x - dynamic_state_.posi_n;
        double dy = msg->exp_center.y - dynamic_state_.posi_e;
        double dz = msg->exp_center.z - dynamic_state_.posi_d;
        double dist = std::sqrt(dx*dx + dy*dy + dz*dz);
        return dist <= msg->exp_range;
    }

    void CleanStaleData()
    {
        rclcpp::Time current_time = this->get_clock()->now();
        rclcpp::Duration timeout = rclcpp::Duration::from_seconds(stale_data_timeout_);

        auto clean_map = [&](auto& map) {
            for (auto it = map.begin(); it != map.end(); ) {
                if (current_time - it->second.timestamp > timeout) {
                    it = map.erase(it);
                } else {
                    ++it;
                }
            }
        };

        clean_map(known_enemies_);
        clean_map(known_teammates_);
        clean_map(teambroadcast_info_);
    }

    // --- Publishing Functions ---
    void perceivedstate_publish()
    {
        sim_msgs::msg::PerceivedState msg;
        msg.header.stamp    = this->get_clock()->now();
        msg.header.frame_id = "map"; // Assuming a global NED frame
        msg.id              = id_;
        msg.position        = position_;
        msg.is_alive        = is_alive_;
        perceivedstate_pub_->publish(msg);
    }
    
    void teambroadcast_publish()
    {
        fwp_planner::msg::TeamBroadcast msg;
        msg.header.stamp    = this->get_clock()->now();
        msg.header.frame_id = "map";
        msg.sender_id       = id_;
        msg.broadcast_range = com_range_;
        msg.dynamic_state   = dynamic_state_;
        msg.is_alive        = is_alive_;
        teambroadcast_pub_->publish(msg);
    }

    void teammulticast_publish()
    {
        fwp_planner::msg::TeamMulticast msg;
        msg.header.stamp    = this->get_clock()->now();
        msg.header.frame_id = "map";
        msg.sender_id       = id_;
        msg.multicast_range = com_range_;
        msg.known_enemies   = convert_enemy_map_to_msg_vector(known_enemies_);
        msg.known_teammates = convert_teammate_map_to_msg_vector(known_teammates_);
        msg.dynamic_state   = dynamic_state_;
        msg.is_alive        = is_alive_;
        teammulticast_pub_->publish(msg);
    }

    void explosion_publish()
    {
        sim_msgs::msg::ExplosionReport msg;
        msg.header.stamp    = this->get_clock()->now();
        msg.header.frame_id = "map";
        msg.attacker_id     = id_;
        msg.exp_center      = position_;
        msg.exp_range       = exp_range_;
        explosion_pub_->publish(msg);
    }

    // --- Conversion Helper Functions ---
    std::vector<fwp_planner::msg::FusedEnemy>
    convert_enemy_map_to_msg_vector(const std::map<int, StoredEnemyInfo>& enemy_map) const
    {
        std::vector<fwp_planner::msg::FusedEnemy> enemy_vector;
        enemy_vector.reserve(enemy_map.size());
        for (const auto& pair : enemy_map) {
            fwp_planner::msg::FusedEnemy enemy_msg;
            enemy_msg.id = pair.first;
            enemy_msg.position = pair.second.position;
            enemy_msg.timestamp = pair.second.timestamp;
            enemy_vector.push_back(enemy_msg);
        }
        return enemy_vector;
    }

    std::vector<fwp_planner::msg::FusedTeammate>
    convert_teammate_map_to_msg_vector(const std::map<int, StoredTeammateInfo>& teammate_map) const
    {
        std::vector<fwp_planner::msg::FusedTeammate> teammate_vector;
        teammate_vector.reserve(teammate_map.size());
        for (const auto& pair : teammate_map) {
            fwp_planner::msg::FusedTeammate teammate_msg;
            teammate_msg.id = pair.first;
            teammate_msg.target_id = pair.second.target_id;
            teammate_msg.timestamp = pair.second.timestamp;
            teammate_vector.push_back(teammate_msg);
        }
        return teammate_vector;
    }

    void PreShutdown()
    {
        // 发布“死亡通告”
        sim_msgs::msg::DeathNotice death_msg;
        death_msg.header.stamp = this->get_clock()->now();
        death_msg.death        = true;  // 可视化节点死亡
        deathnotice_pub_->publish(death_msg);
        RCLCPP_WARN(this->get_logger(), "UAV %s: FwLogicNode shutting down.", this->get_namespace());
        // 所有订阅者关闭
        odom_sub_.reset();
        perceivedstate_sub_.reset();
        teambroadcast_sub_.reset();
        teammulticast_sub_.reset();
        explosion_sub_.reset();
        // 其他
    }

    // --- State & Parameters ---
    int id_;
    std::string team_;
    double fov_range_, fov_angle_, com_range_, exp_range_, stale_data_timeout_;
    std::string algorithm_type_;
    std::unique_ptr<BaseAlgorithm> algorithm_;
    
    bool is_alive_ = true;
    bool state_received_ = false;
    int target_id_ = -1;

    unsigned long long mainloop_cnt_ = 0;
    
    fwp_planner::msg::DynamicState dynamic_state_;
    geometry_msgs::msg::Point position_;
    std::mutex state_mutex_;

    // Situational Awareness Data
    std::map<int, StoredEnemyInfo> known_enemies_;
    std::map<int, StoredTeammateInfo> known_teammates_;
    std::map<int, StoredBroadcastInfo> teambroadcast_info_;

    // --- ROS 2 Members ---
    rclcpp::Publisher<sim_msgs::msg::FwControl>::SharedPtr         control_pub_;
    rclcpp::Publisher<sim_msgs::msg::PerceivedState>::SharedPtr    perceivedstate_pub_;
    rclcpp::Publisher<sim_msgs::msg::ExplosionReport>::SharedPtr   explosion_pub_;
    rclcpp::Publisher<fwp_planner::msg::TeamBroadcast>::SharedPtr  teambroadcast_pub_;
    rclcpp::Publisher<fwp_planner::msg::TeamMulticast>::SharedPtr  teammulticast_pub_;
    
    rclcpp::Publisher<sim_msgs::msg::DeathNotice>::SharedPtr       deathnotice_pub_;

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr          odom_sub_;
    rclcpp::Subscription<sim_msgs::msg::PerceivedState>::SharedPtr    perceivedstate_sub_;
    rclcpp::Subscription<sim_msgs::msg::ExplosionReport>::SharedPtr   explosion_sub_;
    rclcpp::Subscription<fwp_planner::msg::TeamBroadcast>::SharedPtr  teambroadcast_sub_;
    rclcpp::Subscription<fwp_planner::msg::TeamMulticast>::SharedPtr  teammulticast_sub_;

    rclcpp::TimerBase::SharedPtr logic_timer_;
};


// --- Main function to run the node ---
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FwLogicNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}