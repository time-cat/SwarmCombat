// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sim_msgs:msg/DeathNotice.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__BUILDER_HPP_
#define SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sim_msgs/msg/detail/death_notice__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sim_msgs
{

namespace msg
{

namespace builder
{

class Init_DeathNotice_death
{
public:
  explicit Init_DeathNotice_death(::sim_msgs::msg::DeathNotice & msg)
  : msg_(msg)
  {}
  ::sim_msgs::msg::DeathNotice death(::sim_msgs::msg::DeathNotice::_death_type arg)
  {
    msg_.death = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sim_msgs::msg::DeathNotice msg_;
};

class Init_DeathNotice_header
{
public:
  Init_DeathNotice_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeathNotice_death header(::sim_msgs::msg::DeathNotice::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DeathNotice_death(msg_);
  }

private:
  ::sim_msgs::msg::DeathNotice msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sim_msgs::msg::DeathNotice>()
{
  return sim_msgs::msg::builder::Init_DeathNotice_header();
}

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__BUILDER_HPP_
