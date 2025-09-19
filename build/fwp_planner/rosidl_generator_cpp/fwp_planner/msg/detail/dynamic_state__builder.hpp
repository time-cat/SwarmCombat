// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__BUILDER_HPP_
#define FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fwp_planner/msg/detail/dynamic_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fwp_planner
{

namespace msg
{

namespace builder
{

class Init_DynamicState_abgle_bete
{
public:
  explicit Init_DynamicState_abgle_bete(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  ::fwp_planner::msg::DynamicState abgle_bete(::fwp_planner::msg::DynamicState::_abgle_bete_type arg)
  {
    msg_.abgle_bete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_angle_alpha
{
public:
  explicit Init_DynamicState_angle_alpha(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_abgle_bete angle_alpha(::fwp_planner::msg::DynamicState::_angle_alpha_type arg)
  {
    msg_.angle_alpha = std::move(arg);
    return Init_DynamicState_abgle_bete(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_vel_bete
{
public:
  explicit Init_DynamicState_vel_bete(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_angle_alpha vel_bete(::fwp_planner::msg::DynamicState::_vel_bete_type arg)
  {
    msg_.vel_bete = std::move(arg);
    return Init_DynamicState_angle_alpha(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_vel_alpha
{
public:
  explicit Init_DynamicState_vel_alpha(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_vel_bete vel_alpha(::fwp_planner::msg::DynamicState::_vel_alpha_type arg)
  {
    msg_.vel_alpha = std::move(arg);
    return Init_DynamicState_vel_bete(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_vel
{
public:
  explicit Init_DynamicState_vel(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_vel_alpha vel(::fwp_planner::msg::DynamicState::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_DynamicState_vel_alpha(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_orient_w
{
public:
  explicit Init_DynamicState_orient_w(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_vel orient_w(::fwp_planner::msg::DynamicState::_orient_w_type arg)
  {
    msg_.orient_w = std::move(arg);
    return Init_DynamicState_vel(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_orient_z
{
public:
  explicit Init_DynamicState_orient_z(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_orient_w orient_z(::fwp_planner::msg::DynamicState::_orient_z_type arg)
  {
    msg_.orient_z = std::move(arg);
    return Init_DynamicState_orient_w(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_orient_y
{
public:
  explicit Init_DynamicState_orient_y(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_orient_z orient_y(::fwp_planner::msg::DynamicState::_orient_y_type arg)
  {
    msg_.orient_y = std::move(arg);
    return Init_DynamicState_orient_z(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_orient_x
{
public:
  explicit Init_DynamicState_orient_x(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_orient_y orient_x(::fwp_planner::msg::DynamicState::_orient_x_type arg)
  {
    msg_.orient_x = std::move(arg);
    return Init_DynamicState_orient_y(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_posi_d
{
public:
  explicit Init_DynamicState_posi_d(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_orient_x posi_d(::fwp_planner::msg::DynamicState::_posi_d_type arg)
  {
    msg_.posi_d = std::move(arg);
    return Init_DynamicState_orient_x(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_posi_e
{
public:
  explicit Init_DynamicState_posi_e(::fwp_planner::msg::DynamicState & msg)
  : msg_(msg)
  {}
  Init_DynamicState_posi_d posi_e(::fwp_planner::msg::DynamicState::_posi_e_type arg)
  {
    msg_.posi_e = std::move(arg);
    return Init_DynamicState_posi_d(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

class Init_DynamicState_posi_n
{
public:
  Init_DynamicState_posi_n()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DynamicState_posi_e posi_n(::fwp_planner::msg::DynamicState::_posi_n_type arg)
  {
    msg_.posi_n = std::move(arg);
    return Init_DynamicState_posi_e(msg_);
  }

private:
  ::fwp_planner::msg::DynamicState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fwp_planner::msg::DynamicState>()
{
  return fwp_planner::msg::builder::Init_DynamicState_posi_n();
}

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__BUILDER_HPP_
