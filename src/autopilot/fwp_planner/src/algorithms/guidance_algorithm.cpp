


#include "fwp_planner/algorithms/guidance_algorithm.hpp"
#include <rclcpp/rclcpp.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

namespace { // Anonymous namespace

    // 辅助函数：计算两点间的2D距离
    double get_weighted_distance(const tf2::Vector3& p1, const tf2::Vector3& p2, double vertical_weight = 0.4) {
        double dx = p1.x() - p2.x();
        double dy = p1.y() - p2.y();
        double dz = p1.z() - p2.z();
        return std::sqrt(dx*dx + dy*dy + vertical_weight * dz*dz);
    }

    void declare_guidance_parameters(rclcpp::Node* node) {
        // Controller
        node->declare_parameter<double>("guidance.trajectory_lookahead_time", 0.1); // Short lookahead for controller
        node->declare_parameter<double>("guidance.feedback_pos_gain", 4.0); // Kp for position error
        node->declare_parameter<double>("guidance.feedback_vel_gain", 3.0); // Kd for velocity error
        // Red Planner
        node->declare_parameter<double>("guidance.red_du_weight", 2.5);
        node->declare_parameter<double>("guidance.red_dg_weight", 4.0);
        node->declare_parameter<double>("guidance.red_count_weight", 2.5);
        node->declare_parameter<double>("guidance.red_prediction_time", 2.5);
        node->declare_parameter<double>("guidance.red_apn_gain", 4.0);
        // Blue Planner
        node->declare_parameter<double>("guidance.blue_replanning_horizon", 5.0);
        node->declare_parameter<double>("guidance.blue_repulsion_dist_enemy", 450.0);
        node->declare_parameter<double>("guidance.blue_repulsion_coeff_enemy", 2.0);
        node->declare_parameter<double>("guidance.blue_smoothness_weight", 0.5);
        node->declare_parameter<double>("guidance.blue_goal_weight", 1.5);
        // Attitude Generation
        node->declare_parameter<double>("guidance.pitch_gain", 2.5);
        node->declare_parameter<double>("guidance.roll_gain", 4.0);
    }

    GuidanceParameters load_guidance_parameters(rclcpp::Node* node) {
        GuidanceParameters p;
        node->get_parameter("guidance.trajectory_lookahead_time", p.trajectory_lookahead_time);
        node->get_parameter("guidance.feedback_pos_gain", p.feedback_pos_gain);
        node->get_parameter("guidance.feedback_vel_gain", p.feedback_vel_gain);
        node->get_parameter("guidance.red_du_weight", p.red_du_weight);
        node->get_parameter("guidance.red_dg_weight", p.red_dg_weight);
        node->get_parameter("guidance.red_count_weight", p.red_count_weight);
        node->get_parameter("guidance.red_prediction_time", p.red_prediction_time);
        node->get_parameter("guidance.red_apn_gain", p.red_apn_gain);
        node->get_parameter("guidance.blue_replanning_horizon", p.blue_replanning_horizon);
        node->get_parameter("guidance.blue_repulsion_dist_enemy", p.blue_repulsion_dist_enemy);
        node->get_parameter("guidance.blue_repulsion_coeff_enemy", p.blue_repulsion_coeff_enemy);
        node->get_parameter("guidance.blue_smoothness_weight", p.blue_smoothness_weight);
        node->get_parameter("guidance.blue_goal_weight", p.blue_goal_weight);
        node->get_parameter("guidance.pitch_gain", p.pitch_gain);
        node->get_parameter("guidance.roll_gain", p.roll_gain);
        return p;
    }

} // end anonymous namespace


GuidanceAlgorithm::GuidanceAlgorithm(rclcpp::Node* node) : node_(node)
{
    this->team_ = node_->get_parameter("team").as_string();
    declare_guidance_parameters(node_);
    this->params_ = load_guidance_parameters(node_);
    GCS_POSITION_ = tf2::Vector3(0.0, 0.0, 0.0); // Set GCS altitude
    RCLCPP_INFO(node_->get_logger(), "Modern Guidance/Control Algorithm initialized for team '%s'", team_.c_str());
}

// select_target and decide_explode remain unchanged as their logic is high-level.
int GuidanceAlgorithm::select_target(
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies,
    const std::map<int, StoredTeammateInfo>& known_teammates)
{
    if (team_ == "blue") return 0;
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
    return _find_best_target_weighted(self_pos, known_enemies, known_teammates);
}

bool GuidanceAlgorithm::decide_explode(
    int target_id, double exp_range,
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies)
{
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
    if (team_ == "blue") {
        return self_pos.distance(GCS_POSITION_) < exp_range;
    }
    if (target_id != -1 && known_enemies.count(target_id)) {
        const auto& target = known_enemies.at(target_id);
        tf2::Vector3 target_pos(target.position.x, target.position.y, target.position.z);
        return self_pos.distance(target_pos) < exp_range;
    }
    return false;
}

