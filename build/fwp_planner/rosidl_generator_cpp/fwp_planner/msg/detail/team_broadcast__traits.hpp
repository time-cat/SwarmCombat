// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fwp_planner:msg/TeamBroadcast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__TRAITS_HPP_
#define FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fwp_planner/msg/detail/team_broadcast__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'dynamic_state'
#include "fwp_planner/msg/detail/dynamic_state__traits.hpp"

namespace fwp_planner
{

namespace msg
{

inline void to_flow_style_yaml(
  const TeamBroadcast & msg,
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

  // member: broadcast_range
  {
    out << "broadcast_range: ";
    rosidl_generator_traits::value_to_yaml(msg.broadcast_range, out);
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
  const TeamBroadcast & msg,
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

  // member: broadcast_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "broadcast_range: ";
    rosidl_generator_traits::value_to_yaml(msg.broadcast_range, out);
    out << "\n";
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

inline std::string to_yaml(const TeamBroadcast & msg, bool use_flow_style = false)
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
  const fwp_planner::msg::TeamBroadcast & msg,
  std::ostream & out, size_t indentation = 0)
{
  fwp_planner::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fwp_planner::msg::to_yaml() instead")]]
inline std::string to_yaml(const fwp_planner::msg::TeamBroadcast & msg)
{
  return fwp_planner::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fwp_planner::msg::TeamBroadcast>()
{
  return "fwp_planner::msg::TeamBroadcast";
}

template<>
inline const char * name<fwp_planner::msg::TeamBroadcast>()
{
  return "fwp_planner/msg/TeamBroadcast";
}

template<>
struct has_fixed_size<fwp_planner::msg::TeamBroadcast>
  : std::integral_constant<bool, has_fixed_size<fwp_planner::msg::DynamicState>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<fwp_planner::msg::TeamBroadcast>
  : std::integral_constant<bool, has_bounded_size<fwp_planner::msg::DynamicState>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<fwp_planner::msg::TeamBroadcast>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__TRAITS_HPP_
