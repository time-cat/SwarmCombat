// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__FW_CONTROL__STRUCT_HPP_
#define SIM_MSGS__MSG__DETAIL__FW_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sim_msgs__msg__FwControl __attribute__((deprecated))
#else
# define DEPRECATED__sim_msgs__msg__FwControl __declspec(deprecated)
#endif

namespace sim_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FwControl_
{
  using Type = FwControl_<ContainerAllocator>;

  explicit FwControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->desired_roll = 0.0;
      this->desired_pitch = 0.0;
      this->desired_yaw_rate = 0.0;
      this->desired_airspeed = 0.0;
    }
  }

  explicit FwControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->desired_roll = 0.0;
      this->desired_pitch = 0.0;
      this->desired_yaw_rate = 0.0;
      this->desired_airspeed = 0.0;
    }
  }

  // field types and members
  using _desired_roll_type =
    double;
  _desired_roll_type desired_roll;
  using _desired_pitch_type =
    double;
  _desired_pitch_type desired_pitch;
  using _desired_yaw_rate_type =
    double;
  _desired_yaw_rate_type desired_yaw_rate;
  using _desired_airspeed_type =
    double;
  _desired_airspeed_type desired_airspeed;

  // setters for named parameter idiom
  Type & set__desired_roll(
    const double & _arg)
  {
    this->desired_roll = _arg;
    return *this;
  }
  Type & set__desired_pitch(
    const double & _arg)
  {
    this->desired_pitch = _arg;
    return *this;
  }
  Type & set__desired_yaw_rate(
    const double & _arg)
  {
    this->desired_yaw_rate = _arg;
    return *this;
  }
  Type & set__desired_airspeed(
    const double & _arg)
  {
    this->desired_airspeed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sim_msgs::msg::FwControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const sim_msgs::msg::FwControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sim_msgs::msg::FwControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sim_msgs::msg::FwControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::FwControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::FwControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::FwControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::FwControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sim_msgs::msg::FwControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sim_msgs::msg::FwControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sim_msgs__msg__FwControl
    std::shared_ptr<sim_msgs::msg::FwControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sim_msgs__msg__FwControl
    std::shared_ptr<sim_msgs::msg::FwControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FwControl_ & other) const
  {
    if (this->desired_roll != other.desired_roll) {
      return false;
    }
    if (this->desired_pitch != other.desired_pitch) {
      return false;
    }
    if (this->desired_yaw_rate != other.desired_yaw_rate) {
      return false;
    }
    if (this->desired_airspeed != other.desired_airspeed) {
      return false;
    }
    return true;
  }
  bool operator!=(const FwControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FwControl_

// alias to use template instance with default allocator
using FwControl =
  sim_msgs::msg::FwControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__FW_CONTROL__STRUCT_HPP_
