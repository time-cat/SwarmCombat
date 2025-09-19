// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fwp_planner:msg/FusedTeammate.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__BUILDER_HPP_
#define FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fwp_planner/msg/detail/fused_teammate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fwp_planner
{

namespace msg
{

namespace builder
{

class Init_FusedTeammate_timestamp
{
public:
  explicit Init_FusedTeammate_timestamp(::fwp_planner::msg::FusedTeammate & msg)
  : msg_(msg)
  {}
  ::fwp_planner::msg::FusedTeammate timestamp(::fwp_planner::msg::FusedTeammate::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fwp_planner::msg::FusedTeammate msg_;
};

class Init_FusedTeammate_target_id
{
public:
  explicit Init_FusedTeammate_target_id(::fwp_planner::msg::FusedTeammate & msg)
  : msg_(msg)
  {}
  Init_FusedTeammate_timestamp target_id(::fwp_planner::msg::FusedTeammate::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return Init_FusedTeammate_timestamp(msg_);
  }

private:
  ::fwp_planner::msg::FusedTeammate msg_;
};

class Init_FusedTeammate_id
{
public:
  Init_FusedTeammate_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FusedTeammate_target_id id(::fwp_planner::msg::FusedTeammate::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_FusedTeammate_target_id(msg_);
  }

private:
  ::fwp_planner::msg::FusedTeammate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fwp_planner::msg::FusedTeammate>()
{
  return fwp_planner::msg::builder::Init_FusedTeammate_id();
}

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__BUILDER_HPP_
