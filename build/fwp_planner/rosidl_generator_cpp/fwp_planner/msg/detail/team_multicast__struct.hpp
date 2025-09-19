// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__STRUCT_HPP_
#define FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'known_teammates'
#include "fwp_planner/msg/detail/fused_teammate__struct.hpp"
// Member 'known_enemies'
#include "fwp_planner/msg/detail/fused_enemy__struct.hpp"
// Member 'dynamic_state'
#include "fwp_planner/msg/detail/dynamic_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fwp_planner__msg__TeamMulticast __attribute__((deprecated))
#else
# define DEPRECATED__fwp_planner__msg__TeamMulticast __declspec(deprecated)
#endif

namespace fwp_planner
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TeamMulticast_
{
  using Type = TeamMulticast_<ContainerAllocator>;

  explicit TeamMulticast_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    dynamic_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sender_id = 0l;
      this->multicast_range = 0.0f;
      this->is_alive = false;
    }
  }

  explicit TeamMulticast_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    dynamic_state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sender_id = 0l;
      this->multicast_range = 0.0f;
      this->is_alive = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _sender_id_type =
    int32_t;
  _sender_id_type sender_id;
  using _multicast_range_type =
    float;
  _multicast_range_type multicast_range;
  using _known_teammates_type =
    std::vector<fwp_planner::msg::FusedTeammate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<fwp_planner::msg::FusedTeammate_<ContainerAllocator>>>;
  _known_teammates_type known_teammates;
  using _known_enemies_type =
    std::vector<fwp_planner::msg::FusedEnemy_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<fwp_planner::msg::FusedEnemy_<ContainerAllocator>>>;
  _known_enemies_type known_enemies;
  using _dynamic_state_type =
    fwp_planner::msg::DynamicState_<ContainerAllocator>;
  _dynamic_state_type dynamic_state;
  using _is_alive_type =
    bool;
  _is_alive_type is_alive;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__sender_id(
    const int32_t & _arg)
  {
    this->sender_id = _arg;
    return *this;
  }
  Type & set__multicast_range(
    const float & _arg)
  {
    this->multicast_range = _arg;
    return *this;
  }
  Type & set__known_teammates(
    const std::vector<fwp_planner::msg::FusedTeammate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<fwp_planner::msg::FusedTeammate_<ContainerAllocator>>> & _arg)
  {
    this->known_teammates = _arg;
    return *this;
  }
  Type & set__known_enemies(
    const std::vector<fwp_planner::msg::FusedEnemy_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<fwp_planner::msg::FusedEnemy_<ContainerAllocator>>> & _arg)
  {
    this->known_enemies = _arg;
    return *this;
  }
  Type & set__dynamic_state(
    const fwp_planner::msg::DynamicState_<ContainerAllocator> & _arg)
  {
    this->dynamic_state = _arg;
    return *this;
  }
  Type & set__is_alive(
    const bool & _arg)
  {
    this->is_alive = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fwp_planner::msg::TeamMulticast_<ContainerAllocator> *;
  using ConstRawPtr =
    const fwp_planner::msg::TeamMulticast_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fwp_planner::msg::TeamMulticast_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fwp_planner::msg::TeamMulticast_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fwp_planner__msg__TeamMulticast
    std::shared_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fwp_planner__msg__TeamMulticast
    std::shared_ptr<fwp_planner::msg::TeamMulticast_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TeamMulticast_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->sender_id != other.sender_id) {
      return false;
    }
    if (this->multicast_range != other.multicast_range) {
      return false;
    }
    if (this->known_teammates != other.known_teammates) {
      return false;
    }
    if (this->known_enemies != other.known_enemies) {
      return false;
    }
    if (this->dynamic_state != other.dynamic_state) {
      return false;
    }
    if (this->is_alive != other.is_alive) {
      return false;
    }
    return true;
  }
  bool operator!=(const TeamMulticast_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TeamMulticast_

// alias to use template instance with default allocator
using TeamMulticast =
  fwp_planner::msg::TeamMulticast_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__STRUCT_HPP_
