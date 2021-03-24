// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pivot_msg:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef PIVOT_MSG__MSG__DETAIL__PIVOT__BUILDER_HPP_
#define PIVOT_MSG__MSG__DETAIL__PIVOT__BUILDER_HPP_

#include "pivot_msg/msg/detail/pivot__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace pivot_msg
{

namespace msg
{

namespace builder
{

class Init_Pivot_depth
{
public:
  explicit Init_Pivot_depth(::pivot_msg::msg::Pivot & msg)
  : msg_(msg)
  {}
  ::pivot_msg::msg::Pivot depth(::pivot_msg::msg::Pivot::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pivot_msg::msg::Pivot msg_;
};

class Init_Pivot_spin
{
public:
  explicit Init_Pivot_spin(::pivot_msg::msg::Pivot & msg)
  : msg_(msg)
  {}
  Init_Pivot_depth spin(::pivot_msg::msg::Pivot::_spin_type arg)
  {
    msg_.spin = std::move(arg);
    return Init_Pivot_depth(msg_);
  }

private:
  ::pivot_msg::msg::Pivot msg_;
};

class Init_Pivot_tilt
{
public:
  explicit Init_Pivot_tilt(::pivot_msg::msg::Pivot & msg)
  : msg_(msg)
  {}
  Init_Pivot_spin tilt(::pivot_msg::msg::Pivot::_tilt_type arg)
  {
    msg_.tilt = std::move(arg);
    return Init_Pivot_spin(msg_);
  }

private:
  ::pivot_msg::msg::Pivot msg_;
};

class Init_Pivot_pan
{
public:
  Init_Pivot_pan()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pivot_tilt pan(::pivot_msg::msg::Pivot::_pan_type arg)
  {
    msg_.pan = std::move(arg);
    return Init_Pivot_tilt(msg_);
  }

private:
  ::pivot_msg::msg::Pivot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pivot_msg::msg::Pivot>()
{
  return pivot_msg::msg::builder::Init_Pivot_pan();
}

}  // namespace pivot_msg

#endif  // PIVOT_MSG__MSG__DETAIL__PIVOT__BUILDER_HPP_
