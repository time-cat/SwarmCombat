/**
 * @file gcs_visualizer_node.cpp
 * @author Tong
 * @brief ROS 2 node to visualize a Ground Control Station (GCS) in RViz.
 *        It publishes a static TF for the GCS's position and uses Markers
 *        to display its detection and communication ranges as transparent hemispheres.
 *        The node listens for a DeathNotice to clean up visualizations and shut down.
 * @version 1.0
 * @date 2025-09-19
 *
 * @license BSD 3-Clause License
 * @copyright (c) 2025, Your Name/Organization
 * All rights reserved.
 *
 */

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <cmath>

#include <visualization_msgs/msg/marker.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point.hpp>

#include "sim_msgs/msg/death_notice.hpp"

class GcsVisualizerNode : public rclcpp::Node
{
public:
    GcsVisualizerNode() : Node("gcs_visualizer_node")
    {
        // --- 1. 声明并获取参数 ---
        this->declare_parameter<std::string>("team", "red");
        this->declare_parameter<double>("position.x", 0.0);
        this->declare_parameter<double>("position.y", 0.0);
        this->declare_parameter<double>("position.z", 0.0);
        this->declare_parameter<double>("fov_range", 10000.0);
        this->declare_parameter<double>("com_range", 12000.0);
        this->declare_parameter<double>("alpha", 0.3);
        this->declare_parameter<std::string>("tf_frame", "odom");
        this->declare_parameter<std::string>("base_link_frame", "gcs/base_link");
        this->declare_parameter<double>("visualization_frequency", 3.0); // 较低频率，因为是静态的

        team_ = this->get_parameter("team").as_string();
        fov_range_ = this->get_parameter("fov_range").as_double();
        com_range_ = this->get_parameter("com_range").as_double();
        alpha_ = this->get_parameter("alpha").as_double();
        tf_frame_ = this->get_parameter("tf_frame").as_string();
        base_link_frame_ = this->get_parameter("base_link_frame").as_string();
        double pub_freq = this->get_parameter("visualization_frequency").as_double();
        
        // 获取GCS在NED坐标系下的位置
        geometry_msgs::msg::Pose pose_ned;
        pose_ned.position.x = this->get_parameter("position.x").as_double(); // North
        pose_ned.position.y = this->get_parameter("position.y").as_double(); // East
        pose_ned.position.z = this->get_parameter("position.z").as_double(); // Down
        pose_ned.orientation.w = 1.0; // 默认姿态

        // --- 2. 初始化静态TF变换 ---
        // GCS位置固定，所以我们只需要计算一次从NED到ENU的变换
        transform_pose_ned_to_enu(pose_ned, pose_enu_);
        // 初始化TF广播器
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

        // --- 3. 初始化ROS通信 ---
        marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("gcs_ranges_marker", 10);
        deathnotice_sub_ = this->create_subscription<sim_msgs::msg::DeathNotice>(
            "deathnotice", 10, std::bind(&GcsVisualizerNode::deathnotice_callback, this, std::placeholders::_1));

        // --- 4. 设置主循环定时器 ---
        // --- 定时器 ---
        auto node_base_interface = this->get_node_base_interface();
        auto node_timers_interface = this->get_node_timers_interface();
        auto clock = this->get_clock();
        visualize_timer_ = rclcpp::create_timer(
            node_base_interface,
            node_timers_interface,
            clock,
            rclcpp::Duration::from_seconds(1.0 / pub_freq),
            std::bind(&GcsVisualizerNode::visualizeLoop, this)
        );

        RCLCPP_INFO(this->get_logger(), "GCS visualizer node has started for team '%s'.", team_.c_str());
    }

private:
    /**
     * @brief Transforms a pose from NED (simulation) to ENU (ROS/RViz) coordinates.
     * @param pose_ned The input pose in North-East-Down frame.
     * @param pose_enu The output pose in East-North-Up frame.
     */
    void transform_pose_ned_to_enu(const geometry_msgs::msg::Pose& pose_ned, geometry_msgs::msg::Pose& pose_enu)
    {
        // 位置变换: NED -> ENU
        // ROS_X (East)  = Sim_Y (East)
        // ROS_Y (North) = Sim_X (North)
        // ROS_Z (Up)    = -Sim_Z (Down)
        pose_enu.position.x = pose_ned.position.y;
        pose_enu.position.y = pose_ned.position.x;
        pose_enu.position.z = -pose_ned.position.z;

        // 对于地面站，我们假设其模型本身是正的，不需要进行姿态旋转
        pose_enu.orientation.w = 1.0;
        pose_enu.orientation.x = 0.0;
        pose_enu.orientation.y = 0.0;
        pose_enu.orientation.z = 0.0;
    }

    void deathnotice_callback(const sim_msgs::msg::DeathNotice::SharedPtr msg)
    {
        if(msg->death)
        {
            RCLCPP_WARN(this->get_logger(), "Visualizer for GCS received death notice. Cleaning up RViz.");

            // 1. 停止定时器
            visualize_timer_->cancel();

            // 2. 清理RViz中的可视化元素
            cleanup_markers();
            
            // 3. 释放资源并关闭节点
            deathnotice_sub_.reset();
            marker_pub_.reset();
            tf_broadcaster_.reset();

            RCLCPP_INFO(this->get_logger(), "Cleanup for GCS complete. Visualizer is shutting down.");
            rclcpp::shutdown();
        }
    }

    void visualizeLoop()
    {
        publish_static_tf();
        publish_range_marker(0, fov_range_, "det_range"); // ID 0 for detection
        publish_range_marker(1, com_range_, "com_range"); // ID 1 for communication
    }

