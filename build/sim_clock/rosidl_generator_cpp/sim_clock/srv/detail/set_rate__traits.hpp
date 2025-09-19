// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sim_clock:srv/SetRate.idl
// generated code does not contain a copyright notice

#ifndef SIM_CLOCK__SRV__DETAIL__SET_RATE__TRAITS_HPP_
#define SIM_CLOCK__SRV__DETAIL__SET_RATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sim_clock/srv/detail/set_rate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sim_clock
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetRate_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: rate
  {
    out << "rate: ";
    rosidl_generator_traits::value_to_yaml(msg.rate, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetRate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rate: ";
    rosidl_generator_traits::value_to_yaml(msg.rate, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetRate_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sim_clock

namespace rosidl_generator_traits
{

[[deprecated("use sim_clock::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sim_clock::srv::SetRate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sim_clock::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sim_clock::srv::to_yaml() instead")]]
inline std::string to_yaml(const sim_clock::srv::SetRate_Request & msg)
{
  return sim_clock::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sim_clock::srv::SetRate_Request>()
{
  return "sim_clock::srv::SetRate_Request";
}

template<>
inline const char * name<sim_clock::srv::SetRate_Request>()
{
  return "sim_clock/srv/SetRate_Request";
}

template<>
struct has_fixed_size<sim_clock::srv::SetRate_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sim_clock::srv::SetRate_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sim_clock::srv::SetRate_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace sim_clock
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetRate_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetRate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetRate_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sim_clock

namespace rosidl_generator_traits
{

[[deprecated("use sim_clock::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sim_clock::srv::SetRate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sim_clock::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sim_clock::srv::to_yaml() instead")]]
inline std::string to_yaml(const sim_clock::srv::SetRate_Response & msg)
{
  return sim_clock::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sim_clock::srv::SetRate_Response>()
{
  return "sim_clock::srv::SetRate_Response";
}

template<>
inline const char * name<sim_clock::srv::SetRate_Response>()
{
  return "sim_clock/srv/SetRate_Response";
}

template<>
struct has_fixed_size<sim_clock::srv::SetRate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sim_clock::srv::SetRate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sim_clock::srv::SetRate_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sim_clock::srv::SetRate>()
{
  return "sim_clock::srv::SetRate";
}

template<>
inline const char * name<sim_clock::srv::SetRate>()
{
  return "sim_clock/srv/SetRate";
}

template<>
struct has_fixed_size<sim_clock::srv::SetRate>
  : std::integral_constant<
    bool,
    has_fixed_size<sim_clock::srv::SetRate_Request>::value &&
    has_fixed_size<sim_clock::srv::SetRate_Response>::value
  >
{
};

template<>
struct has_bounded_size<sim_clock::srv::SetRate>
  : std::integral_constant<
    bool,
    has_bounded_size<sim_clock::srv::SetRate_Request>::value &&
    has_bounded_size<sim_clock::srv::SetRate_Response>::value
  >
{
};

template<>
struct is_service<sim_clock::srv::SetRate>
  : std::true_type
{
};

template<>
struct is_service_request<sim_clock::srv::SetRate_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sim_clock::srv::SetRate_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SIM_CLOCK__SRV__DETAIL__SET_RATE__TRAITS_HPP_
