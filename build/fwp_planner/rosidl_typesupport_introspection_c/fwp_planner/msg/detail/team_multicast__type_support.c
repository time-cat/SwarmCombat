// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fwp_planner/msg/detail/team_multicast__rosidl_typesupport_introspection_c.h"
#include "fwp_planner/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fwp_planner/msg/detail/team_multicast__functions.h"
#include "fwp_planner/msg/detail/team_multicast__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `known_teammates`
#include "fwp_planner/msg/fused_teammate.h"
// Member `known_teammates`
#include "fwp_planner/msg/detail/fused_teammate__rosidl_typesupport_introspection_c.h"
// Member `known_enemies`
#include "fwp_planner/msg/fused_enemy.h"
// Member `known_enemies`
#include "fwp_planner/msg/detail/fused_enemy__rosidl_typesupport_introspection_c.h"
// Member `dynamic_state`
#include "fwp_planner/msg/dynamic_state.h"
// Member `dynamic_state`
#include "fwp_planner/msg/detail/dynamic_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fwp_planner__msg__TeamMulticast__init(message_memory);
}

void fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_fini_function(void * message_memory)
{
  fwp_planner__msg__TeamMulticast__fini(message_memory);
}

size_t fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__size_function__TeamMulticast__known_teammates(
  const void * untyped_member)
{
  const fwp_planner__msg__FusedTeammate__Sequence * member =
    (const fwp_planner__msg__FusedTeammate__Sequence *)(untyped_member);
  return member->size;
}

const void * fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_const_function__TeamMulticast__known_teammates(
  const void * untyped_member, size_t index)
{
  const fwp_planner__msg__FusedTeammate__Sequence * member =
    (const fwp_planner__msg__FusedTeammate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_function__TeamMulticast__known_teammates(
  void * untyped_member, size_t index)
{
  fwp_planner__msg__FusedTeammate__Sequence * member =
    (fwp_planner__msg__FusedTeammate__Sequence *)(untyped_member);
  return &member->data[index];
}

void fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__fetch_function__TeamMulticast__known_teammates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const fwp_planner__msg__FusedTeammate * item =
    ((const fwp_planner__msg__FusedTeammate *)
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_const_function__TeamMulticast__known_teammates(untyped_member, index));
  fwp_planner__msg__FusedTeammate * value =
    (fwp_planner__msg__FusedTeammate *)(untyped_value);
  *value = *item;
}

void fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__assign_function__TeamMulticast__known_teammates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  fwp_planner__msg__FusedTeammate * item =
    ((fwp_planner__msg__FusedTeammate *)
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_function__TeamMulticast__known_teammates(untyped_member, index));
  const fwp_planner__msg__FusedTeammate * value =
    (const fwp_planner__msg__FusedTeammate *)(untyped_value);
  *item = *value;
}

bool fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__resize_function__TeamMulticast__known_teammates(
  void * untyped_member, size_t size)
{
  fwp_planner__msg__FusedTeammate__Sequence * member =
    (fwp_planner__msg__FusedTeammate__Sequence *)(untyped_member);
  fwp_planner__msg__FusedTeammate__Sequence__fini(member);
  return fwp_planner__msg__FusedTeammate__Sequence__init(member, size);
}

size_t fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__size_function__TeamMulticast__known_enemies(
  const void * untyped_member)
{
  const fwp_planner__msg__FusedEnemy__Sequence * member =
    (const fwp_planner__msg__FusedEnemy__Sequence *)(untyped_member);
  return member->size;
}

const void * fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_const_function__TeamMulticast__known_enemies(
  const void * untyped_member, size_t index)
{
  const fwp_planner__msg__FusedEnemy__Sequence * member =
    (const fwp_planner__msg__FusedEnemy__Sequence *)(untyped_member);
  return &member->data[index];
}

void * fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_function__TeamMulticast__known_enemies(
  void * untyped_member, size_t index)
{
  fwp_planner__msg__FusedEnemy__Sequence * member =
    (fwp_planner__msg__FusedEnemy__Sequence *)(untyped_member);
  return &member->data[index];
}

void fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__fetch_function__TeamMulticast__known_enemies(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const fwp_planner__msg__FusedEnemy * item =
    ((const fwp_planner__msg__FusedEnemy *)
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_const_function__TeamMulticast__known_enemies(untyped_member, index));
  fwp_planner__msg__FusedEnemy * value =
    (fwp_planner__msg__FusedEnemy *)(untyped_value);
  *value = *item;
}

void fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__assign_function__TeamMulticast__known_enemies(
  void * untyped_member, size_t index, const void * untyped_value)
{
  fwp_planner__msg__FusedEnemy * item =
    ((fwp_planner__msg__FusedEnemy *)
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_function__TeamMulticast__known_enemies(untyped_member, index));
  const fwp_planner__msg__FusedEnemy * value =
    (const fwp_planner__msg__FusedEnemy *)(untyped_value);
  *item = *value;
}

bool fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__resize_function__TeamMulticast__known_enemies(
  void * untyped_member, size_t size)
{
  fwp_planner__msg__FusedEnemy__Sequence * member =
    (fwp_planner__msg__FusedEnemy__Sequence *)(untyped_member);
  fwp_planner__msg__FusedEnemy__Sequence__fini(member);
  return fwp_planner__msg__FusedEnemy__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__TeamMulticast, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sender_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__TeamMulticast, sender_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "multicast_range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__TeamMulticast, multicast_range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "known_teammates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__TeamMulticast, known_teammates),  // bytes offset in struct
    NULL,  // default value
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__size_function__TeamMulticast__known_teammates,  // size() function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_const_function__TeamMulticast__known_teammates,  // get_const(index) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_function__TeamMulticast__known_teammates,  // get(index) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__fetch_function__TeamMulticast__known_teammates,  // fetch(index, &value) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__assign_function__TeamMulticast__known_teammates,  // assign(index, value) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__resize_function__TeamMulticast__known_teammates  // resize(index) function pointer
  },
  {
    "known_enemies",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__TeamMulticast, known_enemies),  // bytes offset in struct
    NULL,  // default value
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__size_function__TeamMulticast__known_enemies,  // size() function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_const_function__TeamMulticast__known_enemies,  // get_const(index) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__get_function__TeamMulticast__known_enemies,  // get(index) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__fetch_function__TeamMulticast__known_enemies,  // fetch(index, &value) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__assign_function__TeamMulticast__known_enemies,  // assign(index, value) function pointer
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__resize_function__TeamMulticast__known_enemies  // resize(index) function pointer
  },
  {
    "dynamic_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__TeamMulticast, dynamic_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_alive",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__TeamMulticast, is_alive),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_members = {
  "fwp_planner__msg",  // message namespace
  "TeamMulticast",  // message name
  7,  // number of fields
  sizeof(fwp_planner__msg__TeamMulticast),
  fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_member_array,  // message members
  fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_init_function,  // function to initialize message memory (memory has to be allocated)
  fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_type_support_handle = {
  0,
  &fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fwp_planner
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fwp_planner, msg, TeamMulticast)() {
  fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fwp_planner, msg, FusedTeammate)();
  fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fwp_planner, msg, FusedEnemy)();
  fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fwp_planner, msg, DynamicState)();
  if (!fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_type_support_handle.typesupport_identifier) {
    fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fwp_planner__msg__TeamMulticast__rosidl_typesupport_introspection_c__TeamMulticast_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