    void publish_static_tf()
    {
        geometry_msgs::msg::TransformStamped t;
        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = tf_frame_;
        t.child_frame_id = base_link_frame_;
        t.transform.translation.x = pose_enu_.position.x;
        t.transform.translation.y = pose_enu_.position.y;
        t.transform.translation.z = pose_enu_.position.z;
        t.transform.rotation = pose_enu_.orientation;
        tf_broadcaster_->sendTransform(t);
    }

    void publish_range_marker(int id, double radius, const std::string& ns)
    {
        if (radius <= 0) return;

        visualization_msgs::msg::Marker marker;
        marker.header.frame_id = base_link_frame_;
        marker.header.stamp = this->get_clock()->now();
        marker.ns = ns;
        marker.id = id;
        // --- 核心改动 1: 将类型改为 TRIANGLE_LIST ---
        marker.type = visualization_msgs::msg::Marker::TRIANGLE_LIST;
        marker.action = visualization_msgs::msg::Marker::ADD;

        // 位置相对于frame中心 (0,0,0)
        marker.pose.position.x = 0;
        marker.pose.position.y = 0;
        marker.pose.position.z = 0; // 半球的基座位于z=0平面
        marker.pose.orientation.w = 1.0;

        // --- 核心改动 2: 对于TRIANGLE_LIST, scale应为1 ---
        // 因为形状的大小由点的坐标直接定义
        marker.scale.x = 1.0;
        marker.scale.y = 1.0;
        marker.scale.z = 1.0;

        // 根据队伍和类型设置颜色和透明度 (逻辑保持不变)
        if (team_ == "red") {
            marker.color.r = (ns == "det_range") ? 1.0f : 0.8f;
            marker.color.g = 0.0f;
            marker.color.b = 0.0f;
        } else { // blue team
            marker.color.r = 0.0f;
            marker.color.g = (ns == "det_range") ? 0.5f : 0.3f;
            marker.color.b = 1.0f;
        }
        marker.color.a = alpha_; // 设置透明度

        // --- 核心改动 3: 生成构成半球体表面的三角形网格 ---
        marker.points.clear();
        // resolution决定了半球的平滑度，值越高越平滑，但计算量越大
        int resolution = 48; 

        for (int i = 0; i < resolution / 2; ++i) { // 纬度方向 (从顶部到底部)
            double lat1 = M_PI * i / resolution;
            double lat2 = M_PI * (i + 1) / resolution;

            for (int j = 0; j < resolution; ++j) { // 经度方向 (环绕一周)
                double lon1 = 2 * M_PI * j / resolution;
                double lon2 = 2 * M_PI * (j + 1) / resolution;

                // 定义一个四边形的四个顶点
                geometry_msgs::msg::Point p1, p2, p3, p4;

                p1.x = radius * std::sin(lat1) * std::cos(lon1);
                p1.y = radius * std::sin(lat1) * std::sin(lon1);
                p1.z = radius * std::cos(lat1);

                p2.x = radius * std::sin(lat1) * std::cos(lon2);
                p2.y = radius * std::sin(lat1) * std::sin(lon2);
                p2.z = radius * std::cos(lat1);

                p3.x = radius * std::sin(lat2) * std::cos(lon2);
                p3.y = radius * std::sin(lat2) * std::sin(lon2);
                p3.z = radius * std::cos(lat2);
                
                p4.x = radius * std::sin(lat2) * std::cos(lon1);
                p4.y = radius * std::sin(lat2) * std::sin(lon1);
                p4.z = radius * std::cos(lat2);

                // 将这个四边形分割成两个三角形并添加到点列表中
                // 三角形 1
                marker.points.push_back(p1);
                marker.points.push_back(p2);
                marker.points.push_back(p4);
                // 三角形 2
                marker.points.push_back(p2);
                marker.points.push_back(p3);
                marker.points.push_back(p4);
            }
        }

        // 设置marker的生命周期
        marker.lifetime = rclcpp::Duration::from_seconds(0.6); 

        marker_pub_->publish(marker);
    }

    void cleanup_markers()
    {
        // 发布一个DELETE动作的Marker来清除探测范围
        visualization_msgs::msg::Marker delete_fov_marker;
        delete_fov_marker.header.frame_id = base_link_frame_;
        delete_fov_marker.header.stamp = this->get_clock()->now();
        delete_fov_marker.ns = "det_range";
        delete_fov_marker.id = 0;
        delete_fov_marker.action = visualization_msgs::msg::Marker::DELETE;
        marker_pub_->publish(delete_fov_marker);

        // 发布一个DELETE动作的Marker来清除通信范围
        visualization_msgs::msg::Marker delete_com_marker;
        delete_com_marker.header.frame_id = base_link_frame_;
        delete_com_marker.header.stamp = this->get_clock()->now();
        delete_com_marker.ns = "com_range";
        delete_com_marker.id = 1;
        delete_com_marker.action = visualization_msgs::msg::Marker::DELETE;
        marker_pub_->publish(delete_com_marker);
    }

    // ROS通信相关的成员
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
    rclcpp::Subscription<sim_msgs::msg::DeathNotice>::SharedPtr deathnotice_sub_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    rclcpp::TimerBase::SharedPtr visualize_timer_;

    // 参数存储
    std::string team_;
    double fov_range_;
    double com_range_;
    double alpha_;
    std::string tf_frame_;
    std::string base_link_frame_;

    // 状态存储
    geometry_msgs::msg::Pose pose_enu_; // 存储转换到ENU后的静态位姿
};

// --- Main函数 ---
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GcsVisualizerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}