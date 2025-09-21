/**
 * @file fw_visualizer_node.cpp
 * @author Gemini (adapted from original by Peixuan Shu)
 * @brief ROS 2 node to visualize the fixed-wing aircraft from the fw_sim_node.
 *        It subscribes to the simulator's odometry topic and publishes
 *        TF, joint states for the propeller, a history path, and a name marker for RViz2.
 * @version 2.0 (ROS 2)
 * @date 2025-09-07
 * 
 * @license BSD 3-Clause License
 * @copyright (c) 2024, Peixuan Shu
 * All rights reserved.
 * 
 */

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <deque>
#include <string>
#include <cmath>

#include "sim_msgs/msg/death_notice.hpp"


// 为了满足“无头文件”的要求，我们将类定义直接放在 .cpp 文件中
class FwVisualizerNode : public rclcpp::Node
{
public:
    FwVisualizerNode() : Node("fw_visualizer_node")
    {
        // --- 1. 声明并获取参数 ---
        this->declare_parameter<std::string>("odom_topic", "odom");
        this->declare_parameter<std::string>("tf_frame", "odom");
        this->declare_parameter<std::string>("base_link_frame", "base_link");
        this->declare_parameter<std::string>("propeller_joint_name", "rotor_puller_joint");
        this->declare_parameter<double>("visualization_frequency", 30.0);
        this->declare_parameter<double>("path_history_duration_s", 10.0);
        this->declare_parameter<double>("propeller_rpm", 2000.0);
        this->declare_parameter<std::string>("uav_name", "FixedWing");

        odom_topic_ = this->get_parameter("odom_topic").as_string();
        tf_frame_ = this->get_parameter("tf_frame").as_string();
        base_link_frame_ = this->get_parameter("base_link_frame").as_string();
        propeller_joint_name_ = this->get_parameter("propeller_joint_name").as_string();
        double pub_freq = this->get_parameter("visualization_frequency").as_double();
        path_duration_ = this->get_parameter("path_history_duration_s").as_double();
        propeller_rpm_ = this->get_parameter("propeller_rpm").as_double();
        uav_name_ = this->get_parameter("uav_name").as_string();

        // --- 2. 初始化ROS通信 ---
        // 订阅来自仿真节点的里程计消息
        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            odom_topic_, 10, std::bind(&FwVisualizerNode::odom_callback, this, std::placeholders::_1));

        joint_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10); // 发布模型关节状态（用于驱动螺旋桨旋转）
        path_pub_ = this->create_publisher<nav_msgs::msg::Path>("history_path", 10);   // 发布历史轨迹
        marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("uav_name_marker", 10);  // 发布无人机名称的Marker

        // 初始化TF广播器
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

        // death notice
        deathnotice_sub_ = this->create_subscription<sim_msgs::msg::DeathNotice>(
            "deathnotice", 10, std::bind(&FwVisualizerNode::deathnotice_callback, this, std::placeholders::_1));

        // --- 3. 设置主循环定时器 ---
        // --- 定时器 ---
        auto node_base_interface = this->get_node_base_interface();
        auto node_timers_interface = this->get_node_timers_interface();
        auto clock = this->get_clock();

        visualize_timer_ = rclcpp::create_timer(
            node_base_interface,
            node_timers_interface,
            clock,
            rclcpp::Duration::from_seconds(1.0 / pub_freq),
            std::bind(&FwVisualizerNode::visualizeLoop, this)
        );

        RCLCPP_INFO(this->get_logger(), "Fixed-wing visualizer node has started.");
        RCLCPP_INFO(this->get_logger(), "Listening for odom on topic: %s", odom_topic_.c_str());
    }

