// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "fwp_planner/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "fwp_planner/msg/detail/dynamic_state__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace fwp_planner
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
cdr_serialize(
  const fwp_planner::msg::DynamicState & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fwp_planner::msg::DynamicState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
get_serialized_size(
  const fwp_planner::msg::DynamicState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
max_serialized_size_DynamicState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace fwp_planner

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fwp_planner, msg, DynamicState)();

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
