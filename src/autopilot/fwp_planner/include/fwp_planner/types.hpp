#ifndef FWP_PLANNER__TYPES_HPP_
#define FWP_PLANNER__TYPES_HPP_

#include <geometry_msgs/msg/point.hpp>
#include <rclcpp/time.hpp>
#include "fwp_planner/msg/dynamic_state.hpp"

// Data structures to hold situational awareness information
// These are now in their own file and can be shared safely.

struct StoredEnemyInfo {
    geometry_msgs::msg::Point position;
    rclcpp::Time timestamp;
};

struct StoredTeammateInfo {
    int target_id;
    rclcpp::Time timestamp;
};

struct StoredBroadcastInfo {
    fwp_planner::msg::DynamicState dynamic_state;
    rclcpp::Time timestamp;
};

#endif // FWP_PLANNER__TYPES_HPP_