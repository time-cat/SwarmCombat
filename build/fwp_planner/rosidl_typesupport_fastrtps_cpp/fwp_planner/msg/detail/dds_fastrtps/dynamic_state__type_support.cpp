// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/dynamic_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fwp_planner/msg/detail/dynamic_state__struct.hpp"

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: posi_n
  cdr << ros_message.posi_n;
  // Member: posi_e
  cdr << ros_message.posi_e;
  // Member: posi_d
  cdr << ros_message.posi_d;
  // Member: orient_x
  cdr << ros_message.orient_x;
  // Member: orient_y
  cdr << ros_message.orient_y;
  // Member: orient_z
  cdr << ros_message.orient_z;
  // Member: orient_w
  cdr << ros_message.orient_w;
  // Member: vel
  cdr << ros_message.vel;
  // Member: vel_alpha
  cdr << ros_message.vel_alpha;
  // Member: vel_bete
  cdr << ros_message.vel_bete;
  // Member: angle_alpha
  cdr << ros_message.angle_alpha;
  // Member: abgle_bete
  cdr << ros_message.abgle_bete;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fwp_planner::msg::DynamicState & ros_message)
{
  // Member: posi_n
  cdr >> ros_message.posi_n;

  // Member: posi_e
  cdr >> ros_message.posi_e;

  // Member: posi_d
  cdr >> ros_message.posi_d;

  // Member: orient_x
  cdr >> ros_message.orient_x;

  // Member: orient_y
  cdr >> ros_message.orient_y;

  // Member: orient_z
  cdr >> ros_message.orient_z;

  // Member: orient_w
  cdr >> ros_message.orient_w;

  // Member: vel
  cdr >> ros_message.vel;

  // Member: vel_alpha
  cdr >> ros_message.vel_alpha;

  // Member: vel_bete
  cdr >> ros_message.vel_bete;

  // Member: angle_alpha
  cdr >> ros_message.angle_alpha;

  // Member: abgle_bete
  cdr >> ros_message.abgle_bete;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
get_serialized_size(
  const fwp_planner::msg::DynamicState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: posi_n
  {
    size_t item_size = sizeof(ros_message.posi_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: posi_e
  {
    size_t item_size = sizeof(ros_message.posi_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: posi_d
  {
    size_t item_size = sizeof(ros_message.posi_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: orient_x
  {
    size_t item_size = sizeof(ros_message.orient_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: orient_y
  {
    size_t item_size = sizeof(ros_message.orient_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: orient_z
  {
    size_t item_size = sizeof(ros_message.orient_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: orient_w
  {
    size_t item_size = sizeof(ros_message.orient_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel
  {
    size_t item_size = sizeof(ros_message.vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_alpha
  {
    size_t item_size = sizeof(ros_message.vel_alpha);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_bete
  {
    size_t item_size = sizeof(ros_message.vel_bete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle_alpha
  {
    size_t item_size = sizeof(ros_message.angle_alpha);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: abgle_bete
  {
    size_t item_size = sizeof(ros_message.abgle_bete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
max_serialized_size_DynamicState(
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


  // Member: posi_n
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: posi_e
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: posi_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: orient_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: orient_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: orient_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: orient_w
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_alpha
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_bete
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: angle_alpha
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: abgle_bete
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
    using DataType = fwp_planner::msg::DynamicState;
    is_plain =
      (
      offsetof(DataType, abgle_bete) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DynamicState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fwp_planner::msg::DynamicState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DynamicState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fwp_planner::msg::DynamicState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DynamicState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fwp_planner::msg::DynamicState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DynamicState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DynamicState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DynamicState__callbacks = {
  "fwp_planner::msg",
  "DynamicState",
  _DynamicState__cdr_serialize,
  _DynamicState__cdr_deserialize,
  _DynamicState__get_serialized_size,
  _DynamicState__max_serialized_size
};

static rosidl_message_type_support_t _DynamicState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DynamicState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace fwp_planner

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_fwp_planner
const rosidl_message_type_support_t *
get_message_type_support_handle<fwp_planner::msg::DynamicState>()
{
  return &fwp_planner::msg::typesupport_fastrtps_cpp::_DynamicState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fwp_planner, msg, DynamicState)() {
  return &fwp_planner::msg::typesupport_fastrtps_cpp::_DynamicState__handle;
}

#ifdef __cplusplus
}
#endif
