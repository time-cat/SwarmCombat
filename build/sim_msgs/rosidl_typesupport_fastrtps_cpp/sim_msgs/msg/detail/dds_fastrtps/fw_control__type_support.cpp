// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice
#include "sim_msgs/msg/detail/fw_control__rosidl_typesupport_fastrtps_cpp.hpp"
#include "sim_msgs/msg/detail/fw_control__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace sim_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sim_msgs
cdr_serialize(
  const sim_msgs::msg::FwControl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: desired_roll
  cdr << ros_message.desired_roll;
  // Member: desired_pitch
  cdr << ros_message.desired_pitch;
  // Member: desired_yaw_rate
  cdr << ros_message.desired_yaw_rate;
  // Member: desired_airspeed
  cdr << ros_message.desired_airspeed;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sim_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sim_msgs::msg::FwControl & ros_message)
{
  // Member: desired_roll
  cdr >> ros_message.desired_roll;

  // Member: desired_pitch
  cdr >> ros_message.desired_pitch;

  // Member: desired_yaw_rate
  cdr >> ros_message.desired_yaw_rate;

  // Member: desired_airspeed
  cdr >> ros_message.desired_airspeed;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sim_msgs
get_serialized_size(
  const sim_msgs::msg::FwControl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: desired_roll
  {
    size_t item_size = sizeof(ros_message.desired_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: desired_pitch
  {
    size_t item_size = sizeof(ros_message.desired_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: desired_yaw_rate
  {
    size_t item_size = sizeof(ros_message.desired_yaw_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: desired_airspeed
  {
    size_t item_size = sizeof(ros_message.desired_airspeed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sim_msgs
max_serialized_size_FwControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: desired_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: desired_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: desired_yaw_rate
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: desired_airspeed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = sim_msgs::msg::FwControl;
    is_plain =
      (
      offsetof(DataType, desired_airspeed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FwControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const sim_msgs::msg::FwControl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FwControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<sim_msgs::msg::FwControl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FwControl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const sim_msgs::msg::FwControl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FwControl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FwControl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FwControl__callbacks = {
  "sim_msgs::msg",
  "FwControl",
  _FwControl__cdr_serialize,
  _FwControl__cdr_deserialize,
  _FwControl__get_serialized_size,
  _FwControl__max_serialized_size
};

static rosidl_message_type_support_t _FwControl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FwControl__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sim_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_sim_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<sim_msgs::msg::FwControl>()
{
  return &sim_msgs::msg::typesupport_fastrtps_cpp::_FwControl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sim_msgs, msg, FwControl)() {
  return &sim_msgs::msg::typesupport_fastrtps_cpp::_FwControl__handle;
}

#ifdef __cplusplus
}
#endif
