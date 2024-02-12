#ifndef STARBURST_MACROS_H
#define STARBURST_MACROS_H

/*
Returns how many elements can the array fit.

Args:
    arr: array to check
*/
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

/*
Checks if a value is of a certain type.

Args:
    a: The value to check.
    type: The type to check against.
*/
#define SB_M_IS_TYPE(a, type) _Generic((a), type: 1, default: 0)

#if defined(__GNUC__)
/*
Check if the variables are of the same type.

Args:
    a: The first variable.
    b: The second variable.
*/
#define SB_M_ARE_SAME_TYPE(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))
#elif
/*
Check if the variables are of the same type.

WARNING: Macro this function is dependend on is not suported yby your compiler. This function will always return true.
*/
#define SB_M_ARE_SAME_TYPE(a, b) true; /* Your compiler does not support the needed extension */
#endif // defined(__GNUC__)

#endif // STARBURST_MACROS_H
