#ifndef STARBURST_FILESYSTEM_H
#define STARBURST_FILESYSTEM_H

#include <stdbool.h>

#define BUFSIZE 8192

/*
Read a file.

Args: 
    path: The path to the file.
    out: The string to read the file into.
*/
bool sb_fs_read_file_str(const char *path, sb_string_t *out);

#endif // STARBURST_FILESYSTEM_H
