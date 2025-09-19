// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fwp_planner:msg/TeamBroadcast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__BUILDER_HPP_
#define FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fwp_planner/msg/detail/team_broadcast__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fwp_planner
{

namespace msg
{

namespace builder
{

class Init_TeamBroadcast_is_alive
{
public:
  explicit Init_TeamBroadcast_is_alive(::fwp_planner::msg::TeamBroadcast & msg)
  : msg_(msg)
  {}
  ::fwp_planner::msg::TeamBroadcast is_alive(::fwp_planner::msg::TeamBroadcast::_is_alive_type arg)
  {
    msg_.is_alive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fwp_planner::msg::TeamBroadcast msg_;
};

class Init_TeamBroadcast_dynamic_state
{
public:
  explicit Init_TeamBroadcast_dynamic_state(::fwp_planner::msg::TeamBroadcast & msg)
  : msg_(msg)
  {}
  Init_TeamBroadcast_is_alive dynamic_state(::fwp_planner::msg::TeamBroadcast::_dynamic_state_type arg)
  {
    msg_.dynamic_state = std::move(arg);
    return Init_TeamBroadcast_is_alive(msg_);
  }

private:
  ::fwp_planner::msg::TeamBroadcast msg_;
};

class Init_TeamBroadcast_broadcast_range
{
public:
  explicit Init_TeamBroadcast_broadcast_range(::fwp_planner::msg::TeamBroadcast & msg)
  : msg_(msg)
  {}
  Init_TeamBroadcast_dynamic_state broadcast_range(::fwp_planner::msg::TeamBroadcast::_broadcast_range_type arg)
  {
    msg_.broadcast_range = std::move(arg);
    return Init_TeamBroadcast_dynamic_state(msg_);
  }

private:
  ::fwp_planner::msg::TeamBroadcast msg_;
};

class Init_TeamBroadcast_sender_id
{
public:
  explicit Init_TeamBroadcast_sender_id(::fwp_planner::msg::TeamBroadcast & msg)
  : msg_(msg)
  {}
  Init_TeamBroadcast_broadcast_range sender_id(::fwp_planner::msg::TeamBroadcast::_sender_id_type arg)
  {
    msg_.sender_id = std::move(arg);
    return Init_TeamBroadcast_broadcast_range(msg_);
  }

private:
  ::fwp_planner::msg::TeamBroadcast msg_;
};

class Init_TeamBroadcast_header
{
public:
  Init_TeamBroadcast_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeamBroadcast_sender_id header(::fwp_planner::msg::TeamBroadcast::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TeamBroadcast_sender_id(msg_);
  }

private:
  ::fwp_planner::msg::TeamBroadcast msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fwp_planner::msg::TeamBroadcast>()
{
  return fwp_planner::msg::builder::Init_TeamBroadcast_header();
}

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__BUILDER_HPP_
