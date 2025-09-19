// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fwp_planner:msg/FusedTeammate.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__STRUCT_HPP_
#define FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fwp_planner__msg__FusedTeammate __attribute__((deprecated))
#else
# define DEPRECATED__fwp_planner__msg__FusedTeammate __declspec(deprecated)
#endif

namespace fwp_planner
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FusedTeammate_
{
  using Type = FusedTeammate_<ContainerAllocator>;

  explicit FusedTeammate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->target_id = 0l;
    }
  }

  explicit FusedTeammate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->target_id = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _target_id_type =
    int32_t;
  _target_id_type target_id;
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__target_id(
    const int32_t & _arg)
  {
    this->target_id = _arg;
    return *this;
  }
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fwp_planner::msg::FusedTeammate_<ContainerAllocator> *;
  using ConstRawPtr =
    const fwp_planner::msg::FusedTeammate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fwp_planner::msg::FusedTeammate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fwp_planner::msg::FusedTeammate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fwp_planner__msg__FusedTeammate
    std::shared_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fwp_planner__msg__FusedTeammate
    std::shared_ptr<fwp_planner::msg::FusedTeammate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FusedTeammate_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->target_id != other.target_id) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const FusedTeammate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FusedTeammate_

// alias to use template instance with default allocator
using FusedTeammate =
  fwp_planner::msg::FusedTeammate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__STRUCT_HPP_
