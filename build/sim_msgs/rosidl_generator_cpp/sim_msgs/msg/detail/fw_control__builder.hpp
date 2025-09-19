// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__FW_CONTROL__BUILDER_HPP_
#define SIM_MSGS__MSG__DETAIL__FW_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sim_msgs/msg/detail/fw_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sim_msgs
{

namespace msg
{

namespace builder
{

class Init_FwControl_desired_airspeed
{
public:
  explicit Init_FwControl_desired_airspeed(::sim_msgs::msg::FwControl & msg)
  : msg_(msg)
  {}
  ::sim_msgs::msg::FwControl desired_airspeed(::sim_msgs::msg::FwControl::_desired_airspeed_type arg)
  {
    msg_.desired_airspeed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sim_msgs::msg::FwControl msg_;
};

class Init_FwControl_desired_yaw_rate
{
public:
  explicit Init_FwControl_desired_yaw_rate(::sim_msgs::msg::FwControl & msg)
  : msg_(msg)
  {}
  Init_FwControl_desired_airspeed desired_yaw_rate(::sim_msgs::msg::FwControl::_desired_yaw_rate_type arg)
  {
    msg_.desired_yaw_rate = std::move(arg);
    return Init_FwControl_desired_airspeed(msg_);
  }

private:
  ::sim_msgs::msg::FwControl msg_;
};

class Init_FwControl_desired_pitch
{
public:
  explicit Init_FwControl_desired_pitch(::sim_msgs::msg::FwControl & msg)
  : msg_(msg)
  {}
  Init_FwControl_desired_yaw_rate desired_pitch(::sim_msgs::msg::FwControl::_desired_pitch_type arg)
  {
    msg_.desired_pitch = std::move(arg);
    return Init_FwControl_desired_yaw_rate(msg_);
  }

private:
  ::sim_msgs::msg::FwControl msg_;
};

class Init_FwControl_desired_roll
{
public:
  Init_FwControl_desired_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FwControl_desired_pitch desired_roll(::sim_msgs::msg::FwControl::_desired_roll_type arg)
  {
    msg_.desired_roll = std::move(arg);
    return Init_FwControl_desired_pitch(msg_);
  }

private:
  ::sim_msgs::msg::FwControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sim_msgs::msg::FwControl>()
{
  return sim_msgs::msg::builder::Init_FwControl_desired_roll();
}

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__FW_CONTROL__BUILDER_HPP_
