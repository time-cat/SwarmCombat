// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sim_msgs:msg/ExplosionReport.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__STRUCT_HPP_
#define SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__STRUCT_HPP_

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
// Member 'exp_center'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sim_msgs__msg__ExplosionReport __attribute__((deprecated))
#else
# define DEPRECATED__sim_msgs__msg__ExplosionReport __declspec(deprecated)
#endif

namespace sim_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ExplosionReport_
{
  using Type = ExplosionReport_<ContainerAllocator>;

  explicit ExplosionReport_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    exp_center(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->attacker_id = 0l;
      this->exp_range = 0.0f;
    }
  }

  explicit ExplosionReport_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    exp_center(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->attacker_id = 0l;
      this->exp_range = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _attacker_id_type =
    int32_t;
  _attacker_id_type attacker_id;
  using _exp_center_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _exp_center_type exp_center;
  using _exp_range_type =
    float;
  _exp_range_type exp_range;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__attacker_id(
    const int32_t & _arg)
  {
    this->attacker_id = _arg;
    return *this;
  }
  Type & set__exp_center(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->exp_center = _arg;
    return *this;
  }
  Type & set__exp_range(
    const float & _arg)
  {
    this->exp_range = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sim_msgs::msg::ExplosionReport_<ContainerAllocator> *;
  using ConstRawPtr =
    const sim_msgs::msg::ExplosionReport_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::ExplosionReport_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sim_msgs::msg::ExplosionReport_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sim_msgs__msg__ExplosionReport
    std::shared_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sim_msgs__msg__ExplosionReport
    std::shared_ptr<sim_msgs::msg::ExplosionReport_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExplosionReport_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->attacker_id != other.attacker_id) {
      return false;
    }
    if (this->exp_center != other.exp_center) {
      return false;
    }
    if (this->exp_range != other.exp_range) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExplosionReport_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExplosionReport_

// alias to use template instance with default allocator
using ExplosionReport =
  sim_msgs::msg::ExplosionReport_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__STRUCT_HPP_
