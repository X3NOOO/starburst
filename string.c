#include <stdbool.h>
#include "string.h"

bool sb_str_starts_with(const sb_string_t *str, const char *prefix)
{
    if (str->count < strlen(prefix))
    {
        return false;
    }

    for (size_t i = 0; i < strlen(prefix); i++)
    {
        if (str->items[i] != prefix[i])
        {
            return false;
        }
    }
    return true;
}

bool sb_str_ends_with(const sb_string_t *str, const char *prefix)
{
    if (str->count < strlen(prefix))
    {
        return false;
    }

    for (size_t i = 0; i < strlen(prefix); i++)
    {
        if (str->items[str->count - strlen(prefix) + i] != prefix[i])
        {
            return false;
        }
    }
    return true;
}
