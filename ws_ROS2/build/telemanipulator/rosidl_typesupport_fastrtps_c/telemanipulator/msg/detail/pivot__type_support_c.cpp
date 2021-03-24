// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice
#include "telemanipulator/msg/detail/pivot__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "telemanipulator/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "telemanipulator/msg/detail/pivot__struct.h"
#include "telemanipulator/msg/detail/pivot__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Pivot__ros_msg_type = telemanipulator__msg__Pivot;

static bool _Pivot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Pivot__ros_msg_type * ros_message = static_cast<const _Pivot__ros_msg_type *>(untyped_ros_message);
  // Field name: pan
  {
    cdr << ros_message->pan;
  }

  // Field name: tilt
  {
    cdr << ros_message->tilt;
  }

  // Field name: spin
  {
    cdr << ros_message->spin;
  }

  // Field name: depth
  {
    cdr << ros_message->depth;
  }

  return true;
}

static bool _Pivot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Pivot__ros_msg_type * ros_message = static_cast<_Pivot__ros_msg_type *>(untyped_ros_message);
  // Field name: pan
  {
    cdr >> ros_message->pan;
  }

  // Field name: tilt
  {
    cdr >> ros_message->tilt;
  }

  // Field name: spin
  {
    cdr >> ros_message->spin;
  }

  // Field name: depth
  {
    cdr >> ros_message->depth;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_telemanipulator
size_t get_serialized_size_telemanipulator__msg__Pivot(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Pivot__ros_msg_type * ros_message = static_cast<const _Pivot__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pan
  {
    size_t item_size = sizeof(ros_message->pan);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt
  {
    size_t item_size = sizeof(ros_message->tilt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name spin
  {
    size_t item_size = sizeof(ros_message->spin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name depth
  {
    size_t item_size = sizeof(ros_message->depth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Pivot__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_telemanipulator__msg__Pivot(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_telemanipulator
size_t max_serialized_size_telemanipulator__msg__Pivot(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: pan
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: spin
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: depth
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Pivot__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_telemanipulator__msg__Pivot(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Pivot = {
  "telemanipulator::msg",
  "Pivot",
  _Pivot__cdr_serialize,
  _Pivot__cdr_deserialize,
  _Pivot__get_serialized_size,
  _Pivot__max_serialized_size
};

static rosidl_message_type_support_t _Pivot__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Pivot,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, telemanipulator, msg, Pivot)() {
  return &_Pivot__type_support;
}

#if defined(__cplusplus)
}
#endif
