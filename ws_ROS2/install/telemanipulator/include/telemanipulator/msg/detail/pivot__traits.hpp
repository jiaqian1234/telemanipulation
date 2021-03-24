// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef TELEMANIPULATOR__MSG__DETAIL__PIVOT__TRAITS_HPP_
#define TELEMANIPULATOR__MSG__DETAIL__PIVOT__TRAITS_HPP_

#include "telemanipulator/msg/detail/pivot__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<telemanipulator::msg::Pivot>()
{
  return "telemanipulator::msg::Pivot";
}

template<>
inline const char * name<telemanipulator::msg::Pivot>()
{
  return "telemanipulator/msg/Pivot";
}

template<>
struct has_fixed_size<telemanipulator::msg::Pivot>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<telemanipulator::msg::Pivot>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<telemanipulator::msg::Pivot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TELEMANIPULATOR__MSG__DETAIL__PIVOT__TRAITS_HPP_