private:

    /**
     * @brief Transforms a pose from NED (simulation) to ENU (ROS) coordinates.
     * @param pose_ned The input pose in North-East-Down frame.
     * @param pose_enu The output pose in East-North-Up frame.
     */
    void transform_pose_ned_to_enu(const geometry_msgs::msg::Pose& pose_ned, geometry_msgs::msg::Pose& pose_enu)
    {
        // 1. Transform Position (NED -> ENU)
        // ROS_X (East)  = Sim_Y (East)
        // ROS_Y (North) = Sim_X (North)
        // ROS_Z (Up)    = -Sim_Z (Down)
        pose_enu.position.x = pose_ned.position.y;
        pose_enu.position.y = pose_ned.position.x;
        pose_enu.position.z = -pose_ned.position.z;

        // 2. 转换姿态 (核心部分)
        // 从 geometry_msgs::msg::Quaternion 转换到 tf2::Quaternion 以便进行数学运算
        tf2::Quaternion q_ned_frd;
        tf2::fromMsg(pose_ned.orientation, q_ned_frd);

        // 定义一个固定的旋转，用于将NED世界系转换为ENU世界系
        // 该旋转等效于：首先绕原始Z轴(Down)偏航+90度，然后绕新的X轴(East)滚转+180度
        tf2::Quaternion q_enu_from_ned;
        q_enu_from_ned.setRPY(M_PI, 0.0, M_PI_2);

        // 定义一个固定的旋转，用于将FRD机体约定转换为ROS常用的FLU机体约定
        // 该旋转等效于绕机体的X轴(Forward)滚转180度
        tf2::Quaternion q_flu_from_frd;
        q_flu_from_frd.setRPY(M_PI, 0.0, 0.0);

        // --- 应用组合变换 ---
        // 最终的姿态是在ENU坐标系下，以FLU为约定的姿态
        // 计算方法：首先将NED下的姿态转换到ENU系下，然后应用机体约定变换
        // q_C' = (q_B_from_A * q_C) * q_C'_from_C
        // 其中 C' 是FLU, C 是FRD, B 是ENU, A 是NED
        // 但由于FLU和FRD的定义是相对于机体自身的，可以直接后乘
        
        tf2::Quaternion q_enu_flu = q_enu_from_ned * q_ned_frd * q_flu_from_frd;


        // 归一化四元数以保证其有效性
        q_enu_flu.normalize();

        // 将计算结果转换回 geometry_msgs::msg::Quaternion 并赋值
        pose_enu.orientation = tf2::toMsg(q_enu_flu);
    }

    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        // 收到里程计消息后，存储起来以备定时器使用
        last_odom_msg_ = *msg;
        odom_received_ = true;
    }

    void deathnotice_callback(const sim_msgs::msg::DeathNotice::SharedPtr msg)
    {
        RCLCPP_WARN(this->get_logger(), "Visualizer for %s received death notice. Cleaning up RViz and showing crash.", this->get_namespace());

        // 关键 1: 立即停止定时器
        visualize_timer_->cancel();

        // 关键 2: 清理RViz中的现有可视化元素
        // a) 发布一个空的Path消息，立即清除RViz中的轨迹
        nav_msgs::msg::Path empty_path;                  
        empty_path.header.stamp = this->get_clock()->now();
        empty_path.header.frame_id = tf_frame_;
        path_pub_->publish(empty_path);
        // b) 发布一个DELETE动作的Marker，立即删除RViz中的无人机名称
        visualization_msgs::msg::Marker delete_marker;  
        delete_marker.header.frame_id = base_link_frame_;   
        delete_marker.header.stamp = this->get_clock()->now();
        delete_marker.ns = "uav_name";     // ns和id必须与要删除的marker匹配
        delete_marker.id = 0;
        delete_marker.action = visualization_msgs::msg::Marker::DELETE;    // 设置动作为DELETE
        marker_pub_->publish(delete_marker);
        // c) 发布一个TF变换，将无人机移动到“坠毁”位置（坠毁变换）
        geometry_msgs::msg::TransformStamped crash_tf; 
        crash_tf.header.stamp = this->get_clock()->now();
        crash_tf.header.frame_id = tf_frame_;
        crash_tf.child_frame_id = base_link_frame_;
        crash_tf.transform.translation.x = 0.0;  // 设置坠毁位置
        crash_tf.transform.translation.y = 0.0;
        crash_tf.transform.translation.z = 3000.0;
        crash_tf.transform.rotation.x = 0.0;     // 设置一个默认姿态（无旋转，即单位四元数）
        crash_tf.transform.rotation.y = 0.0;
        crash_tf.transform.rotation.z = 0.0;
        crash_tf.transform.rotation.w = 1.0;
        tf_broadcaster_->sendTransform(crash_tf);
        std::this_thread::sleep_for(std::chrono::seconds(3)); // 可视化螺旋桨关闭延时 3 秒（不然螺旋桨会滞留）
        // d) 告诉 robot_state_publisher 将螺旋桨置于其默认的0度角位置。从而确保它能跟随 base_link 一起移动到坠毁位置。
        sensor_msgs::msg::JointState final_joint_state;
        final_joint_state.header.stamp = this->get_clock()->now();
        final_joint_state.name.push_back(propeller_joint_name_);
        final_joint_state.position.push_back(0.0); // 设置螺旋桨角度为0
        joint_pub_->publish(final_joint_state);
        
        // 关键 3: 释放资源  重置所有通信，让节点进入空闲状态
        odom_sub_.reset();
        deathnotice_sub_.reset();
        // joint_pub_.reset();
        // path_pub_.reset();
        // marker_pub_.reset();
        // tf_broadcaster_.reset();

        RCLCPP_INFO(this->get_logger(), "Cleanup for %s complete. Visualizer is now idle.", this->get_namespace());
        rclcpp::shutdown();    // 关闭 ros 节点
    }

    void visualizeLoop()
    {
        if (!odom_received_) {
            // 如果还没收到任何里程计消息，就不执行任何操作
            return;
        }
        // 调用所有发布函数
        publish_tf();
        publish_propeller_joint_state();
        publish_path();
        publish_uav_name_marker();
    }

    void publish_tf()
    {
        geometry_msgs::msg::TransformStamped t;

        t.header.stamp = last_odom_msg_.header.stamp;
        t.header.frame_id = tf_frame_;
        t.child_frame_id = base_link_frame_;

        geometry_msgs::msg::Pose transformed_pose;
        transform_pose_ned_to_enu(last_odom_msg_.pose.pose, transformed_pose);
        
        // 从最新的里程计消息中获取位姿
        t.transform.rotation      = transformed_pose.orientation;
        t.transform.translation.x = transformed_pose.position.x;
        t.transform.translation.y = transformed_pose.position.y;
        t.transform.translation.z = transformed_pose.position.z;
        
        tf_broadcaster_->sendTransform(t);
    }

    void publish_propeller_joint_state()
    {
        sensor_msgs::msg::JointState joint_state_msg;
        joint_state_msg.header.stamp = this->get_clock()->now();
        joint_state_msg.name.push_back(propeller_joint_name_);

        // 根据RPM计算角速度 (rad/s)
        double omega = propeller_rpm_ * 2.0 * M_PI / 60.0;

        // 计算从上次发布以来的时间增量
        double current_time = this->now().seconds();
        double dt = (last_joint_pub_time_ > 0) ? (current_time - last_joint_pub_time_) : 0.0;
        last_joint_pub_time_ = current_time;

        // 更新关节角度
        propeller_angle_ += omega * dt;
        // 保持角度在 -pi 到 pi 之间 (可选，但良好实践)
        propeller_angle_ = fmod(propeller_angle_, 2.0 * M_PI);
        if (propeller_angle_ > M_PI) {
            propeller_angle_ -= 2.0 * M_PI;
        }

        joint_state_msg.position.push_back(propeller_angle_);
        joint_pub_->publish(joint_state_msg);
    }

    void publish_path()
    {
        // 将当前位姿添加到历史轨迹队列
        geometry_msgs::msg::PoseStamped current_pose;
        current_pose.header = last_odom_msg_.header;
        transform_pose_ned_to_enu(last_odom_msg_.pose.pose, current_pose.pose);
        history_path_.push_back(current_pose);

        // 如果队列太长，从队首移除旧的位姿
        while (history_path_.size() > 1 &&
               (rclcpp::Time(history_path_.back().header.stamp) - rclcpp::Time(history_path_.front().header.stamp)).seconds() > path_duration_)
        {
            history_path_.pop_front();
        }

        // 创建并发布 Path 消息
        nav_msgs::msg::Path path_msg;
        path_msg.header.stamp = this->get_clock()->now();
        path_msg.header.frame_id = tf_frame_;
        path_msg.poses.assign(history_path_.begin(), history_path_.end());

        path_pub_->publish(path_msg);
    }

    void publish_uav_name_marker()
    {
        visualization_msgs::msg::Marker marker;
        marker.header.frame_id = base_link_frame_; // 将Marker附着在无人机模型上
        marker.header.stamp = this->get_clock()->now();
        marker.ns = "uav_name";
        marker.id = 0;
        marker.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
        marker.action = visualization_msgs::msg::Marker::ADD;

        // 设置文本相对于无人机模型的位置（例如，在模型上方）
        marker.pose.position.x = 5.7;
        marker.pose.position.y = 4.7;
        marker.pose.position.z = 1.0; 
        
        // 尺寸和颜色
        marker.scale.x = 4.0; // 文本高度
        marker.scale.y = 4.0; // 文本高度
        marker.scale.z = 4.0; // 文本高度
        marker.color.a = 1.0;
        marker.color.r = 0.0;
        marker.color.g = 0.0;
        marker.color.b = 0.0;
        
        marker.text = uav_name_;
        marker.frame_locked = true; // 确保文本跟随 base_link

        marker_pub_->publish(marker);
    }

    // ROS 通信相关的成员
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Subscription<sim_msgs::msg::DeathNotice>::SharedPtr deathnotice_sub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    rclcpp::TimerBase::SharedPtr visualize_timer_;

    // 参数存储
    std::string odom_topic_;
    std::string tf_frame_;
    std::string base_link_frame_;
    std::string propeller_joint_name_;
    double path_duration_;
    double propeller_rpm_;
    std::string uav_name_;

    // 状态存储
    bool odom_received_{false};
    nav_msgs::msg::Odometry last_odom_msg_;
    std::deque<geometry_msgs::msg::PoseStamped> history_path_;
    double propeller_angle_{0.0};
    double last_joint_pub_time_{0.0};
};

// --- Main函数 ---
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FwVisualizerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}