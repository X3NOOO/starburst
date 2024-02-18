#include <stdio.h>
#include "../starburst.h"

void test_readfile(void)
{
    sb_string_t file = {0};

    assert(sb_fs_read_file_str(__FILE__, &file));

    sb_str_append_null(&file);

    printf("%s", file.items);

    sb_da_free(&file);
}

void test_ls(void)
{
    sb_fs_entries_t entries = {0};

    assert(sb_fs_ls(".", &entries));

    for (size_t i = 0; i < entries.count; i++)
    {
        printf("%s\n", entries.items[i].name.items);
        sb_da_free(&entries.items[i].name);
    }

    sb_da_free(&entries);
}

int main(void)
{
    test_readfile();
    test_ls();

    return 0;
}
