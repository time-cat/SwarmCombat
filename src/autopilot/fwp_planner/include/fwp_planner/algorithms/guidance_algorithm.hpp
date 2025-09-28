#ifndef FWP_PLANNER__ALGORITHMS__GUIDANCE_ALGORITHM_HPP_
#define FWP_PLANNER__ALGORITHMS__GUIDANCE_ALGORITHM_HPP_

#include "fwp_planner/algorithms/base_algorithm.hpp"
#include <rclcpp/node.hpp>
#include <tf2/LinearMath/Vector3.h>

// --- Trajectory Representation ---
// 定义一个结构体来表示轨迹上的一个点，包含期望状态
struct TrajectoryPoint {
    tf2::Vector3 position;
    tf2::Vector3 velocity;
    tf2::Vector3 acceleration;
};

// --- Modern Guidance & Control Parameters ---
struct GuidanceParameters {
    // General Controller Parameters
    double trajectory_lookahead_time; // 控制器跟踪轨迹的前瞻时间
    double feedback_pos_gain;         // 位置误差反馈增益 (Kp)
    double feedback_vel_gain;         // 速度误差反馈增益 (Kd)
    
    // Red Team: Interception Planner
    double red_du_weight;          // 目标选择：距离UAV权重
    double red_dg_weight;          // 目标选择：距离GCS权重
    double red_count_weight;       // 目标选择：被锁定数量权重
    double red_prediction_time;       // 预测敌方位置的提前时间
    double red_apn_gain;              // 增广比例导引增益 (N')

    // Blue Team: Trajectory Optimization Planner
    double blue_replanning_horizon;   // 轨迹重新规划的时间域 (e.g., 5 seconds)
    double blue_repulsion_dist_enemy; // 避障斥力作用范围
    double blue_repulsion_coeff_enemy;// 避障斥力系数 (用于优化目标函数)
    double blue_smoothness_weight;    // 轨迹平滑度权重 (用于优化)
    double blue_goal_weight;          // 目标点权重 (用于优化)
    
    // Attitude Generation (Inner Loop abstraction)
    double pitch_gain;
    double roll_gain;
};


class GuidanceAlgorithm : public BaseAlgorithm
{
public:
    explicit GuidanceAlgorithm(rclcpp::Node* node);
    virtual ~GuidanceAlgorithm() = default;

    int select_target(
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredTeammateInfo>& known_teammates) override;

    bool decide_explode(
        int target_id,
        double exp_range,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies) override;

    sim_msgs::msg::FwControl calculate_motion(
        int target_id,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info) override;

private:

    int _find_best_target_weighted(
        const tf2::Vector3& self_pos,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredTeammateInfo>& known_teammates);

    // --- Planner Layer ---
    TrajectoryPoint _planner_red_team(
        int target_id,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies);

    TrajectoryPoint _planner_blue_team(
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies);

    // --- Controller Layer ---
    tf2::Vector3 _controller_track_trajectory(
        const fwp_planner::msg::DynamicState& self_state,
        const TrajectoryPoint& desired_point);

    // --- Helper & Utility Functions ---
    tf2::Vector3 _predict_target_position(
        const StoredEnemyInfo& target_info,
        const tf2::Vector3& self_pos);

    sim_msgs::msg::FwControl _generate_attitude_commands(
        const tf2::Vector3& desired_acceleration,
        const fwp_planner::msg::DynamicState& self_state);

    // Member Variables
    std::string team_;
    rclcpp::Node* node_;
    GuidanceParameters params_;
    tf2::Vector3 GCS_POSITION_;
    
    // State for velocity estimation and trajectory generation
    std::map<int, StoredEnemyInfo> last_enemy_info_;
    
    // Note: In a real implementation, a full trajectory (e.g., a B-spline object) 
    // would be stored here. For this example, we generate the target point on the fly.
};

#endif // FWP_PLANNER__ALGORITHMS__GUIDANCE_ALGORITHM_HPP_
