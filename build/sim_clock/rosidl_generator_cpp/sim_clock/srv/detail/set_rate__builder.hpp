// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sim_clock:srv/SetRate.idl
// generated code does not contain a copyright notice

#ifndef SIM_CLOCK__SRV__DETAIL__SET_RATE__BUILDER_HPP_
#define SIM_CLOCK__SRV__DETAIL__SET_RATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sim_clock/srv/detail/set_rate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sim_clock
{

namespace srv
{

namespace builder
{

class Init_SetRate_Request_rate
{
public:
  Init_SetRate_Request_rate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sim_clock::srv::SetRate_Request rate(::sim_clock::srv::SetRate_Request::_rate_type arg)
  {
    msg_.rate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sim_clock::srv::SetRate_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sim_clock::srv::SetRate_Request>()
{
  return sim_clock::srv::builder::Init_SetRate_Request_rate();
}

}  // namespace sim_clock


namespace sim_clock
{

namespace srv
{

namespace builder
{

class Init_SetRate_Response_message
{
public:
  explicit Init_SetRate_Response_message(::sim_clock::srv::SetRate_Response & msg)
  : msg_(msg)
  {}
  ::sim_clock::srv::SetRate_Response message(::sim_clock::srv::SetRate_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sim_clock::srv::SetRate_Response msg_;
};

class Init_SetRate_Response_success
{
public:
  Init_SetRate_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetRate_Response_message success(::sim_clock::srv::SetRate_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetRate_Response_message(msg_);
  }

private:
  ::sim_clock::srv::SetRate_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sim_clock::srv::SetRate_Response>()
{
  return sim_clock::srv::builder::Init_SetRate_Response_success();
}

}  // namespace sim_clock

#endif  // SIM_CLOCK__SRV__DETAIL__SET_RATE__BUILDER_HPP_
