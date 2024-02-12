#ifndef STARBURST_STRING_H
#define STARBURST_STRING_H

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

#endif // STARBURST_STRING_H