// Main logic loop: orchestrates planning and control
sim_msgs::msg::FwControl GuidanceAlgorithm::calculate_motion(
    int target_id,
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies,
    const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info)
{
    // --- 1. PLANNER LAYER ---
    // Generate a reference point on the desired trajectory for the controller to track.
    TrajectoryPoint desired_trajectory_point;
    if (team_ == "blue") {
        desired_trajectory_point = _planner_blue_team(self_state, known_enemies);
    } else { // red team
        desired_trajectory_point = _planner_red_team(target_id, self_state, known_enemies);
    }

    // --- 2. CONTROLLER LAYER ---
    // Calculate the required acceleration to track the trajectory point.
    tf2::Vector3 desired_acceleration = _controller_track_trajectory(self_state, desired_trajectory_point);

    // --- 3. COMMAND GENERATION ---
    // Convert acceleration vector into attitude and vel commands.
    sim_msgs::msg::FwControl cmd = _generate_attitude_commands(desired_acceleration, self_state);

    // Simple vel controller: fly faster when aligned with the acceleration command
    tf2::Quaternion current_attitude(self_state.orient_x, self_state.orient_y, self_state.orient_z, self_state.orient_w);
    tf2::Vector3 current_heading = tf2::quatRotate(current_attitude, tf2::Vector3(1, 0, 0));
    double alignment = current_heading.dot(desired_acceleration.normalized());
    const double min_vel = 25.0, max_vel = 40.0;
    cmd.desired_vel = min_vel + (max_vel - min_vel) * std::max(0.0, alignment);
    
    last_enemy_info_ = known_enemies;
    return cmd;
}

