#if defined(_WIN32) || defined(_WIN64)

#include <stdbool.h>
#include "string.h"
#include "macros.h"
#include "filesystem.h"

bool sb_fs_read_file_str(const char *path, sb_string_t *out)
{
    static_assert(0, "Not implemented");
}

bool sb_fs_ls(const char *path, sb_fs_entry_t *out[]);
{
    static_assert(0, "Not implemented");
}

#endif
