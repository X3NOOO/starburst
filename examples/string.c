#include <stdio.h>
#include "../starburst.h"

int main(void)
{
    sb_string_t str = {0};
    sb_da_push_array(&str, "Hello, World!", strlen("Hello, World!"));

    sb_str_append_null(&str);
    sb_str_remove_null(&str);

    printf("String: %s\n", str.items);

    if (sb_str_starts_with(&str, "Hello"))
    {
        printf("String starts with 'Hello'\n");
    }

    if (sb_str_ends_with(&str, "World!"))
    {
        printf("String ends with 'World!'\n");
    }

    sb_da_free(&str);

    return 0;
}