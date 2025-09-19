#include <thread>   // <-- 添加这一行
#include <chrono>   // <-- 添加这一行
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <std_msgs/msg/float64.hpp>

#include "fwp_simulator/fw_dynamics.hpp"
#include "sim_msgs/msg/fw_control.hpp"
#include "sim_msgs/msg/death_notice.hpp"

// 一个简单的PID控制器实现
class PIDController {
public:
    PIDController(double kp, double ki, double kd) : kp_(kp), ki_(ki), kd_(kd), integral_(0), prev_error_(0) {}

    double calculate(double setpoint, double current_value, double dt) {
        double error = setpoint - current_value;
        integral_ += error * dt;
        double derivative = (error - prev_error_) / dt;
        prev_error_ = error;
        return kp_ * error + ki_ * integral_ + kd_ * derivative;
    }

private:
    double kp_, ki_, kd_;
    double integral_, prev_error_;
};



class FwSimNode : public rclcpp::Node
{
public:
    FwSimNode() : Node("fw_sim_node"),
        // 初始化内环PID控制器 (这些增益需要根据飞机模型进行调整)
        roll_controller_(0.1, 0.1, 0.02),
        pitch_controller_(0.9, 0.2, 0.05),
        yaw_rate_controller_(1.0, 0.0, 0.0),
        airspeed_controller_(0.8, 0.15, 0.0)
    {
        // --- 参数声明和获取 ---
        this->declare_parameter<double>("initial_state.north", 0.0);
        this->declare_parameter<double>("initial_state.east", 0.0);
        this->declare_parameter<double>("initial_state.down", -100.0); // 初始高度100m
        this->declare_parameter<double>("initial_state.roll", 0.0);
        this->declare_parameter<double>("initial_state.pitch", 0.0);
        this->declare_parameter<double>("initial_state.yaw", 0.0);
        this->declare_parameter<double>("initial_state.airspeed", 15.0); // 初始空速

        this->declare_parameter<double>("rate.simulation", 100.0); // 动力学仿真频率
        this->declare_parameter<double>("rate.odom", 50.0);        // Odometry 发布频率
        
        // GPS原点 (用于将NED坐标转换为纬经高)
        this->declare_parameter<double>("gps_origin.latitude", 47.397742);
        this->declare_parameter<double>("gps_origin.longitude", 8.545594);
        this->declare_parameter<double>("gps_origin.altitude", 488.0);


        // --- 初始化动力学模型 ---
        FwSimulator::FwDynamics::State init_state;
        init_state.pos << this->get_parameter("initial_state.north").as_double(),
                          this->get_parameter("initial_state.east").as_double(),
                          this->get_parameter("initial_state.down").as_double();
        
        double init_airspeed = this->get_parameter("initial_state.airspeed").as_double();
        init_state.vel << init_airspeed, 0.0, 0.0;
        
        fw_dynamics_.setState(init_state);
        fw_dynamics_.setAttitude(
            this->get_parameter("initial_state.roll").as_double(),
            this->get_parameter("initial_state.pitch").as_double(),
            this->get_parameter("initial_state.yaw").as_double()
        );

        // --- ROS 通信设置 ---
        odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", 10);
        imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>("imu", 10);
        gps_pub_ = this->create_publisher<sensor_msgs::msg::NavSatFix>("gps", 10);
        airspeed_pub_ = this->create_publisher<std_msgs::msg::Float64>("airspeed", 10);
        
        control_sub_ = this->create_subscription<sim_msgs::msg::FwControl>(
            "fw_control", 10, std::bind(&FwSimNode::control_callback, this, std::placeholders::_1));

        // death notice
        deathnotice_sub_ = this->create_subscription<sim_msgs::msg::DeathNotice>(
            "deathnotice", 10, std::bind(&FwSimNode::deathnotice_callback, this, std::placeholders::_1));

        // --- 定时器 ---
        double sim_rate = this->get_parameter("rate.simulation").as_double();
        simulation_dt_ = 1.0 / sim_rate;
        auto node_base_interface = this->get_node_base_interface();
        auto node_timers_interface = this->get_node_timers_interface();
        auto clock = this->get_clock();
        simulation_timer_ = rclcpp::create_timer(
            node_base_interface,
            node_timers_interface,
            clock,
            rclcpp::Duration::from_seconds(simulation_dt_),
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
        // 1. 更新内环控制器，计算舵面和油门
        updateControls();

        // 2. 运行一步动力学仿真
        double current_time = this->now().seconds();
        fw_dynamics_.step(current_time, current_time + simulation_dt_);

        // 3. 发布传感器数据
        publishMessages();
    }

    // --- 核心功能函数 ---
    void updateControls()
    {
        sim_msgs::msg::FwControl cmd;
        {
            std::lock_guard<std::mutex> lock(control_mutex_);
            cmd = last_control_cmd_;
        }

        auto current_state = fw_dynamics_.getState();
        auto euler_angles = fw_dynamics_.getEulerAngles(); // (roll, pitch, yaw)
        double airspeed = fw_dynamics_.getAirspeed();

        // 内环控制器计算
        double aileron_out = roll_controller_.calculate(cmd.desired_roll, euler_angles.x(), simulation_dt_);
        double elevator_out = pitch_controller_.calculate(cmd.desired_pitch, -euler_angles.y(), simulation_dt_);
        
        // 偏航使用角速度控制，更符合固定翼特性
        double rudder_out = yaw_rate_controller_.calculate(cmd.desired_yaw_rate, -current_state.omega.z(), simulation_dt_); 
        
        double throttle_out = airspeed_controller_.calculate(cmd.desired_airspeed, airspeed, simulation_dt_);
        
        // 限制输出范围
        aileron_out = std::max(-1.0, std::min(1.0, aileron_out));
        elevator_out = std::max(-1.0, std::min(1.0, elevator_out));
        rudder_out = std::max(-1.0, std::min(1.0, rudder_out));
        throttle_out = std::max(0.0, std::min(1.0, throttle_out));

        // 将归一化的控制量转换为舵偏角和油门值
        const double MAX_DEFLECTION_RAD = 25.0 * M_PI / 180.0; // 假设最大舵偏角为25度
        FwSimulator::FwDynamics::Input sim_input;
        sim_input.aileron = aileron_out * MAX_DEFLECTION_RAD;
        sim_input.elevator = elevator_out * MAX_DEFLECTION_RAD;
        sim_input.rudder = rudder_out * MAX_DEFLECTION_RAD;
        sim_input.throttle = throttle_out;

        fw_dynamics_.setInput(sim_input);
    }
    
    void publishMessages()
    {
        rclcpp::Time now = this->get_clock()->now();
        
        // --- Odometry ---
        nav_msgs::msg::Odometry odom_msg;
        odom_msg.header.stamp = now;
        odom_msg.header.frame_id = "odom"; // or "world"
        odom_msg.child_frame_id = "base_link";

        Eigen::Vector3d pos_ned = fw_dynamics_.getPosition();
        odom_msg.pose.pose.position.x = pos_ned.x(); // North
        odom_msg.pose.pose.position.y = pos_ned.y(); // East
        odom_msg.pose.pose.position.z = pos_ned.z(); // Down

        Eigen::Quaterniond q = fw_dynamics_.getQuaternion();
        odom_msg.pose.pose.orientation.x = q.x();
        odom_msg.pose.pose.orientation.y = q.y();
        odom_msg.pose.pose.orientation.z = q.z();
        odom_msg.pose.pose.orientation.w = q.w();

        Eigen::Vector3d vel_ned = fw_dynamics_.getVelocityNED();
        odom_msg.twist.twist.linear.x = vel_ned.x();
        odom_msg.twist.twist.linear.y = vel_ned.y();
        odom_msg.twist.twist.linear.z = vel_ned.z();

        Eigen::Vector3d omega_body = fw_dynamics_.getAngularVelocity();
        odom_msg.twist.twist.angular.x = omega_body.x();
        odom_msg.twist.twist.angular.y = omega_body.y();
        odom_msg.twist.twist.angular.z = omega_body.z();
        
        odom_pub_->publish(odom_msg);

        // --- IMU ---
        sensor_msgs::msg::Imu imu_msg;
        imu_msg.header = odom_msg.header;
        imu_msg.orientation = odom_msg.pose.pose.orientation;
        imu_msg.angular_velocity = odom_msg.twist.twist.angular;
        
        Eigen::Vector3d acc_ned = fw_dynamics_.getAccelerationNED();
        imu_msg.linear_acceleration.x = acc_ned.x();
        imu_msg.linear_acceleration.y = acc_ned.y();
        imu_msg.linear_acceleration.z = acc_ned.z();

        imu_pub_->publish(imu_msg);
        
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
        
        gps_msg.latitude = (pos_ned.x() / R_earth + lat0) * 180.0 / M_PI;
        gps_msg.longitude = (pos_ned.y() / (R_earth * cos(lat0)) + lon0) * 180.0 / M_PI;
        gps_msg.altitude = alt0 - pos_ned.z();

        gps_pub_->publish(gps_msg);

        // --- Airspeed ---
        std_msgs::msg::Float64 airspeed_msg;
        airspeed_msg.data = fw_dynamics_.getAirspeed();
        airspeed_pub_->publish(airspeed_msg);
    }

    // --- 成员变量 ---
    FwSimulator::FwDynamics fw_dynamics_;
    double simulation_dt_;
    sim_msgs::msg::FwControl last_control_cmd_;
    std::mutex control_mutex_;

    // PID 控制器
    PIDController roll_controller_;
    PIDController pitch_controller_;
    PIDController yaw_rate_controller_;
    PIDController airspeed_controller_;

    // ROS
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
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