#ifndef FWP_PLANNER__ALGORITHMS__APF_ALGORITHM_HPP_
#define FWP_PLANNER__ALGORITHMS__APF_ALGORITHM_HPP_

#include "fwp_planner/algorithms/base_algorithm.hpp"
#include <rclcpp/rclcpp.hpp>
#include <tf2/LinearMath/Vector3.h>
#include <string>

// APF算法的所有可配置参数
struct ApfParameters {
    // 通用参数
    double turn_rate_coeff;
    double prediction_time_factor; // 红队预测提前量

    // 红队参数
    double red_du_weight;          // 目标选择：距离UAV权重
    double red_dg_weight;          // 目标选择：距离GCS权重
    double red_count_weight;       // 目标选择：被锁定数量权重
    double red_attraction_coeff_target;
    double red_repulsion_dist_teammate;
    double red_repulsion_coeff_teammate;
    double red_attraction_coeff_formation;

    // 蓝队参数
    double blue_attack_distance;
    double blue_evade_distance;
    double blue_attraction_coeff_gcs;
    double blue_repulsion_dist_enemy;
    double blue_repulsion_coeff_enemy;
};


class ApfAlgorithm : public BaseAlgorithm
{
public:
    explicit ApfAlgorithm(rclcpp::Node* node);
    // ApfAlgorithm(const std::string& team, const ApfParameters& params, rclcpp::Logger logger);
    virtual ~ApfAlgorithm() = default;

    int select_target(
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredTeammateInfo>& known_teammates) override;

    sim_msgs::msg::FwControl calculate_motion(
        int target_id,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info) override;

    bool decide_explode(
        int target_id,
        double exp_range,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies) override;

private:
    // 辅助函数
    int _find_best_target_weighted(
        const tf2::Vector3& self_pos,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredTeammateInfo>& known_teammates);

    tf2::Vector3 _calculate_red_force(
        int target_id,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info);

    tf2::Vector3 _calculate_blue_force(
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies);

    tf2::Vector3 _calculate_teammate_forces(
        const tf2::Vector3& self_pos,
        const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info);
    
    tf2::Vector3 _calculate_enemy_repulsion(
        const tf2::Vector3& self_pos,
        const std::map<int, StoredEnemyInfo>& known_enemies);

    // 成员变量
    std::string team_;
    ApfParameters params_;
    rclcpp::Node* node_;
    // rclcpp::Logger logger_;

    tf2::Vector3 GCS_POSITION_;

    // 用于计算敌方速度
    std::map<int, StoredEnemyInfo> last_enemy_info_;
    rclcpp::Time last_update_time_;
};

#endif // FWP_PLANNER__ALGORITHMS__APF_ALGORITHM_HPP_