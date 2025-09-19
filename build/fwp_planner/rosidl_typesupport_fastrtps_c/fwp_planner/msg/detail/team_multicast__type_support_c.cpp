// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/team_multicast__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "fwp_planner/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fwp_planner/msg/detail/team_multicast__struct.h"
#include "fwp_planner/msg/detail/team_multicast__functions.h"
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

#include "fwp_planner/msg/detail/dynamic_state__functions.h"  // dynamic_state
#include "fwp_planner/msg/detail/fused_enemy__functions.h"  // known_enemies
#include "fwp_planner/msg/detail/fused_teammate__functions.h"  // known_teammates
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
size_t get_serialized_size_fwp_planner__msg__DynamicState(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_fwp_planner__msg__DynamicState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fwp_planner, msg, DynamicState)();
size_t get_serialized_size_fwp_planner__msg__FusedEnemy(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_fwp_planner__msg__FusedEnemy(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fwp_planner, msg, FusedEnemy)();
size_t get_serialized_size_fwp_planner__msg__FusedTeammate(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_fwp_planner__msg__FusedTeammate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fwp_planner, msg, FusedTeammate)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_fwp_planner
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_fwp_planner
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_fwp_planner
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _TeamMulticast__ros_msg_type = fwp_planner__msg__TeamMulticast;

static bool _TeamMulticast__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TeamMulticast__ros_msg_type * ros_message = static_cast<const _TeamMulticast__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: sender_id
  {
    cdr << ros_message->sender_id;
  }

  // Field name: multicast_range
  {
    cdr << ros_message->multicast_range;
  }

  // Field name: known_teammates
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fwp_planner, msg, FusedTeammate
      )()->data);
    size_t size = ros_message->known_teammates.size;
    auto array_ptr = ros_message->known_teammates.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: known_enemies
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fwp_planner, msg, FusedEnemy
      )()->data);
    size_t size = ros_message->known_enemies.size;
    auto array_ptr = ros_message->known_enemies.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: dynamic_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fwp_planner, msg, DynamicState
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->dynamic_state, cdr))
    {
      return false;
    }
  }

  // Field name: is_alive
  {
    cdr << (ros_message->is_alive ? true : false);
  }

  return true;
}

static bool _TeamMulticast__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TeamMulticast__ros_msg_type * ros_message = static_cast<_TeamMulticast__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: sender_id
  {
    cdr >> ros_message->sender_id;
  }

  // Field name: multicast_range
  {
    cdr >> ros_message->multicast_range;
  }

  // Field name: known_teammates
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fwp_planner, msg, FusedTeammate
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->known_teammates.data) {
      fwp_planner__msg__FusedTeammate__Sequence__fini(&ros_message->known_teammates);
    }
    if (!fwp_planner__msg__FusedTeammate__Sequence__init(&ros_message->known_teammates, size)) {
      fprintf(stderr, "failed to create array for field 'known_teammates'");
      return false;
    }
    auto array_ptr = ros_message->known_teammates.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: known_enemies
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fwp_planner, msg, FusedEnemy
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->known_enemies.data) {
      fwp_planner__msg__FusedEnemy__Sequence__fini(&ros_message->known_enemies);
    }
    if (!fwp_planner__msg__FusedEnemy__Sequence__init(&ros_message->known_enemies, size)) {
      fprintf(stderr, "failed to create array for field 'known_enemies'");
      return false;
    }
    auto array_ptr = ros_message->known_enemies.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: dynamic_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fwp_planner, msg, DynamicState
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->dynamic_state))
    {
      return false;
    }
  }

  // Field name: is_alive
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_alive = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fwp_planner
size_t get_serialized_size_fwp_planner__msg__TeamMulticast(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TeamMulticast__ros_msg_type * ros_message = static_cast<const _TeamMulticast__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name sender_id
  {
    size_t item_size = sizeof(ros_message->sender_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name multicast_range
  {
    size_t item_size = sizeof(ros_message->multicast_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name known_teammates
  {
    size_t array_size = ros_message->known_teammates.size;
    auto array_ptr = ros_message->known_teammates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_fwp_planner__msg__FusedTeammate(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name known_enemies
  {
    size_t array_size = ros_message->known_enemies.size;
    auto array_ptr = ros_message->known_enemies.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_fwp_planner__msg__FusedEnemy(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name dynamic_state

  current_alignment += get_serialized_size_fwp_planner__msg__DynamicState(
    &(ros_message->dynamic_state), current_alignment);
  // field.name is_alive
  {
    size_t item_size = sizeof(ros_message->is_alive);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TeamMulticast__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fwp_planner__msg__TeamMulticast(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fwp_planner
size_t max_serialized_size_fwp_planner__msg__TeamMulticast(
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

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: sender_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: multicast_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: known_teammates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_fwp_planner__msg__FusedTeammate(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: known_enemies
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_fwp_planner__msg__FusedEnemy(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: dynamic_state
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_fwp_planner__msg__DynamicState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: is_alive
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = fwp_planner__msg__TeamMulticast;
    is_plain =
      (
      offsetof(DataType, is_alive) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TeamMulticast__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_fwp_planner__msg__TeamMulticast(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TeamMulticast = {
  "fwp_planner::msg",
  "TeamMulticast",
  _TeamMulticast__cdr_serialize,
  _TeamMulticast__cdr_deserialize,
  _TeamMulticast__get_serialized_size,
  _TeamMulticast__max_serialized_size
};

static rosidl_message_type_support_t _TeamMulticast__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TeamMulticast,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fwp_planner, msg, TeamMulticast)() {
  return &_TeamMulticast__type_support;
}

#if defined(__cplusplus)
}
#endif
