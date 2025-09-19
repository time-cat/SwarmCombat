// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__STRUCT_HPP_
#define FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__fwp_planner__msg__DynamicState __attribute__((deprecated))
#else
# define DEPRECATED__fwp_planner__msg__DynamicState __declspec(deprecated)
#endif

namespace fwp_planner
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DynamicState_
{
  using Type = DynamicState_<ContainerAllocator>;

  explicit DynamicState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->posi_n = 0.0;
      this->posi_e = 0.0;
      this->posi_d = 0.0;
      this->orient_x = 0.0;
      this->orient_y = 0.0;
      this->orient_z = 0.0;
      this->orient_w = 0.0;
      this->vel = 0.0;
      this->vel_alpha = 0.0;
      this->vel_bete = 0.0;
      this->angle_alpha = 0.0;
      this->abgle_bete = 0.0;
    }
  }

  explicit DynamicState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->posi_n = 0.0;
      this->posi_e = 0.0;
      this->posi_d = 0.0;
      this->orient_x = 0.0;
      this->orient_y = 0.0;
      this->orient_z = 0.0;
      this->orient_w = 0.0;
      this->vel = 0.0;
      this->vel_alpha = 0.0;
      this->vel_bete = 0.0;
      this->angle_alpha = 0.0;
      this->abgle_bete = 0.0;
    }
  }

  // field types and members
  using _posi_n_type =
    double;
  _posi_n_type posi_n;
  using _posi_e_type =
    double;
  _posi_e_type posi_e;
  using _posi_d_type =
    double;
  _posi_d_type posi_d;
  using _orient_x_type =
    double;
  _orient_x_type orient_x;
  using _orient_y_type =
    double;
  _orient_y_type orient_y;
  using _orient_z_type =
    double;
  _orient_z_type orient_z;
  using _orient_w_type =
    double;
  _orient_w_type orient_w;
  using _vel_type =
    double;
  _vel_type vel;
  using _vel_alpha_type =
    double;
  _vel_alpha_type vel_alpha;
  using _vel_bete_type =
    double;
  _vel_bete_type vel_bete;
  using _angle_alpha_type =
    double;
  _angle_alpha_type angle_alpha;
  using _abgle_bete_type =
    double;
  _abgle_bete_type abgle_bete;

  // setters for named parameter idiom
  Type & set__posi_n(
    const double & _arg)
  {
    this->posi_n = _arg;
    return *this;
  }
  Type & set__posi_e(
    const double & _arg)
  {
    this->posi_e = _arg;
    return *this;
  }
  Type & set__posi_d(
    const double & _arg)
  {
    this->posi_d = _arg;
    return *this;
  }
  Type & set__orient_x(
    const double & _arg)
  {
    this->orient_x = _arg;
    return *this;
  }
  Type & set__orient_y(
    const double & _arg)
  {
    this->orient_y = _arg;
    return *this;
  }
  Type & set__orient_z(
    const double & _arg)
  {
    this->orient_z = _arg;
    return *this;
  }
  Type & set__orient_w(
    const double & _arg)
  {
    this->orient_w = _arg;
    return *this;
  }
  Type & set__vel(
    const double & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__vel_alpha(
    const double & _arg)
  {
    this->vel_alpha = _arg;
    return *this;
  }
  Type & set__vel_bete(
    const double & _arg)
  {
    this->vel_bete = _arg;
    return *this;
  }
  Type & set__angle_alpha(
    const double & _arg)
  {
    this->angle_alpha = _arg;
    return *this;
  }
  Type & set__abgle_bete(
    const double & _arg)
  {
    this->abgle_bete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fwp_planner::msg::DynamicState_<ContainerAllocator> *;
  using ConstRawPtr =
    const fwp_planner::msg::DynamicState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fwp_planner::msg::DynamicState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fwp_planner::msg::DynamicState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fwp_planner__msg__DynamicState
    std::shared_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fwp_planner__msg__DynamicState
    std::shared_ptr<fwp_planner::msg::DynamicState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DynamicState_ & other) const
  {
    if (this->posi_n != other.posi_n) {
      return false;
    }
    if (this->posi_e != other.posi_e) {
      return false;
    }
    if (this->posi_d != other.posi_d) {
      return false;
    }
    if (this->orient_x != other.orient_x) {
      return false;
    }
    if (this->orient_y != other.orient_y) {
      return false;
    }
    if (this->orient_z != other.orient_z) {
      return false;
    }
    if (this->orient_w != other.orient_w) {
      return false;
    }
    if (this->vel != other.vel) {
      return false;
    }
    if (this->vel_alpha != other.vel_alpha) {
      return false;
    }
    if (this->vel_bete != other.vel_bete) {
      return false;
    }
    if (this->angle_alpha != other.angle_alpha) {
      return false;
    }
    if (this->abgle_bete != other.abgle_bete) {
      return false;
    }
    return true;
  }
  bool operator!=(const DynamicState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DynamicState_

// alias to use template instance with default allocator
using DynamicState =
  fwp_planner::msg::DynamicState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__STRUCT_HPP_
