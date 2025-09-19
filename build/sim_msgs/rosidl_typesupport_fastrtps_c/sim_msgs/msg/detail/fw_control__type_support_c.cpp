// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice
#include "sim_msgs/msg/detail/fw_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "sim_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "sim_msgs/msg/detail/fw_control__struct.h"
#include "sim_msgs/msg/detail/fw_control__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _FwControl__ros_msg_type = sim_msgs__msg__FwControl;

static bool _FwControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FwControl__ros_msg_type * ros_message = static_cast<const _FwControl__ros_msg_type *>(untyped_ros_message);
  // Field name: desired_roll
  {
    cdr << ros_message->desired_roll;
  }

  // Field name: desired_pitch
  {
    cdr << ros_message->desired_pitch;
  }

  // Field name: desired_yaw_rate
  {
    cdr << ros_message->desired_yaw_rate;
  }

  // Field name: desired_airspeed
  {
    cdr << ros_message->desired_airspeed;
  }

  return true;
}

static bool _FwControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FwControl__ros_msg_type * ros_message = static_cast<_FwControl__ros_msg_type *>(untyped_ros_message);
  // Field name: desired_roll
  {
    cdr >> ros_message->desired_roll;
  }

  // Field name: desired_pitch
  {
    cdr >> ros_message->desired_pitch;
  }

  // Field name: desired_yaw_rate
  {
    cdr >> ros_message->desired_yaw_rate;
  }

  // Field name: desired_airspeed
  {
    cdr >> ros_message->desired_airspeed;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sim_msgs
size_t get_serialized_size_sim_msgs__msg__FwControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FwControl__ros_msg_type * ros_message = static_cast<const _FwControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name desired_roll
  {
    size_t item_size = sizeof(ros_message->desired_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name desired_pitch
  {
    size_t item_size = sizeof(ros_message->desired_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name desired_yaw_rate
  {
    size_t item_size = sizeof(ros_message->desired_yaw_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name desired_airspeed
  {
    size_t item_size = sizeof(ros_message->desired_airspeed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FwControl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_sim_msgs__msg__FwControl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sim_msgs
size_t max_serialized_size_sim_msgs__msg__FwControl(
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

  // member: desired_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: desired_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: desired_yaw_rate
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: desired_airspeed
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
    using DataType = sim_msgs__msg__FwControl;
    is_plain =
      (
      offsetof(DataType, desired_airspeed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FwControl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_sim_msgs__msg__FwControl(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FwControl = {
  "sim_msgs::msg",
  "FwControl",
  _FwControl__cdr_serialize,
  _FwControl__cdr_deserialize,
  _FwControl__get_serialized_size,
  _FwControl__max_serialized_size
};

static rosidl_message_type_support_t _FwControl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FwControl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sim_msgs, msg, FwControl)() {
  return &_FwControl__type_support;
}

#if defined(__cplusplus)
}
#endif
