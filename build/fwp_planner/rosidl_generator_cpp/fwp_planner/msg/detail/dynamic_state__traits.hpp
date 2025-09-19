// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__TRAITS_HPP_
#define FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fwp_planner/msg/detail/dynamic_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace fwp_planner
{

namespace msg
{

inline void to_flow_style_yaml(
  const DynamicState & msg,
  std::ostream & out)
{
  out << "{";
  // member: posi_n
  {
    out << "posi_n: ";
    rosidl_generator_traits::value_to_yaml(msg.posi_n, out);
    out << ", ";
  }

  // member: posi_e
  {
    out << "posi_e: ";
    rosidl_generator_traits::value_to_yaml(msg.posi_e, out);
    out << ", ";
  }

  // member: posi_d
  {
    out << "posi_d: ";
    rosidl_generator_traits::value_to_yaml(msg.posi_d, out);
    out << ", ";
  }

  // member: orient_x
  {
    out << "orient_x: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_x, out);
    out << ", ";
  }

  // member: orient_y
  {
    out << "orient_y: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_y, out);
    out << ", ";
  }

  // member: orient_z
  {
    out << "orient_z: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_z, out);
    out << ", ";
  }

  // member: orient_w
  {
    out << "orient_w: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_w, out);
    out << ", ";
  }

  // member: vel
  {
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
    out << ", ";
  }

  // member: vel_alpha
  {
    out << "vel_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_alpha, out);
    out << ", ";
  }

  // member: vel_bete
  {
    out << "vel_bete: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_bete, out);
    out << ", ";
  }

  // member: angle_alpha
  {
    out << "angle_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_alpha, out);
    out << ", ";
  }

  // member: abgle_bete
  {
    out << "abgle_bete: ";
    rosidl_generator_traits::value_to_yaml(msg.abgle_bete, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DynamicState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: posi_n
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posi_n: ";
    rosidl_generator_traits::value_to_yaml(msg.posi_n, out);
    out << "\n";
  }

  // member: posi_e
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posi_e: ";
    rosidl_generator_traits::value_to_yaml(msg.posi_e, out);
    out << "\n";
  }

  // member: posi_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posi_d: ";
    rosidl_generator_traits::value_to_yaml(msg.posi_d, out);
    out << "\n";
  }

  // member: orient_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orient_x: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_x, out);
    out << "\n";
  }

  // member: orient_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orient_y: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_y, out);
    out << "\n";
  }

  // member: orient_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orient_z: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_z, out);
    out << "\n";
  }

  // member: orient_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orient_w: ";
    rosidl_generator_traits::value_to_yaml(msg.orient_w, out);
    out << "\n";
  }

  // member: vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
    out << "\n";
  }

  // member: vel_alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_alpha, out);
    out << "\n";
  }

  // member: vel_bete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_bete: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_bete, out);
    out << "\n";
  }

  // member: angle_alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_alpha, out);
    out << "\n";
  }

  // member: abgle_bete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "abgle_bete: ";
    rosidl_generator_traits::value_to_yaml(msg.abgle_bete, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DynamicState & msg, bool use_flow_style = false)
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
  const fwp_planner::msg::DynamicState & msg,
  std::ostream & out, size_t indentation = 0)
{
  fwp_planner::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fwp_planner::msg::to_yaml() instead")]]
inline std::string to_yaml(const fwp_planner::msg::DynamicState & msg)
{
  return fwp_planner::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fwp_planner::msg::DynamicState>()
{
  return "fwp_planner::msg::DynamicState";
}

template<>
inline const char * name<fwp_planner::msg::DynamicState>()
{
  return "fwp_planner/msg/DynamicState";
}

template<>
struct has_fixed_size<fwp_planner::msg::DynamicState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fwp_planner::msg::DynamicState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fwp_planner::msg::DynamicState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__TRAITS_HPP_
