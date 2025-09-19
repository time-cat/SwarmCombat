// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "fwp_planner/msg/detail/team_multicast__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace fwp_planner
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TeamMulticast_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) fwp_planner::msg::TeamMulticast(_init);
}

void TeamMulticast_fini_function(void * message_memory)
{
  auto typed_message = static_cast<fwp_planner::msg::TeamMulticast *>(message_memory);
  typed_message->~TeamMulticast();
}

size_t size_function__TeamMulticast__known_teammates(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<fwp_planner::msg::FusedTeammate> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TeamMulticast__known_teammates(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<fwp_planner::msg::FusedTeammate> *>(untyped_member);
  return &member[index];
}

void * get_function__TeamMulticast__known_teammates(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<fwp_planner::msg::FusedTeammate> *>(untyped_member);
  return &member[index];
}

void fetch_function__TeamMulticast__known_teammates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const fwp_planner::msg::FusedTeammate *>(
    get_const_function__TeamMulticast__known_teammates(untyped_member, index));
  auto & value = *reinterpret_cast<fwp_planner::msg::FusedTeammate *>(untyped_value);
  value = item;
}

void assign_function__TeamMulticast__known_teammates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<fwp_planner::msg::FusedTeammate *>(
    get_function__TeamMulticast__known_teammates(untyped_member, index));
  const auto & value = *reinterpret_cast<const fwp_planner::msg::FusedTeammate *>(untyped_value);
  item = value;
}

void resize_function__TeamMulticast__known_teammates(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<fwp_planner::msg::FusedTeammate> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TeamMulticast__known_enemies(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<fwp_planner::msg::FusedEnemy> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TeamMulticast__known_enemies(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<fwp_planner::msg::FusedEnemy> *>(untyped_member);
  return &member[index];
}

void * get_function__TeamMulticast__known_enemies(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<fwp_planner::msg::FusedEnemy> *>(untyped_member);
  return &member[index];
}

void fetch_function__TeamMulticast__known_enemies(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const fwp_planner::msg::FusedEnemy *>(
    get_const_function__TeamMulticast__known_enemies(untyped_member, index));
  auto & value = *reinterpret_cast<fwp_planner::msg::FusedEnemy *>(untyped_value);
  value = item;
}

void assign_function__TeamMulticast__known_enemies(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<fwp_planner::msg::FusedEnemy *>(
    get_function__TeamMulticast__known_enemies(untyped_member, index));
  const auto & value = *reinterpret_cast<const fwp_planner::msg::FusedEnemy *>(untyped_value);
  item = value;
}

void resize_function__TeamMulticast__known_enemies(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<fwp_planner::msg::FusedEnemy> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TeamMulticast_message_member_array[7] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner::msg::TeamMulticast, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sender_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner::msg::TeamMulticast, sender_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "multicast_range",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner::msg::TeamMulticast, multicast_range),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "known_teammates",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<fwp_planner::msg::FusedTeammate>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner::msg::TeamMulticast, known_teammates),  // bytes offset in struct
    nullptr,  // default value
    size_function__TeamMulticast__known_teammates,  // size() function pointer
    get_const_function__TeamMulticast__known_teammates,  // get_const(index) function pointer
    get_function__TeamMulticast__known_teammates,  // get(index) function pointer
    fetch_function__TeamMulticast__known_teammates,  // fetch(index, &value) function pointer
    assign_function__TeamMulticast__known_teammates,  // assign(index, value) function pointer
    resize_function__TeamMulticast__known_teammates  // resize(index) function pointer
  },
  {
    "known_enemies",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<fwp_planner::msg::FusedEnemy>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner::msg::TeamMulticast, known_enemies),  // bytes offset in struct
    nullptr,  // default value
    size_function__TeamMulticast__known_enemies,  // size() function pointer
    get_const_function__TeamMulticast__known_enemies,  // get_const(index) function pointer
    get_function__TeamMulticast__known_enemies,  // get(index) function pointer
    fetch_function__TeamMulticast__known_enemies,  // fetch(index, &value) function pointer
    assign_function__TeamMulticast__known_enemies,  // assign(index, value) function pointer
    resize_function__TeamMulticast__known_enemies  // resize(index) function pointer
  },
  {
    "dynamic_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<fwp_planner::msg::DynamicState>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner::msg::TeamMulticast, dynamic_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "is_alive",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fwp_planner::msg::TeamMulticast, is_alive),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TeamMulticast_message_members = {
  "fwp_planner::msg",  // message namespace
  "TeamMulticast",  // message name
  7,  // number of fields
  sizeof(fwp_planner::msg::TeamMulticast),
  TeamMulticast_message_member_array,  // message members
  TeamMulticast_init_function,  // function to initialize message memory (memory has to be allocated)
  TeamMulticast_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TeamMulticast_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TeamMulticast_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace fwp_planner


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fwp_planner::msg::TeamMulticast>()
{
  return &::fwp_planner::msg::rosidl_typesupport_introspection_cpp::TeamMulticast_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fwp_planner, msg, TeamMulticast)() {
  return &::fwp_planner::msg::rosidl_typesupport_introspection_cpp::TeamMulticast_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
