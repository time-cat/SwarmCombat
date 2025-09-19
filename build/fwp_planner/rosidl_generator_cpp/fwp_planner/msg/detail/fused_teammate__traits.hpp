// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fwp_planner:msg/FusedTeammate.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__TRAITS_HPP_
#define FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fwp_planner/msg/detail/fused_teammate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace fwp_planner
{

namespace msg
{

inline void to_flow_style_yaml(
  const FusedTeammate & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: target_id
  {
    out << "target_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_id, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FusedTeammate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: target_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_id, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FusedTeammate & msg, bool use_flow_style = false)
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
  const fwp_planner::msg::FusedTeammate & msg,
  std::ostream & out, size_t indentation = 0)
{
  fwp_planner::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fwp_planner::msg::to_yaml() instead")]]
inline std::string to_yaml(const fwp_planner::msg::FusedTeammate & msg)
{
  return fwp_planner::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fwp_planner::msg::FusedTeammate>()
{
  return "fwp_planner::msg::FusedTeammate";
}

template<>
inline const char * name<fwp_planner::msg::FusedTeammate>()
{
  return "fwp_planner/msg/FusedTeammate";
}

template<>
struct has_fixed_size<fwp_planner::msg::FusedTeammate>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<fwp_planner::msg::FusedTeammate>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<fwp_planner::msg::FusedTeammate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__TRAITS_HPP_
