// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from pivot_msg:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef PIVOT_MSG__MSG__DETAIL__PIVOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PIVOT_MSG__MSG__DETAIL__PIVOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pivot_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "pivot_msg/msg/detail/pivot__struct.hpp"

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

namespace pivot_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pivot_msg
cdr_serialize(
  const pivot_msg::msg::Pivot & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pivot_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pivot_msg::msg::Pivot & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pivot_msg
get_serialized_size(
  const pivot_msg::msg::Pivot & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pivot_msg
max_serialized_size_Pivot(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pivot_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pivot_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pivot_msg, msg, Pivot)();

#ifdef __cplusplus
}
#endif

#endif  // PIVOT_MSG__MSG__DETAIL__PIVOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
