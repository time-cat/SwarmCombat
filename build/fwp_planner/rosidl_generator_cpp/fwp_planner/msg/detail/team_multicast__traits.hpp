// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__TRAITS_HPP_
#define FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fwp_planner/msg/detail/team_multicast__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'known_teammates'
#include "fwp_planner/msg/detail/fused_teammate__traits.hpp"
// Member 'known_enemies'
#include "fwp_planner/msg/detail/fused_enemy__traits.hpp"
// Member 'dynamic_state'
#include "fwp_planner/msg/detail/dynamic_state__traits.hpp"

namespace fwp_planner
{

namespace msg
{

inline void to_flow_style_yaml(
  const TeamMulticast & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: sender_id
  {
    out << "sender_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sender_id, out);
    out << ", ";
  }

  // member: multicast_range
  {
    out << "multicast_range: ";
    rosidl_generator_traits::value_to_yaml(msg.multicast_range, out);
    out << ", ";
  }

  // member: known_teammates
  {
    if (msg.known_teammates.size() == 0) {
      out << "known_teammates: []";
    } else {
      out << "known_teammates: [";
      size_t pending_items = msg.known_teammates.size();
      for (auto item : msg.known_teammates) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: known_enemies
  {
    if (msg.known_enemies.size() == 0) {
      out << "known_enemies: []";
    } else {
      out << "known_enemies: [";
      size_t pending_items = msg.known_enemies.size();
      for (auto item : msg.known_enemies) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: dynamic_state
  {
    out << "dynamic_state: ";
    to_flow_style_yaml(msg.dynamic_state, out);
    out << ", ";
  }

  // member: is_alive
  {
    out << "is_alive: ";
    rosidl_generator_traits::value_to_yaml(msg.is_alive, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeamMulticast & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: sender_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sender_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sender_id, out);
    out << "\n";
  }

  // member: multicast_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "multicast_range: ";
    rosidl_generator_traits::value_to_yaml(msg.multicast_range, out);
    out << "\n";
  }

  // member: known_teammates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.known_teammates.size() == 0) {
      out << "known_teammates: []\n";
    } else {
      out << "known_teammates:\n";
      for (auto item : msg.known_teammates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: known_enemies
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.known_enemies.size() == 0) {
      out << "known_enemies: []\n";
    } else {
      out << "known_enemies:\n";
      for (auto item : msg.known_enemies) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: dynamic_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dynamic_state:\n";
    to_block_style_yaml(msg.dynamic_state, out, indentation + 2);
  }

  // member: is_alive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_alive: ";
    rosidl_generator_traits::value_to_yaml(msg.is_alive, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeamMulticast & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace fwp_planner

namespace rosidl_generator_traits
{

[[deprecated("use fwp_planner::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fwp_planner::msg::TeamMulticast & msg,
  std::ostream & out, size_t indentation = 0)
{
  fwp_planner::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fwp_planner::msg::to_yaml() instead")]]
inline std::string to_yaml(const fwp_planner::msg::TeamMulticast & msg)
{
  return fwp_planner::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fwp_planner::msg::TeamMulticast>()
{
  return "fwp_planner::msg::TeamMulticast";
}

template<>
inline const char * name<fwp_planner::msg::TeamMulticast>()
{
  return "fwp_planner/msg/TeamMulticast";
}

template<>
struct has_fixed_size<fwp_planner::msg::TeamMulticast>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fwp_planner::msg::TeamMulticast>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fwp_planner::msg::TeamMulticast>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__TRAITS_HPP_
