// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sim_msgs:msg/DeathNotice.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__STRUCT_HPP_
#define SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__sim_msgs__msg__DeathNotice __attribute__((deprecated))
#else
# define DEPRECATED__sim_msgs__msg__DeathNotice __declspec(deprecated)
#endif

namespace sim_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DeathNotice_
{
  using Type = DeathNotice_<ContainerAllocator>;

  explicit DeathNotice_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->death = false;
    }
  }

  explicit DeathNotice_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->death = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _death_type =
    bool;
  _death_type death;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__death(
    const bool & _arg)
  {
    this->death = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sim_msgs::msg::DeathNotice_<ContainerAllocator> *;
  using ConstRawPtr =
    const sim_msgs::msg::DeathNotice_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::DeathNotice_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::DeathNotice_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sim_msgs__msg__DeathNotice
    std::shared_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sim_msgs__msg__DeathNotice
    std::shared_ptr<sim_msgs::msg::DeathNotice_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeathNotice_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->death != other.death) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeathNotice_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeathNotice_

// alias to use template instance with default allocator
using DeathNotice =
  sim_msgs::msg::DeathNotice_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__STRUCT_HPP_
