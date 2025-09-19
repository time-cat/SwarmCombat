// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fwp_planner:msg/FusedTeammate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fwp_planner/msg/detail/fused_teammate__rosidl_typesupport_introspection_c.h"
#include "fwp_planner/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fwp_planner/msg/detail/fused_teammate__functions.h"
#include "fwp_planner/msg/detail/fused_teammate__struct.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/time.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fwp_planner__msg__FusedTeammate__init(message_memory);
}

void fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_fini_function(void * message_memory)
{
  fwp_planner__msg__FusedTeammate__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_member_array[3] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__FusedTeammate, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__FusedTeammate, target_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner__msg__FusedTeammate, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_members = {
  "fwp_planner__msg",  // message namespace
  "FusedTeammate",  // message name
  3,  // number of fields
  sizeof(fwp_planner__msg__FusedTeammate),
  fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_member_array,  // message members
  fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_init_function,  // function to initialize message memory (memory has to be allocated)
  fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_type_support_handle = {
  0,
  &fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fwp_planner
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fwp_planner, msg, FusedTeammate)() {
  fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_type_support_handle.typesupport_identifier) {
    fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fwp_planner__msg__FusedTeammate__rosidl_typesupport_introspection_c__FusedTeammate_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
