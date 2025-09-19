// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sim_msgs:msg/PerceivedState.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__BUILDER_HPP_
#define SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sim_msgs/msg/detail/perceived_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sim_msgs
{

namespace msg
{

namespace builder
{

class Init_PerceivedState_is_alive
{
public:
  explicit Init_PerceivedState_is_alive(::sim_msgs::msg::PerceivedState & msg)
  : msg_(msg)
  {}
  ::sim_msgs::msg::PerceivedState is_alive(::sim_msgs::msg::PerceivedState::_is_alive_type arg)
  {
    msg_.is_alive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sim_msgs::msg::PerceivedState msg_;
};

class Init_PerceivedState_position
{
public:
  explicit Init_PerceivedState_position(::sim_msgs::msg::PerceivedState & msg)
  : msg_(msg)
  {}
  Init_PerceivedState_is_alive position(::sim_msgs::msg::PerceivedState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_PerceivedState_is_alive(msg_);
  }

private:
  ::sim_msgs::msg::PerceivedState msg_;
};

class Init_PerceivedState_id
{
public:
  explicit Init_PerceivedState_id(::sim_msgs::msg::PerceivedState & msg)
  : msg_(msg)
  {}
  Init_PerceivedState_position id(::sim_msgs::msg::PerceivedState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_PerceivedState_position(msg_);
  }

private:
  ::sim_msgs::msg::PerceivedState msg_;
};

class Init_PerceivedState_header
{
public:
  Init_PerceivedState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PerceivedState_id header(::sim_msgs::msg::PerceivedState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PerceivedState_id(msg_);
  }

private:
  ::sim_msgs::msg::PerceivedState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sim_msgs::msg::PerceivedState>()
{
  return sim_msgs::msg::builder::Init_PerceivedState_header();
}

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__BUILDER_HPP_
