#include <thread>  
#include <chrono> 
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <std_msgs/msg/float64.hpp>

#include "BHDynamic/BHDynamic.h"
#include "sim_msgs/msg/fw_control.hpp"
#include "sim_msgs/msg/death_notice.hpp"


class FwSimNode : public rclcpp::Node
{
public:
    FwSimNode() : Node("fw_sim_node")
    {
        // --- 参数声明和获取 ---
        this->declare_parameter<double>("initial_state.north", 0.0);
        this->declare_parameter<double>("initial_state.east", 0.0);
        this->declare_parameter<double>("initial_state.down", -100.0); // 初始高度100m
        this->declare_parameter<double>("initial_state.roll", 0.0);
        this->declare_parameter<double>("initial_state.pitch", 0.0);
        this->declare_parameter<double>("initial_state.yaw", 0.0);
        this->declare_parameter<double>("initial_state.airspeed", 20.0); // 初始空速

        this->declare_parameter<double>("rate.simulation", 100.0); // 动力学仿真频率
        this->declare_parameter<double>("rate.odom", 50.0);        // Odometry 发布频率
        
        // GPS原点 (用于将NED坐标转换为纬经高)
        this->declare_parameter<double>("gps_origin.latitude", 47.397742);
        this->declare_parameter<double>("gps_origin.longitude", 8.545594);
        this->declare_parameter<double>("gps_origin.altitude", 488.0);


        // --- 初始化动力学模型 ---
        State_Init baseState;
        baseState.posiNInit = this->get_parameter("initial_state.north").as_double();  // 北向初始位置，m
        baseState.posiEInit = this->get_parameter("initial_state.east").as_double();   // 东向初始位置，m
        baseState.posiDInit = this->get_parameter("initial_state.down").as_double();   // 地向初始位置，m
        baseState.velInit   = this->get_parameter("initial_state.airspeed").as_double(); // 初始空速
        baseState.pitchInit = this->get_parameter("initial_state.pitch").as_double(), // 初始俯仰角，rad
        baseState.yawInit   = this->get_parameter("initial_state.yaw").as_double();   // 初始偏航角，rad
        baseState.rollInit  = this->get_parameter("initial_state.roll").as_double();  // 初始滚转角，rad
        InitState(baseState); // from BHDynamics.h

        // --- ROS 通信设置 ---
        odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", 10);
        gps_pub_ = this->create_publisher<sensor_msgs::msg::NavSatFix>("gps", 10);
        airspeed_pub_ = this->create_publisher<std_msgs::msg::Float64>("airspeed", 10);
        
        control_sub_ = this->create_subscription<sim_msgs::msg::FwControl>(
            "fw_control", 10, std::bind(&FwSimNode::control_callback, this, std::placeholders::_1));

        // death notice
        deathnotice_sub_ = this->create_subscription<sim_msgs::msg::DeathNotice>(
            "deathnotice", 10, std::bind(&FwSimNode::deathnotice_callback, this, std::placeholders::_1));

        // --- 定时器 ---
        double sim_rate = this->get_parameter("rate.simulation").as_double();
        auto node_base_interface = this->get_node_base_interface();
        auto node_timers_interface = this->get_node_timers_interface();
        auto clock = this->get_clock();
        simulation_timer_ = rclcpp::create_timer(
            node_base_interface,
            node_timers_interface,
            clock,
            rclcpp::Duration::from_seconds(1.0 / sim_rate),
            std::bind(&FwSimNode::simulationLoop, this)
        );

        RCLCPP_INFO(this->get_logger(), "Fixed-wing %s simulator node started.", this->get_namespace());

        std::this_thread::sleep_for(std::chrono::seconds(8)); // 启动延时 8 秒
    }

private:
    // --- 回调函数 ---
    void control_callback(const sim_msgs::msg::FwControl::SharedPtr msg)
    {
        std::lock_guard<std::mutex> lock(control_mutex_);
        last_control_cmd_ = *msg;
    }

    void deathnotice_callback(const sim_msgs::msg::DeathNotice::SharedPtr msg)
    {
        RCLCPP_WARN(this->get_logger(), "UAV %s: FwSimNode shutting down.", this->get_namespace());
        simulation_timer_->cancel();  // 停止主循环
        control_sub_.reset();
        deathnotice_sub_.reset();
        rclcpp::shutdown();           // 请求 ROS 关闭本节点
    }

    // --- 主仿真循环 ---
    void simulationLoop()
    {
        // 1. 更新内环控制器
        updateControls();

        // 2. 发布传感器数据
        publishMessages();
    }

    void updateControls()
    {
        sim_msgs::msg::FwControl ctrl_cmd;
        {
            std::lock_guard<std::mutex> lock(control_mutex_);
            ctrl_cmd = last_control_cmd_;
        }

        if (ctrl_cmd.desired_pitch == 0.0 && ctrl_cmd.desired_high != 0.0) { 
            /* formation mode */ // ODE integrate for one step (25ms);
            dynamic_state_ = OutLoopCtrl_1(ctrl_cmd.desired_high, ctrl_cmd.desired_vel, ctrl_cmd.desired_roll * 180.0 / M_PI);
        }
        else if (ctrl_cmd.desired_pitch != 999.0 && ctrl_cmd.desired_high == 0.0) { 
            /* guidance mode */ // ODE integrate for one step (25ms)
            dynamic_state_ = OutLoopCtrl_3(ctrl_cmd.desired_pitch * 180.0 / M_PI, ctrl_cmd.desired_vel, ctrl_cmd.desired_roll * 180.0 / M_PI);
        }
        else if (ctrl_cmd.desired_pitch == 999.0 && ctrl_cmd.desired_high == 0.0) {
            // RCLCPP_INFO(this->get_logger(), "[fw_sim_node] Waiting for inputs");
        }
        else if (ctrl_cmd.desired_pitch != 0.0 && ctrl_cmd.desired_high != 0.0) {
            RCLCPP_INFO(this->get_logger(), "[fw_sim_node] Invalid inputs! Pitch and Height inputs" 
                                    " can not be nonzeros at the same time!");
        }
    }
    
