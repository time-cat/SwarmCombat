// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fwp_planner:msg/FusedEnemy.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__FUSED_ENEMY__BUILDER_HPP_
#define FWP_PLANNER__MSG__DETAIL__FUSED_ENEMY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fwp_planner/msg/detail/fused_enemy__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fwp_planner
{

namespace msg
{

namespace builder
{

class Init_FusedEnemy_timestamp
{
public:
  explicit Init_FusedEnemy_timestamp(::fwp_planner::msg::FusedEnemy & msg)
  : msg_(msg)
  {}
  ::fwp_planner::msg::FusedEnemy timestamp(::fwp_planner::msg::FusedEnemy::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fwp_planner::msg::FusedEnemy msg_;
};

class Init_FusedEnemy_position
{
public:
  explicit Init_FusedEnemy_position(::fwp_planner::msg::FusedEnemy & msg)
  : msg_(msg)
  {}
  Init_FusedEnemy_timestamp position(::fwp_planner::msg::FusedEnemy::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_FusedEnemy_timestamp(msg_);
  }

private:
  ::fwp_planner::msg::FusedEnemy msg_;
};

class Init_FusedEnemy_id
{
public:
  Init_FusedEnemy_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FusedEnemy_position id(::fwp_planner::msg::FusedEnemy::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_FusedEnemy_position(msg_);
  }

private:
  ::fwp_planner::msg::FusedEnemy msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fwp_planner::msg::FusedEnemy>()
{
  return fwp_planner::msg::builder::Init_FusedEnemy_id();
}

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__FUSED_ENEMY__BUILDER_HPP_
