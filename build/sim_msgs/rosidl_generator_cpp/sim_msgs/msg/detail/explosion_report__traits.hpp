// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sim_msgs:msg/ExplosionReport.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__TRAITS_HPP_
#define SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sim_msgs/msg/detail/explosion_report__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'exp_center'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace sim_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ExplosionReport & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: attacker_id
  {
    out << "attacker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.attacker_id, out);
    out << ", ";
  }

  // member: exp_center
  {
    out << "exp_center: ";
    to_flow_style_yaml(msg.exp_center, out);
    out << ", ";
  }

  // member: exp_range
  {
    out << "exp_range: ";
    rosidl_generator_traits::value_to_yaml(msg.exp_range, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExplosionReport & msg,
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

  // member: attacker_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "attacker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.attacker_id, out);
    out << "\n";
  }

  // member: exp_center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "exp_center:\n";
    to_block_style_yaml(msg.exp_center, out, indentation + 2);
  }

  // member: exp_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "exp_range: ";
    rosidl_generator_traits::value_to_yaml(msg.exp_range, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExplosionReport & msg, bool use_flow_style = false)
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
  const sim_msgs::msg::ExplosionReport & msg,
  std::ostream & out, size_t indentation = 0)
{
  sim_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sim_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const sim_msgs::msg::ExplosionReport & msg)
{
  return sim_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sim_msgs::msg::ExplosionReport>()
{
  return "sim_msgs::msg::ExplosionReport";
}

template<>
inline const char * name<sim_msgs::msg::ExplosionReport>()
{
  return "sim_msgs/msg/ExplosionReport";
}

template<>
struct has_fixed_size<sim_msgs::msg::ExplosionReport>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<sim_msgs::msg::ExplosionReport>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<sim_msgs::msg::ExplosionReport>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__TRAITS_HPP_
