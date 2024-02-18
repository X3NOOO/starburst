#ifndef STARBURST_FILESYSTEM_H
#define STARBURST_FILESYSTEM_H

#include <stdbool.h>
#include <sys/stat.h>

#define BUFSIZE 8192

typedef struct
{
    sb_string_t name;
    struct stat st;
} sb_fs_entry_t;

sb_da_construct_type(sb_fs_entries_t, sb_fs_entry_t);

/*
Read a file.

Args:
    path: The path to the file.
    out: The string to read the file into.
*/
bool sb_fs_read_file_str(const char *path, sb_string_t *out);

/*
Get the list of files in a directory. If the list of files has elements already in it, new elements are gonna be appended.

Args:
    path: The path to the directory.
    out: Array of paths to the files in the directory.
*/
bool sb_fs_ls(const char *path, sb_fs_entries_t *out);

#endif // STARBURST_FILESYSTEM_H
