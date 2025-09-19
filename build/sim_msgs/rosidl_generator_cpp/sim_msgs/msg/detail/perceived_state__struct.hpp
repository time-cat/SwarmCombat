// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sim_msgs:msg/PerceivedState.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__STRUCT_HPP_
#define SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__STRUCT_HPP_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sim_msgs__msg__PerceivedState __attribute__((deprecated))
#else
# define DEPRECATED__sim_msgs__msg__PerceivedState __declspec(deprecated)
#endif

namespace sim_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PerceivedState_
{
  using Type = PerceivedState_<ContainerAllocator>;

  explicit PerceivedState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->is_alive = false;
    }
  }

  explicit PerceivedState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->is_alive = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _id_type =
    int32_t;
  _id_type id;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
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
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
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
    sim_msgs::msg::PerceivedState_<ContainerAllocator> *;
  using ConstRawPtr =
    const sim_msgs::msg::PerceivedState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::PerceivedState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::PerceivedState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sim_msgs__msg__PerceivedState
    std::shared_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sim_msgs__msg__PerceivedState
    std::shared_ptr<sim_msgs::msg::PerceivedState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PerceivedState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->is_alive != other.is_alive) {
      return false;
    }
    return true;
  }
  bool operator!=(const PerceivedState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PerceivedState_

// alias to use template instance with default allocator
using PerceivedState =
  sim_msgs::msg::PerceivedState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__STRUCT_HPP_
