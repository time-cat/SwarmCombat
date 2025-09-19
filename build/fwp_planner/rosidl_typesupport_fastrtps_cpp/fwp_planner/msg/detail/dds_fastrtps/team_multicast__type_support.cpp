// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/team_multicast__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fwp_planner/msg/detail/team_multicast__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace fwp_planner
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const fwp_planner::msg::FusedTeammate &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  fwp_planner::msg::FusedTeammate &);
size_t get_serialized_size(
  const fwp_planner::msg::FusedTeammate &,
  size_t current_alignment);
size_t
max_serialized_size_FusedTeammate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace fwp_planner

namespace fwp_planner
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const fwp_planner::msg::FusedEnemy &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  fwp_planner::msg::FusedEnemy &);
size_t get_serialized_size(
  const fwp_planner::msg::FusedEnemy &,
  size_t current_alignment);
size_t
max_serialized_size_FusedEnemy(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace fwp_planner

namespace fwp_planner
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const fwp_planner::msg::DynamicState &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  fwp_planner::msg::DynamicState &);
size_t get_serialized_size(
  const fwp_planner::msg::DynamicState &,
  size_t current_alignment);
size_t
max_serialized_size_DynamicState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace fwp_planner


namespace fwp_planner
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
cdr_serialize(
  const fwp_planner::msg::TeamMulticast & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: sender_id
  cdr << ros_message.sender_id;
  // Member: multicast_range
  cdr << ros_message.multicast_range;
  // Member: known_teammates
  {
    size_t size = ros_message.known_teammates.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      fwp_planner::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.known_teammates[i],
        cdr);
    }
  }
  // Member: known_enemies
  {
    size_t size = ros_message.known_enemies.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      fwp_planner::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.known_enemies[i],
        cdr);
    }
  }
  // Member: dynamic_state
  fwp_planner::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.dynamic_state,
    cdr);
  // Member: is_alive
  cdr << (ros_message.is_alive ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fwp_planner::msg::TeamMulticast & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: sender_id
  cdr >> ros_message.sender_id;

  // Member: multicast_range
  cdr >> ros_message.multicast_range;

  // Member: known_teammates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.known_teammates.resize(size);
    for (size_t i = 0; i < size; i++) {
      fwp_planner::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.known_teammates[i]);
    }
  }

  // Member: known_enemies
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.known_enemies.resize(size);
    for (size_t i = 0; i < size; i++) {
      fwp_planner::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.known_enemies[i]);
    }
  }

  // Member: dynamic_state
  fwp_planner::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.dynamic_state);

  // Member: is_alive
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_alive = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
get_serialized_size(
  const fwp_planner::msg::TeamMulticast & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: sender_id
  {
    size_t item_size = sizeof(ros_message.sender_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: multicast_range
  {
    size_t item_size = sizeof(ros_message.multicast_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: known_teammates
  {
    size_t array_size = ros_message.known_teammates.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        fwp_planner::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.known_teammates[index], current_alignment);
    }
  }
  // Member: known_enemies
  {
    size_t array_size = ros_message.known_enemies.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        fwp_planner::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.known_enemies[index], current_alignment);
    }
  }
  // Member: dynamic_state

  current_alignment +=
    fwp_planner::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.dynamic_state, current_alignment);
  // Member: is_alive
  {
    size_t item_size = sizeof(ros_message.is_alive);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fwp_planner
max_serialized_size_TeamMulticast(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: sender_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: multicast_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: known_teammates
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
      size_t inner_size =
        fwp_planner::msg::typesupport_fastrtps_cpp::max_serialized_size_FusedTeammate(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: known_enemies
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
      size_t inner_size =
        fwp_planner::msg::typesupport_fastrtps_cpp::max_serialized_size_FusedEnemy(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: dynamic_state
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        fwp_planner::msg::typesupport_fastrtps_cpp::max_serialized_size_DynamicState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: is_alive
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
    using DataType = fwp_planner::msg::TeamMulticast;
    is_plain =
      (
      offsetof(DataType, is_alive) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _TeamMulticast__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fwp_planner::msg::TeamMulticast *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TeamMulticast__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fwp_planner::msg::TeamMulticast *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TeamMulticast__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fwp_planner::msg::TeamMulticast *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TeamMulticast__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TeamMulticast(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TeamMulticast__callbacks = {
  "fwp_planner::msg",
  "TeamMulticast",
  _TeamMulticast__cdr_serialize,
  _TeamMulticast__cdr_deserialize,
  _TeamMulticast__get_serialized_size,
  _TeamMulticast__max_serialized_size
};

static rosidl_message_type_support_t _TeamMulticast__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TeamMulticast__callbacks,
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
get_message_type_support_handle<fwp_planner::msg::TeamMulticast>()
{
  return &fwp_planner::msg::typesupport_fastrtps_cpp::_TeamMulticast__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fwp_planner, msg, TeamMulticast)() {
  return &fwp_planner::msg::typesupport_fastrtps_cpp::_TeamMulticast__handle;
}

#ifdef __cplusplus
}
#endif