int GuidanceAlgorithm::_find_best_target_weighted(
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

// ==========================================================
// RED TEAM PLANNER: Generates an intercept trajectory point using APN.
// ==========================================================
TrajectoryPoint GuidanceAlgorithm::_planner_red_team(
    int target_id,
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies)
{
    TrajectoryPoint traj_pt;
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
    
    // Default to loitering if no valid target
    if (target_id == -1 || !known_enemies.count(target_id)) {
        traj_pt.position = self_pos + tf2::Vector3(100, 0, 0); // Fly straight
        traj_pt.velocity.setZero();
        traj_pt.acceleration.setZero();
        return traj_pt;
    }
    
    const auto& target_info = known_enemies.at(target_id);
    tf2::Vector3 target_pos(target_info.position.x, target_info.position.y, target_info.position.z);
    
    // Estimate target velocity
    tf2::Vector3 target_vel(0,0,0);
    if (last_enemy_info_.count(target_id)) {
        const auto& last_info = last_enemy_info_.at(target_id);
        double dt = (target_info.timestamp - last_info.timestamp).seconds();
        if (dt > 1e-3) {
            target_vel = (target_pos - tf2::Vector3(last_info.position.x, last_info.position.y, last_info.position.z)) / dt;
        }
    }
    
    // --- Augmented Proportional Navigation (APN) Logic ---
    tf2::Vector3 self_vel = tf2::quatRotate(
        {self_state.orient_x, self_state.orient_y, self_state.orient_z, self_state.orient_w},
        {self_state.vel, 0, 0}
    );

    tf2::Vector3 r_vec = target_pos - self_pos;
    tf2::Vector3 v_vec = target_vel - self_vel;
    
    // Line-of-Sight (LOS) vector and its rotation rate
    tf2::Vector3 los_unit = r_vec.normalized();
    tf2::Vector3 omega = los_unit.cross(v_vec) / r_vec.length();
    
    // Closing velocity
    double v_c = -r_vec.dot(v_vec) / r_vec.length();

    // APN acceleration command
    tf2::Vector3 accel_cmd_inertial = params_.red_apn_gain * v_c * (omega.cross(los_unit));

    // --- Generate Trajectory Point ---
    // The planner's output is the state on the trajectory a short time from now.
    // We can get this by integrating the current state with the calculated acceleration.
    double dt = params_.trajectory_lookahead_time;
    traj_pt.acceleration = accel_cmd_inertial;
    traj_pt.velocity = self_vel + traj_pt.acceleration * dt;
    traj_pt.position = self_pos + self_vel * dt + 0.5 * traj_pt.acceleration * dt * dt;

    return traj_pt;
}


// ==========================================================
// BLUE TEAM PLANNER: Generates a trajectory towards goal, avoiding enemies.
// (This is a simplified representation of a trajectory optimization)
// ==========================================================
TrajectoryPoint GuidanceAlgorithm::_planner_blue_team(
    const fwp_planner::msg::DynamicState& self_state,
    const std::map<int, StoredEnemyInfo>& known_enemies)
{
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
    
    // --- 1. Define Optimization "Forces" ---
    // Attractive force towards the goal (GCS)
    tf2::Vector3 goal_direction = (GCS_POSITION_ - self_pos).normalized();
    tf2::Vector3 goal_force = params_.blue_goal_weight * goal_direction;
    
    // Repulsive force from enemies
    tf2::Vector3 repulsion_force(0, 0, 0);
    for (const auto& pair : known_enemies) {
        tf2::Vector3 enemy_pos(pair.second.position.x, pair.second.position.y, pair.second.position.z);
        tf2::Vector3 vec_to_self = self_pos - enemy_pos;
        double dist = vec_to_self.length();

        if (dist > 0 && dist < params_.blue_repulsion_dist_enemy) {
            double repulsion_magnitude = params_.blue_repulsion_coeff_enemy * (1.0/dist - 1.0/params_.blue_repulsion_dist_enemy);
            repulsion_force += repulsion_magnitude * vec_to_self.normalized();
        }
    }
    
    // --- 2. Combine forces to get desired acceleration ---
    // Note: In a real B-spline/QP optimizer, these forces would be part of the cost function.
    // Here, we use them directly to compute a desired acceleration vector, which acts as
    // the core of our dynamically generated trajectory.
    tf2::Vector3 desired_accel = goal_force + repulsion_force;
    
    // --- 3. Generate Trajectory Point ---
    // As with the red planner, we integrate forward to find the point on the new trajectory.
    tf2::Vector3 self_vel = tf2::quatRotate(
        {self_state.orient_x, self_state.orient_y, self_state.orient_z, self_state.orient_w},
        {self_state.vel, 0, 0}
    );
    double dt = params_.trajectory_lookahead_time;
    TrajectoryPoint traj_pt;
    traj_pt.acceleration = desired_accel;
    traj_pt.velocity = self_vel + traj_pt.acceleration * dt;
    traj_pt.position = self_pos + self_vel * dt + 0.5 * traj_pt.acceleration * dt * dt;

    return traj_pt;
}


// ==========================================================
// CONTROLLER: Tracks the trajectory point using a PD feedback + feedforward law.
// ==========================================================
tf2::Vector3 GuidanceAlgorithm::_controller_track_trajectory(
    const fwp_planner::msg::DynamicState& self_state,
    const TrajectoryPoint& desired_point)
{
    // --- Current State ---
    tf2::Vector3 self_pos(self_state.posi_n, self_state.posi_e, self_state.posi_d);
    tf2::Vector3 self_vel = tf2::quatRotate(
        {self_state.orient_x, self_state.orient_y, self_state.orient_z, self_state.orient_w},
        {self_state.vel, 0, 0}
    );

    // --- Controller Law ---
    // Feedforward term (from the planner)
    tf2::Vector3 feedforward_accel = desired_point.acceleration;

    // Feedback terms (PD control on position error)
    tf2::Vector3 pos_error = desired_point.position - self_pos;
    tf2::Vector3 vel_error = desired_point.velocity - self_vel;
    tf2::Vector3 feedback_accel = params_.feedback_pos_gain * pos_error + params_.feedback_vel_gain * vel_error;
    
    // Total desired acceleration
    return feedforward_accel + feedback_accel;
}


// ==========================================================
// ATTITUDE COMMAND GENERATOR: Converts acceleration to roll/pitch. (Unchanged)
// ==========================================================
sim_msgs::msg::FwControl GuidanceAlgorithm::_generate_attitude_commands(
    const tf2::Vector3& desired_acceleration,
    const fwp_planner::msg::DynamicState& self_state)
{
    sim_msgs::msg::FwControl cmd;
    if (desired_acceleration.length() < 1e-6) {
        cmd.desired_roll = 0.0; cmd.desired_pitch = 0.0;
        return cmd;
    }
    
    tf2::Quaternion current_attitude(self_state.orient_x, self_state.orient_y, self_state.orient_z, self_state.orient_w);
    tf2::Vector3 current_heading_3d = tf2::quatRotate(current_attitude, tf2::Vector3(1, 0, 0));
    tf2::Vector3 desired_direction_vec = desired_acceleration.normalized();
    
    tf2::Vector3 rotation_axis_world = current_heading_3d.cross(desired_direction_vec);
    tf2::Vector3 rotation_axis_body = tf2::quatRotate(current_attitude.inverse(), rotation_axis_world);
    
    cmd.desired_pitch = params_.pitch_gain * rotation_axis_body.y();
    cmd.desired_roll = params_.roll_gain * rotation_axis_body.z();

    const double max_roll = 0.872; // 50 deg
    const double max_pitch = 0.610; // 35 deg
    cmd.desired_roll = std::max(-max_roll, std::min(max_roll, cmd.desired_roll));
    cmd.desired_pitch = std::max(-max_pitch, std::min(max_pitch, cmd.desired_pitch));
    
    cmd.desired_roll  = 0.2;  // TEST
    cmd.desired_pitch = -0.2;
    cmd.desired_vel   = 25;
    return cmd;
}