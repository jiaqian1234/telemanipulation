// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef TELEMANIPULATOR__MSG__DETAIL__PIVOT__BUILDER_HPP_
#define TELEMANIPULATOR__MSG__DETAIL__PIVOT__BUILDER_HPP_

#include "telemanipulator/msg/detail/pivot__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace telemanipulator
{

namespace msg
{

namespace builder
{

class Init_Pivot_depth
{
public:
  explicit Init_Pivot_depth(::telemanipulator::msg::Pivot & msg)
  : msg_(msg)
  {}
  ::telemanipulator::msg::Pivot depth(::telemanipulator::msg::Pivot::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::telemanipulator::msg::Pivot msg_;
};

class Init_Pivot_spin
{
public:
  explicit Init_Pivot_spin(::telemanipulator::msg::Pivot & msg)
  : msg_(msg)
  {}
  Init_Pivot_depth spin(::telemanipulator::msg::Pivot::_spin_type arg)
  {
    msg_.spin = std::move(arg);
    return Init_Pivot_depth(msg_);
  }

private:
  ::telemanipulator::msg::Pivot msg_;
};

class Init_Pivot_tilt
{
public:
  explicit Init_Pivot_tilt(::telemanipulator::msg::Pivot & msg)
  : msg_(msg)
  {}
  Init_Pivot_spin tilt(::telemanipulator::msg::Pivot::_tilt_type arg)
  {
    msg_.tilt = std::move(arg);
    return Init_Pivot_spin(msg_);
  }

private:
  ::telemanipulator::msg::Pivot msg_;
};

class Init_Pivot_pan
{
public:
  Init_Pivot_pan()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pivot_tilt pan(::telemanipulator::msg::Pivot::_pan_type arg)
  {
    msg_.pan = std::move(arg);
    return Init_Pivot_tilt(msg_);
  }

private:
  ::telemanipulator::msg::Pivot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::telemanipulator::msg::Pivot>()
{
  return telemanipulator::msg::builder::Init_Pivot_pan();
}

}  // namespace telemanipulator

#endif  // TELEMANIPULATOR__MSG__DETAIL__PIVOT__BUILDER_HPP_