    void publishMessages()
    {
        /* get states (NED/FRD -> ENU/FLU)*/
        double pos_x   = dynamic_state_.posiNState; // north (m)
        double pos_y   = dynamic_state_.posiEState; // east  (m)
        double pos_z   = dynamic_state_.posiDState; // down  (m)
        double angle_x = dynamic_state_.rollState;  // roll  (Forward)(rad)
        double angle_y = dynamic_state_.pitchState; // pitch (Right)(rad)
        double angle_z = dynamic_state_.yawState;   // yaw   (Down)(rad)
        double vel_ground = dynamic_state_.velState;
        double vel_alpha  = dynamic_state_.velalphaState * M_PI / 180.0; // 速度倾角(rad)
        double vel_beta   = dynamic_state_.velbeteState  * M_PI / 180.0; // 速度偏角(rad)
        // double angle_alpha = dynamic_state_.alphaState; // 攻角，输出暂为0
        // double angle_beta = dynamic_state_.beteState; // 侧滑角，输出暂为0
        
        /* TODO: vel is corresponding to the vel_alpha and vel_beta, not body attitude */
        double vel_x = vel_ground * cos(-vel_alpha) * cos(vel_beta); // north (m/s)
        double vel_y = vel_ground * cos(-vel_alpha) * sin(vel_beta); // east  (m/s)
        double vel_z = vel_ground * sin(-vel_alpha);                 // down  (m/s)

        rclcpp::Time now = this->get_clock()->now();
        
        // --- Odometry ---
        nav_msgs::msg::Odometry odom_msg;
        odom_msg.header.stamp = now;
        odom_msg.header.frame_id = "odom"; // or "world"
        odom_msg.child_frame_id = "base_link";

        odom_msg.pose.pose.position.x = pos_y;  // East (m)
        odom_msg.pose.pose.position.y = pos_x;  // North (m)
        odom_msg.pose.pose.position.z = -pos_z; // Up (m)

        // Eigen::Quaterniond q = fw_dynamics_.getQuaternion();
        // odom_msg.pose.pose.orientation.x = q.x();
        // odom_msg.pose.pose.orientation.y = q.y();
        // odom_msg.pose.pose.orientation.z = q.z();
        // odom_msg.pose.pose.orientation.w = q.w();

        tf2::Quaternion quaternion;
        double roll_f_rad = angle_x;
        double pitch_l_rad = -angle_y;
        double yaw_u_rad = -angle_z + M_PI_2;   // FLU
        quaternion.setRPY(roll_f_rad, pitch_l_rad, yaw_u_rad);
        odom_msg.pose.pose.orientation = tf2::toMsg(quaternion);

        odom_msg.twist.twist.linear.x = vel_y;
        odom_msg.twist.twist.linear.y = vel_x;
        odom_msg.twist.twist.linear.z = -vel_z;

        // Eigen::Vector3d omega_body = fw_dynamics_.getAngularVelocity();
        // odom_msg.twist.twist.angular.x = omega_body.x();
        // odom_msg.twist.twist.angular.y = omega_body.y();
        // odom_msg.twist.twist.angular.z = omega_body.z();
        
        odom_pub_->publish(odom_msg);

        // --- GPS ---
        sensor_msgs::msg::NavSatFix gps_msg;
        gps_msg.header = odom_msg.header;
        gps_msg.status.status = sensor_msgs::msg::NavSatStatus::STATUS_FIX;
        gps_msg.status.service = sensor_msgs::msg::NavSatStatus::SERVICE_GPS;
        
        // 简单的NED到LLA转换
        double lat0 = this->get_parameter("gps_origin.latitude").as_double() * M_PI / 180.0;
        double lon0 = this->get_parameter("gps_origin.longitude").as_double() * M_PI / 180.0;
        double alt0 = this->get_parameter("gps_origin.altitude").as_double();
        double R_earth = 6378137.0; // WGS-84 地球半径

        gps_msg.latitude = (pos_x / R_earth + lat0) * 180.0 / M_PI;
        gps_msg.longitude = (pos_y / (R_earth * cos(lat0)) + lon0) * 180.0 / M_PI;
        gps_msg.altitude = alt0 - pos_z;

        gps_pub_->publish(gps_msg);

        // --- Airspeed ---
        std_msgs::msg::Float64 airspeed_msg;
        airspeed_msg.data = vel_ground;
        airspeed_pub_->publish(airspeed_msg);
    }

    // --- 成员变量 ---
    State_Output dynamic_state_;
    sim_msgs::msg::FwControl last_control_cmd_;
    std::mutex control_mutex_;

    // ROS
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr gps_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr airspeed_pub_;
    rclcpp::Subscription<sim_msgs::msg::FwControl>::SharedPtr control_sub_;
    rclcpp::Subscription<sim_msgs::msg::DeathNotice>::SharedPtr deathnotice_sub_;
    rclcpp::TimerBase::SharedPtr simulation_timer_;
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FwSimNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}