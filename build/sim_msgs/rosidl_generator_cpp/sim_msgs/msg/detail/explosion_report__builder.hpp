// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sim_msgs:msg/ExplosionReport.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__BUILDER_HPP_
#define SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sim_msgs/msg/detail/explosion_report__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sim_msgs
{

namespace msg
{

namespace builder
{

class Init_ExplosionReport_exp_range
{
public:
  explicit Init_ExplosionReport_exp_range(::sim_msgs::msg::ExplosionReport & msg)
  : msg_(msg)
  {}
  ::sim_msgs::msg::ExplosionReport exp_range(::sim_msgs::msg::ExplosionReport::_exp_range_type arg)
  {
    msg_.exp_range = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sim_msgs::msg::ExplosionReport msg_;
};

class Init_ExplosionReport_exp_center
{
public:
  explicit Init_ExplosionReport_exp_center(::sim_msgs::msg::ExplosionReport & msg)
  : msg_(msg)
  {}
  Init_ExplosionReport_exp_range exp_center(::sim_msgs::msg::ExplosionReport::_exp_center_type arg)
  {
    msg_.exp_center = std::move(arg);
    return Init_ExplosionReport_exp_range(msg_);
  }

private:
  ::sim_msgs::msg::ExplosionReport msg_;
};

class Init_ExplosionReport_attacker_id
{
public:
  explicit Init_ExplosionReport_attacker_id(::sim_msgs::msg::ExplosionReport & msg)
  : msg_(msg)
  {}
  Init_ExplosionReport_exp_center attacker_id(::sim_msgs::msg::ExplosionReport::_attacker_id_type arg)
  {
    msg_.attacker_id = std::move(arg);
    return Init_ExplosionReport_exp_center(msg_);
  }

private:
  ::sim_msgs::msg::ExplosionReport msg_;
};

class Init_ExplosionReport_header
{
public:
  Init_ExplosionReport_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExplosionReport_attacker_id header(::sim_msgs::msg::ExplosionReport::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ExplosionReport_attacker_id(msg_);
  }

private:
  ::sim_msgs::msg::ExplosionReport msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sim_msgs::msg::ExplosionReport>()
{
  return sim_msgs::msg::builder::Init_ExplosionReport_header();
}

}  // namespace sim_msgs

#endif  // SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__BUILDER_HPP_
