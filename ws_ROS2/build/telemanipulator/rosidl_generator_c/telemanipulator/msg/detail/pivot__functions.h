// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef TELEMANIPULATOR__MSG__DETAIL__PIVOT__FUNCTIONS_H_
#define TELEMANIPULATOR__MSG__DETAIL__PIVOT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "telemanipulator/msg/rosidl_generator_c__visibility_control.h"

#include "telemanipulator/msg/detail/pivot__struct.h"

/// Initialize msg/Pivot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * telemanipulator__msg__Pivot
 * )) before or use
 * telemanipulator__msg__Pivot__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
bool
telemanipulator__msg__Pivot__init(telemanipulator__msg__Pivot * msg);

/// Finalize msg/Pivot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
void
telemanipulator__msg__Pivot__fini(telemanipulator__msg__Pivot * msg);

/// Create msg/Pivot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * telemanipulator__msg__Pivot__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
telemanipulator__msg__Pivot *
telemanipulator__msg__Pivot__create();

/// Destroy msg/Pivot message.
/**
 * It calls
 * telemanipulator__msg__Pivot__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
void
telemanipulator__msg__Pivot__destroy(telemanipulator__msg__Pivot * msg);


/// Initialize array of msg/Pivot messages.
/**
 * It allocates the memory for the number of elements and calls
 * telemanipulator__msg__Pivot__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
bool
telemanipulator__msg__Pivot__Sequence__init(telemanipulator__msg__Pivot__Sequence * array, size_t size);

/// Finalize array of msg/Pivot messages.
/**
 * It calls
 * telemanipulator__msg__Pivot__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
void
telemanipulator__msg__Pivot__Sequence__fini(telemanipulator__msg__Pivot__Sequence * array);

/// Create array of msg/Pivot messages.
/**
 * It allocates the memory for the array and calls
 * telemanipulator__msg__Pivot__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
telemanipulator__msg__Pivot__Sequence *
telemanipulator__msg__Pivot__Sequence__create(size_t size);

/// Destroy array of msg/Pivot messages.
/**
 * It calls
 * telemanipulator__msg__Pivot__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemanipulator
void
telemanipulator__msg__Pivot__Sequence__destroy(telemanipulator__msg__Pivot__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // TELEMANIPULATOR__MSG__DETAIL__PIVOT__FUNCTIONS_H_
