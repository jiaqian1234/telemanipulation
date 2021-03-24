// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice
#include "telemanipulator/msg/detail/pivot__rosidl_typesupport_fastrtps_cpp.hpp"
#include "telemanipulator/msg/detail/pivot__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pan
  cdr << ros_message.pan;
  // Member: tilt
  cdr << ros_message.tilt;
  // Member: spin
  cdr << ros_message.spin;
  // Member: depth
  cdr << ros_message.depth;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  telemanipulator::msg::Pivot & ros_message)
{
  // Member: pan
  cdr >> ros_message.pan;

  // Member: tilt
  cdr >> ros_message.tilt;

  // Member: spin
  cdr >> ros_message.spin;

  // Member: depth
  cdr >> ros_message.depth;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
get_serialized_size(
  const telemanipulator::msg::Pivot & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pan
  {
    size_t item_size = sizeof(ros_message.pan);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt
  {
    size_t item_size = sizeof(ros_message.tilt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: spin
  {
    size_t item_size = sizeof(ros_message.spin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: depth
  {
    size_t item_size = sizeof(ros_message.depth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemanipulator
max_serialized_size_Pivot(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: pan
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: spin
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: depth
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Pivot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const telemanipulator::msg::Pivot *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Pivot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<telemanipulator::msg::Pivot *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Pivot__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const telemanipulator::msg::Pivot *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Pivot__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Pivot(full_bounded, 0);
}

static message_type_support_callbacks_t _Pivot__callbacks = {
  "telemanipulator::msg",
  "Pivot",
  _Pivot__cdr_serialize,
  _Pivot__cdr_deserialize,
  _Pivot__get_serialized_size,
  _Pivot__max_serialized_size
};

static rosidl_message_type_support_t _Pivot__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Pivot__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace telemanipulator

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_telemanipulator
const rosidl_message_type_support_t *
get_message_type_support_handle<telemanipulator::msg::Pivot>()
{
  return &telemanipulator::msg::typesupport_fastrtps_cpp::_Pivot__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, telemanipulator, msg, Pivot)() {
  return &telemanipulator::msg::typesupport_fastrtps_cpp::_Pivot__handle;
}

#ifdef __cplusplus
}
#endif
