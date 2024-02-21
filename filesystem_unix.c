#ifdef __unix__

#include <stdbool.h>
#include <dirent.h>
#include "string.h"
#include "macros.h"
#include "filesystem.h"
#include "dynamic_array.h"

bool sb_fs_read_file_str(const char *path, sb_string_t *out)
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        return false;
    }

    typeof(*out->items) *tmp_buf = malloc(sizeof(typeof(*out->items)) * BUFSIZE);

    while (0 < fread(tmp_buf, sizeof(*(out->items)), BUFSIZE, fp))
    {
        sb_da_push_array(out, tmp_buf, BUFSIZE);
    }

    free(tmp_buf);

    return fclose(fp);
}

bool sb_fs_ls(const char *path, sb_fs_entries_t *out)
{
    DIR *dir;
    struct dirent *ent;

    dir = opendir(path);

    if (dir == NULL)
    {
        return false;
    }

    size_t i = out->count;
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
        {
            continue;
        }

        sb_fs_entry_t entry = {0};
        sb_da_push_array(&entry.name, ent->d_name, strlen(ent->d_name) + 1);

        sb_da_push(out, entry);

        stat(ent->d_name, &out->items[i].st);
        i++;
    }

    closedir(dir);
    return true;
}

#endif
