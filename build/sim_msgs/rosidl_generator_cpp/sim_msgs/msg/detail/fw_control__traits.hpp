// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__FW_CONTROL__TRAITS_HPP_
#define SIM_MSGS__MSG__DETAIL__FW_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sim_msgs/msg/detail/fw_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sim_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FwControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: desired_roll
  {
    out << "desired_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_roll, out);
    out << ", ";
  }

  // member: desired_pitch
  {
    out << "desired_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_pitch, out);
    out << ", ";
  }

  // member: desired_yaw_rate
  {
    out << "desired_yaw_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_yaw_rate, out);
    out << ", ";
  }

  // member: desired_airspeed
  {
    out << "desired_airspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_airspeed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FwControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: desired_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desired_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_roll, out);
    out << "\n";
  }

  // member: desired_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desired_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_pitch, out);
    out << "\n";
  }

  // member: desired_yaw_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desired_yaw_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_yaw_rate, out);
    out << "\n";
  }

  // member: desired_airspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desired_airspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_airspeed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FwControl & msg, bool use_flow_style = false)
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

}  // namespace sim_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sim_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sim_msgs::msg::FwControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  sim_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sim_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const sim_msgs::msg::FwControl & msg)
{
  return sim_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sim_msgs::msg::FwControl>()
{
  return "sim_msgs::msg::FwControl";
}

template<>
inline const char * name<sim_msgs::msg::FwControl>()
{
  return "sim_msgs/msg/FwControl";
}

template<>
struct has_fixed_size<sim_msgs::msg::FwControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sim_msgs::msg::FwControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sim_msgs::msg::FwControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SIM_MSGS__MSG__DETAIL__FW_CONTROL__TRAITS_HPP_
