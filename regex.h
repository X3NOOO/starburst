#ifndef STARBURST_REGEX_H
#define STARBURST_REGEX_H

#define PCRE2_CODE_UNIT_WIDTH 8

#include "./dynamic_array.h"
#include "./string.h"

sb_da_construct_type(sb_str_arr_t, sb_string_t);

/*
Match regex pattern to text.

WARNING: Depends on pcre2

Args:
    pattern: The regex pattern to match.
    text: The text to match against.
    matches: The array to store matches in.
*/
bool sb_re_match(const char *pattern, const char *text, sb_str_arr_t *matches);

#endif // STARBURST_REGEX_H
