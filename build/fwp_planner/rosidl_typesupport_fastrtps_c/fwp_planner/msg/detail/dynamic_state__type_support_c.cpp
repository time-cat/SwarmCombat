// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/dynamic_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "fwp_planner/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fwp_planner/msg/detail/dynamic_state__struct.h"
#include "fwp_planner/msg/detail/dynamic_state__functions.h"
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


using _DynamicState__ros_msg_type = fwp_planner__msg__DynamicState;

static bool _DynamicState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DynamicState__ros_msg_type * ros_message = static_cast<const _DynamicState__ros_msg_type *>(untyped_ros_message);
  // Field name: posi_n
  {
    cdr << ros_message->posi_n;
  }

  // Field name: posi_e
  {
    cdr << ros_message->posi_e;
  }

  // Field name: posi_d
  {
    cdr << ros_message->posi_d;
  }

  // Field name: orient_x
  {
    cdr << ros_message->orient_x;
  }

  // Field name: orient_y
  {
    cdr << ros_message->orient_y;
  }

  // Field name: orient_z
  {
    cdr << ros_message->orient_z;
  }

  // Field name: orient_w
  {
    cdr << ros_message->orient_w;
  }

  // Field name: vel
  {
    cdr << ros_message->vel;
  }

  // Field name: vel_alpha
  {
    cdr << ros_message->vel_alpha;
  }

  // Field name: vel_bete
  {
    cdr << ros_message->vel_bete;
  }

  // Field name: angle_alpha
  {
    cdr << ros_message->angle_alpha;
  }

  // Field name: abgle_bete
  {
    cdr << ros_message->abgle_bete;
  }

  return true;
}

static bool _DynamicState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DynamicState__ros_msg_type * ros_message = static_cast<_DynamicState__ros_msg_type *>(untyped_ros_message);
  // Field name: posi_n
  {
    cdr >> ros_message->posi_n;
  }

  // Field name: posi_e
  {
    cdr >> ros_message->posi_e;
  }

  // Field name: posi_d
  {
    cdr >> ros_message->posi_d;
  }

  // Field name: orient_x
  {
    cdr >> ros_message->orient_x;
  }

  // Field name: orient_y
  {
    cdr >> ros_message->orient_y;
  }

  // Field name: orient_z
  {
    cdr >> ros_message->orient_z;
  }

  // Field name: orient_w
  {
    cdr >> ros_message->orient_w;
  }

  // Field name: vel
  {
    cdr >> ros_message->vel;
  }

  // Field name: vel_alpha
  {
    cdr >> ros_message->vel_alpha;
  }

  // Field name: vel_bete
  {
    cdr >> ros_message->vel_bete;
  }

  // Field name: angle_alpha
  {
    cdr >> ros_message->angle_alpha;
  }

  // Field name: abgle_bete
  {
    cdr >> ros_message->abgle_bete;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fwp_planner
size_t get_serialized_size_fwp_planner__msg__DynamicState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DynamicState__ros_msg_type * ros_message = static_cast<const _DynamicState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name posi_n
  {
    size_t item_size = sizeof(ros_message->posi_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posi_e
  {
    size_t item_size = sizeof(ros_message->posi_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posi_d
  {
    size_t item_size = sizeof(ros_message->posi_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name orient_x
  {
    size_t item_size = sizeof(ros_message->orient_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name orient_y
  {
    size_t item_size = sizeof(ros_message->orient_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name orient_z
  {
    size_t item_size = sizeof(ros_message->orient_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name orient_w
  {
    size_t item_size = sizeof(ros_message->orient_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel
  {
    size_t item_size = sizeof(ros_message->vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_alpha
  {
    size_t item_size = sizeof(ros_message->vel_alpha);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_bete
  {
    size_t item_size = sizeof(ros_message->vel_bete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angle_alpha
  {
    size_t item_size = sizeof(ros_message->angle_alpha);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name abgle_bete
  {
    size_t item_size = sizeof(ros_message->abgle_bete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DynamicState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fwp_planner__msg__DynamicState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fwp_planner
size_t max_serialized_size_fwp_planner__msg__DynamicState(
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

  // member: posi_n
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: posi_e
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: posi_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: orient_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: orient_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: orient_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: orient_w
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_alpha
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_bete
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: angle_alpha
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: abgle_bete
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
    using DataType = fwp_planner__msg__DynamicState;
    is_plain =
      (
      offsetof(DataType, abgle_bete) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DynamicState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_fwp_planner__msg__DynamicState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DynamicState = {
  "fwp_planner::msg",
  "DynamicState",
  _DynamicState__cdr_serialize,
  _DynamicState__cdr_deserialize,
  _DynamicState__get_serialized_size,
  _DynamicState__max_serialized_size
};

static rosidl_message_type_support_t _DynamicState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DynamicState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fwp_planner, msg, DynamicState)() {
  return &_DynamicState__type_support;
}

#if defined(__cplusplus)
}
#endif
