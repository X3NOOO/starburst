#include <stdio.h>
#include "../starburst.h"

int main(void)
{
    sb_string_t file = { 0 };

    assert(sb_fs_read_file_str(__FILE__, &file));

    sb_str_append_null(&file);

    printf("%s", file.items);

    return 0;
}
