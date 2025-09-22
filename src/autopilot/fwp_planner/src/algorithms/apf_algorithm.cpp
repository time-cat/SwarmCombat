#include "fwp_planner/algorithms/apf_algorithm.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <cmath>

#include "fwp_planner/types.hpp"  // 包含 FwLogicNode 中的数据结构定义

namespace { // 匿名命名空间，辅助函数仅在此文件可见
    
    // 辅助函数：计算两点间的2D距离
    double get_weighted_distance(const tf2::Vector3& p1, const tf2::Vector3& p2, double vertical_weight = 0.4) {
        double dx = p1.x() - p2.x();
        double dy = p1.y() - p2.y();
        double dz = p1.z() - p2.z();
        return std::sqrt(dx*dx + dy*dy + vertical_weight * dz*dz);
    }

    void declare_apf_parameters(rclcpp::Node* node) {
        // 使用 "apf." 作为命名空间，以避免与其他算法参数冲突
        node->declare_parameter<double>("apf.turn_rate_coeff", 1.0);
        node->declare_parameter<double>("apf.prediction_time_factor", 1.5);
        // Red team
        node->declare_parameter<double>("apf.red.du_weight", 1.0);
        node->declare_parameter<double>("apf.red.dg_weight", 0.5);
        node->declare_parameter<double>("apf.red.count_weight", 500.0);
        node->declare_parameter<double>("apf.red.attraction_coeff_target", 1.0);
        node->declare_parameter<double>("apf.red.repulsion_dist_teammate", 150.0);
        node->declare_parameter<double>("apf.red.repulsion_coeff_teammate", 0.5);
        node->declare_parameter<double>("apf.red.attraction_coeff_formation", 0.2);
        // Blue team
        node->declare_parameter<double>("apf.blue.attack_distance", 200.0);
        node->declare_parameter<double>("apf.blue.evade_distance", 300.0);
        node->declare_parameter<double>("apf.blue.attraction_coeff_gcs", 1.0);
        node->declare_parameter<double>("apf.blue.repulsion_dist_enemy", 500.0);
        node->declare_parameter<double>("apf.blue.repulsion_coeff_enemy", 1.2);
    }

    ApfParameters load_apf_parameters(rclcpp::Node* node) {
        ApfParameters p;
        node->get_parameter("apf.turn_rate_coeff", p.turn_rate_coeff);
        node->get_parameter("apf.prediction_time_factor", p.prediction_time_factor);
        // Red team
        node->get_parameter("apf.red.du_weight", p.red_du_weight);
        node->get_parameter("apf.red.dg_weight", p.red_dg_weight);
        node->get_parameter("apf.red.count_weight", p.red_count_weight);
        node->get_parameter("apf.red.attraction_coeff_target", p.red_attraction_coeff_target);
        node->get_parameter("apf.red.repulsion_dist_teammate", p.red_repulsion_dist_teammate);
        node->get_parameter("apf.red.repulsion_coeff_teammate", p.red_repulsion_coeff_teammate);
        node->get_parameter("apf.red.attraction_coeff_formation", p.red_attraction_coeff_formation);
        // Blue team
        node->get_parameter("apf.blue.attack_distance", p.blue_attack_distance);
        node->get_parameter("apf.blue.evade_distance", p.blue_evade_distance);
        node->get_parameter("apf.blue.attraction_coeff_gcs", p.blue_attraction_coeff_gcs);
        node->get_parameter("apf.blue.repulsion_dist_enemy", p.blue_repulsion_dist_enemy);
        node->get_parameter("apf.blue.repulsion_coeff_enemy", p.blue_repulsion_coeff_enemy);
        return p;
    }

}

// === 构造函数实现 ===
ApfAlgorithm::ApfAlgorithm(rclcpp::Node* node) : node_(node)
{
    // 1. 从宿主节点获取基本信息
    this->team_ = node_->get_parameter("team").as_string();
    
    // 2. 声明并加载自己的参数
    declare_apf_parameters(node_);
    this->params_ = load_apf_parameters(node_);

    GCS_POSITION_ = tf2::Vector3(0.0, 0.0, 0.0);
    
    RCLCPP_INFO(node_->get_logger(), "APF Algorithm initialized for team '%s'", team_.c_str());
    RCLCPP_INFO(node_->get_logger(), "APF param 'turn_rate_coeff' is: %.2f", params_.turn_rate_coeff);
}

int ApfAlgorithm::select_target(
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies,
    const std::map<int, StoredTeammateInfo>& known_teammates)
{
    if (team_ == "blue") {
        // 蓝队目标是突防，目标始终是GCS，这里返回0或-1均可，具体逻辑在calculate_motion中
        return 0;
    } else if (team_ == "red") {
        // 红队拦截策略：总是锁定火力分配最优的敌人
        tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
        return _find_best_target_weighted(self_pos, known_enemies, known_teammates);
    }
    return -1; // 默认无目标
}

