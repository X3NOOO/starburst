#ifndef STARBURST_STRING_H
#define STARBURST_STRING_H

#include <stdbool.h>
#include "dynamic_array.h"

sb_da_construct_type(sb_string_t, char);

/*
Append a null character to the end of the string.

Args:
    str: The string to append to.
*/
#define sb_str_append_null(str) sb_da_push(str, '\0')

/*
Removes null characters from the end of a string.

Args:
    str: The string to remove null characters from.
*/
#define sb_str_remove_null(str) while ((str)->items[(str)->count-1] == '\0') sb_da_pop(str);

/*
Checks if string starts with a certain string.

Args:
    str: The string to check.
    prefix: The string to check against.
*/
bool sb_str_starts_with(const sb_string_t *str, const char *prefix);

/*
Checks if string ends with a certain string.

Args:
    str: The string to check.
    suffix: The string to check against.
*/
bool sb_str_ends_with(const sb_string_t *str, const char *suffix);

#endif // STARBURST_STRING_H
