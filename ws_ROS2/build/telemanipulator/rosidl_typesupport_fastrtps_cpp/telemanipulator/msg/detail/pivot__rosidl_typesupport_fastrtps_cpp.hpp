// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef TELEMANIPULATOR__MSG__DETAIL__PIVOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TELEMANIPULATOR__MSG__DETAIL__PIVOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "telemanipulator/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "telemanipulator/msg/detail/pivot__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace telemanipulator
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
cdr_serialize(
  const telemanipulator::msg::Pivot & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  telemanipulator::msg::Pivot & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
get_serialized_size(
  const telemanipulator::msg::Pivot & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
max_serialized_size_Pivot(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace telemanipulator

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, telemanipulator, msg, Pivot)();

#ifdef __cplusplus
}
#endif

#endif  // TELEMANIPULATOR__MSG__DETAIL__PIVOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