bool ApfAlgorithm::decide_explode(
    int target_id,
    double exp_range,
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies)
{
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
    if (team_ == "blue") {
        double dist_to_gcs = get_weighted_distance(self_pos, GCS_POSITION_, 1.0);
        RCLCPP_INFO(node_->get_logger(), "dist_to_gcs is team %.2f", dist_to_gcs);
        if (dist_to_gcs < exp_range) {
            return true;
        }
        return false;
    } else {
        if (target_id != -1 && known_enemies.count(target_id)) {
            const auto& target = known_enemies.at(target_id);
            tf2::Vector3 target_pos(target.position.x, target.position.y, target.position.z);
            double dist_to_target = get_weighted_distance(self_pos, target_pos, 1.0);
            if (dist_to_target < exp_range) {
                return true;
            }
        }
        return false;
    }
}

sim_msgs::msg::FwControl ApfAlgorithm::calculate_motion(
    int target_id,
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies,
    const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info)
{
    tf2::Vector3 total_force(0.0, 0.0, 0.0);

    if (team_ == "blue") {
        total_force = _calculate_blue_force(self_state, known_enemies);
    } else if (team_ == "red") {
        total_force = _calculate_red_force(target_id, self_state, known_enemies, known_teammates_dynamic_info);
    }

    sim_msgs::msg::FwControl cmd;
    cmd.desired_airspeed = 25.0; // 设置一个基准速度
    cmd.desired_roll = 0.0;
    cmd.desired_pitch = 0.0;
    
    // --- 通用部分：将合力转换为期望偏航角速度 ---
    double force_magnitude_2d = total_force.length();
    if (force_magnitude_2d < 1e-6) {
        cmd.desired_yaw_rate = 0.0;
        return cmd;
    }

    // 从四元数获取当前偏航角
    tf2::Quaternion q(self_state.orient_x, self_state.orient_y, self_state.orient_z, self_state.orient_w);
    double roll, pitch, yaw;
    tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);

    // 计算期望航向 (只考虑XY平面)
    double desired_heading = std::atan2(total_force.y(), total_force.x());
    
    // 计算角度误差 ([-PI, PI])
    double angle_error = std::atan2(std::sin(desired_heading - yaw), std::cos(desired_heading - yaw));

    // P控制器计算期望角速度
    cmd.desired_yaw_rate = params_.turn_rate_coeff * angle_error;

    // 根据朝向调整速度（简单逻辑）
    tf2::Vector3 heading_vector(std::cos(yaw), std::sin(yaw), 0);
    tf2::Vector3 force_direction_vector = total_force.normalized();
    double alignment = heading_vector.dot(force_direction_vector);

    // 仅当大致对准方向时才加速
    if (alignment > 0.5) { // cos(60deg) = 0.5
        cmd.desired_airspeed = 35.0; // 最大速度
    }

    // 记录本帧敌方信息，用于下一帧预测
    last_enemy_info_ = known_enemies;
    // 注意：需要一个可靠的时间源来计算dt，这里简化处理
    
    return cmd;
}


int ApfAlgorithm::_find_best_target_weighted(
    const tf2::Vector3& self_pos,
    const std::map<int, StoredEnemyInfo>& known_enemies,
    const std::map<int, StoredTeammateInfo>& known_teammates)
{
    if (known_enemies.empty()) {
        return -1;
    }

    std::map<int, int> target_counts;
    for (const auto& pair : known_teammates) {
        int tid = pair.second.target_id;
        if (tid != -1) {
            target_counts[tid]++;
        }
    }

    int best_target_id = -1;
    double min_score = std::numeric_limits<double>::max();

    for (const auto& pair : known_enemies) {
        int enemy_id = pair.first;
        tf2::Vector3 enemy_pos(pair.second.position.x, pair.second.position.y, pair.second.position.z);
        
        double dist_to_uav = get_weighted_distance(self_pos, enemy_pos);
        double dist_to_gcs = get_weighted_distance(GCS_POSITION_, enemy_pos);
        int count = target_counts.count(enemy_id) ? target_counts.at(enemy_id) : 0;

        double score = dist_to_uav * params_.red_du_weight + 
                       dist_to_gcs * params_.red_dg_weight + 
                       count * params_.red_count_weight;
        
        if (score < min_score) {
            min_score = score;
            best_target_id = enemy_id;
        }
    }
    return best_target_id;
}


