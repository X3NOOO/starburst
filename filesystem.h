#ifndef STARBURST_FILESYSTEM_H
#define STARBURST_FILESYSTEM_H
#include <stdbool.h>

#define BUFSIZE 8192

bool sb_fs_read_file_str(const char *path, sb_string_t *out);

#endif // STARBURST_FILESYSTEM_H
