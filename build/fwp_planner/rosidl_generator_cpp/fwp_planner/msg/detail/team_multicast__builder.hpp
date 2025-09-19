// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__BUILDER_HPP_
#define FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fwp_planner/msg/detail/team_multicast__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fwp_planner
{

namespace msg
{

namespace builder
{

class Init_TeamMulticast_is_alive
{
public:
  explicit Init_TeamMulticast_is_alive(::fwp_planner::msg::TeamMulticast & msg)
  : msg_(msg)
  {}
  ::fwp_planner::msg::TeamMulticast is_alive(::fwp_planner::msg::TeamMulticast::_is_alive_type arg)
  {
    msg_.is_alive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fwp_planner::msg::TeamMulticast msg_;
};

class Init_TeamMulticast_dynamic_state
{
public:
  explicit Init_TeamMulticast_dynamic_state(::fwp_planner::msg::TeamMulticast & msg)
  : msg_(msg)
  {}
  Init_TeamMulticast_is_alive dynamic_state(::fwp_planner::msg::TeamMulticast::_dynamic_state_type arg)
  {
    msg_.dynamic_state = std::move(arg);
    return Init_TeamMulticast_is_alive(msg_);
  }

private:
  ::fwp_planner::msg::TeamMulticast msg_;
};

class Init_TeamMulticast_known_enemies
{
public:
  explicit Init_TeamMulticast_known_enemies(::fwp_planner::msg::TeamMulticast & msg)
  : msg_(msg)
  {}
  Init_TeamMulticast_dynamic_state known_enemies(::fwp_planner::msg::TeamMulticast::_known_enemies_type arg)
  {
    msg_.known_enemies = std::move(arg);
    return Init_TeamMulticast_dynamic_state(msg_);
  }

private:
  ::fwp_planner::msg::TeamMulticast msg_;
};

class Init_TeamMulticast_known_teammates
{
public:
  explicit Init_TeamMulticast_known_teammates(::fwp_planner::msg::TeamMulticast & msg)
  : msg_(msg)
  {}
  Init_TeamMulticast_known_enemies known_teammates(::fwp_planner::msg::TeamMulticast::_known_teammates_type arg)
  {
    msg_.known_teammates = std::move(arg);
    return Init_TeamMulticast_known_enemies(msg_);
  }

private:
  ::fwp_planner::msg::TeamMulticast msg_;
};

class Init_TeamMulticast_multicast_range
{
public:
  explicit Init_TeamMulticast_multicast_range(::fwp_planner::msg::TeamMulticast & msg)
  : msg_(msg)
  {}
  Init_TeamMulticast_known_teammates multicast_range(::fwp_planner::msg::TeamMulticast::_multicast_range_type arg)
  {
    msg_.multicast_range = std::move(arg);
    return Init_TeamMulticast_known_teammates(msg_);
  }

private:
  ::fwp_planner::msg::TeamMulticast msg_;
};

class Init_TeamMulticast_sender_id
{
public:
  explicit Init_TeamMulticast_sender_id(::fwp_planner::msg::TeamMulticast & msg)
  : msg_(msg)
  {}
  Init_TeamMulticast_multicast_range sender_id(::fwp_planner::msg::TeamMulticast::_sender_id_type arg)
  {
    msg_.sender_id = std::move(arg);
    return Init_TeamMulticast_multicast_range(msg_);
  }

private:
  ::fwp_planner::msg::TeamMulticast msg_;
};

class Init_TeamMulticast_header
{
public:
  Init_TeamMulticast_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeamMulticast_sender_id header(::fwp_planner::msg::TeamMulticast::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TeamMulticast_sender_id(msg_);
  }

private:
  ::fwp_planner::msg::TeamMulticast msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fwp_planner::msg::TeamMulticast>()
{
  return fwp_planner::msg::builder::Init_TeamMulticast_header();
}

}  // namespace fwp_planner

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__BUILDER_HPP_
