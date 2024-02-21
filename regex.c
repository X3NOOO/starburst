#define PCRE2_CODE_UNIT_WIDTH 8

#include <pcre2.h>
#include "dynamic_array.h"
#include "regex.h"

bool sb_re_match(const char *pattern, const char *text, sb_str_arr_t *matches)
{
    int errorcode;
    PCRE2_SIZE erroffset;
    pcre2_code *re;
    pcre2_match_data *match_data;
    int rc;

    re = pcre2_compile((PCRE2_SPTR)pattern, PCRE2_ZERO_TERMINATED, 0, &errorcode, &erroffset, NULL);
    if (re == NULL)
        return false;

    match_data = pcre2_match_data_create_from_pattern(re, NULL);

    rc = pcre2_match(re, (PCRE2_SPTR)text, PCRE2_ZERO_TERMINATED, 0, 0, match_data, NULL);

    PCRE2_SIZE offset = 0;
    while ((rc = pcre2_match(re, (PCRE2_SPTR)text, PCRE2_ZERO_TERMINATED, offset, 0, match_data, NULL)) >= 0)
    {
        if (rc == 0)
            rc = 1;

        PCRE2_SIZE *ovector = pcre2_get_ovector_pointer(match_data);
        for (int i = 0; i < rc; i++)
        {
            PCRE2_SIZE start = ovector[2 * i];
            PCRE2_SIZE end = ovector[2 * i + 1];

            size_t len = end - start;
            char *match = malloc((len + 1) * sizeof(char));
            strncpy(match, text + start, len);
            match[len] = '\0';

            sb_string_t entry = {0};
            sb_da_push_array(&entry, match, len);
            sb_da_push(matches, entry);
        }
        offset = ovector[1];
    }

    if (rc < 0 && rc != PCRE2_ERROR_NOMATCH)
        return false;

    pcre2_match_data_free(match_data);
    pcre2_code_free(re);

    return true;
}