tf2::Vector3 ApfAlgorithm::_calculate_red_force(
    int target_id,
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies,
    const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info)
{
    tf2::Vector3 total_force(0, 0, 0);
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);

    // 1. 目标引力 (带预测)
    if (target_id != -1 && known_enemies.count(target_id)) {
        const auto& target_info = known_enemies.at(target_id);
        tf2::Vector3 current_target_pos(target_info.position.x, target_info.position.y, target_info.position.z);
        tf2::Vector3 attraction_point = current_target_pos;

        if (last_enemy_info_.count(target_id)) {
            const auto& last_target_info = last_enemy_info_.at(target_id);
            tf2::Vector3 last_target_pos(last_target_info.position.x, last_target_info.position.y, last_target_info.position.z);
            
            // 假设一个固定的时间间隔 dt (例如 1/20 Hz = 0.05s)
            double dt = 0.05; 
            tf2::Vector3 estimated_velocity = (current_target_pos - last_target_pos) / dt;
            attraction_point = current_target_pos + estimated_velocity * params_.prediction_time_factor;
        }

        tf2::Vector3 vec_to_target = attraction_point - self_pos;
        if (vec_to_target.length() > 0) {
            total_force += params_.red_attraction_coeff_target * vec_to_target.normalized();
        }
    }

    // 2. 队友交互力 (斥力/凝聚力)
    total_force += _calculate_teammate_forces(self_pos, known_teammates_dynamic_info);

    return total_force;
}


tf2::Vector3 ApfAlgorithm::_calculate_blue_force(
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies)
{
    tf2::Vector3 total_force(0, 0, 0);
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
    
    // 1. --- 确定当前战术状态 ---
    std::string current_state = "CRUISE";
    double dist_to_gcs = get_weighted_distance(self_pos, GCS_POSITION_);

    if (dist_to_gcs < params_.blue_attack_distance) {
        current_state = "ATTACK";
    } else {
        double min_dist_to_enemy = std::numeric_limits<double>::max();
        for (const auto& pair : known_enemies) {
            tf2::Vector3 enemy_pos(pair.second.position.x, pair.second.position.y, pair.second.position.z);
            min_dist_to_enemy = std::min(min_dist_to_enemy, get_weighted_distance(self_pos, enemy_pos));
        }
        if (min_dist_to_enemy < params_.blue_evade_distance) {
            current_state = "EVADE";
        }
    }
    
    // 2. --- 根据状态计算合力 ---
    if (current_state == "ATTACK") {
        tf2::Vector3 vec_gcs = GCS_POSITION_ - self_pos;
        if (vec_gcs.length() > 0) {
            total_force += params_.blue_attraction_coeff_gcs * vec_gcs.normalized();
        }
    } else if (current_state == "EVADE") {
        total_force += _calculate_enemy_repulsion(self_pos, known_enemies);
    } else { // CRUISE
        // GCS引力
        tf2::Vector3 vec_gcs = GCS_POSITION_ - self_pos;
        if (vec_gcs.length() > 0) {
            total_force += params_.blue_attraction_coeff_gcs * vec_gcs.normalized();
        }
        // 敌人斥力
        total_force += _calculate_enemy_repulsion(self_pos, known_enemies);
    }

    return total_force;
}

tf2::Vector3 ApfAlgorithm::_calculate_teammate_forces(
    const tf2::Vector3& self_pos,
    const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info)
{
    tf2::Vector3 force(0, 0, 0);
    const double rep_dist = params_.red_repulsion_dist_teammate;
    const double rep_coeff = params_.red_repulsion_coeff_teammate;

    for (const auto& pair : known_teammates_dynamic_info) {
        tf2::Vector3 mate_pos(
            pair.second.dynamic_state.posi_n,
            pair.second.dynamic_state.posi_e,
            pair.second.dynamic_state.posi_d);
        
        tf2::Vector3 vec = self_pos - mate_pos;
        double dist = vec.length();

        if (dist > 0 && dist < rep_dist) {
            force += rep_coeff * (vec / (dist * dist * dist));
        }
    }
    // 凝聚力逻辑可以后续添加
    return force;
}

tf2::Vector3 ApfAlgorithm::_calculate_enemy_repulsion(
    const tf2::Vector3& self_pos,
    const std::map<int, StoredEnemyInfo>& known_enemies)
{
    tf2::Vector3 force_rep_enemy(0, 0, 0);
    const double rep_dist = params_.blue_repulsion_dist_enemy;
    const double rep_coeff = params_.blue_repulsion_coeff_enemy;

    for (const auto& pair : known_enemies) {
        tf2::Vector3 enemy_pos(pair.second.position.x, pair.second.position.y, pair.second.position.z);
        tf2::Vector3 vec = self_pos - enemy_pos;
        double dist = vec.length();

        if (dist > 0 && dist < rep_dist) {
            force_rep_enemy += rep_coeff * (1.0/dist - 1.0/rep_dist) * (vec / (dist*dist*dist));
        }
    }
    return force_rep_enemy;
}

