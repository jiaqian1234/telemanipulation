// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pivot_msg:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef PIVOT_MSG__MSG__DETAIL__PIVOT__TRAITS_HPP_
#define PIVOT_MSG__MSG__DETAIL__PIVOT__TRAITS_HPP_

#include "pivot_msg/msg/detail/pivot__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<pivot_msg::msg::Pivot>()
{
  return "pivot_msg::msg::Pivot";
}

template<>
inline const char * name<pivot_msg::msg::Pivot>()
{
  return "pivot_msg/msg/Pivot";
}

template<>
struct has_fixed_size<pivot_msg::msg::Pivot>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pivot_msg::msg::Pivot>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pivot_msg::msg::Pivot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PIVOT_MSG__MSG__DETAIL__PIVOT__TRAITS_HPP_
