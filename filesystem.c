#include <stdbool.h>
#include "string.h"
#include "macros.h"
#include "filesystem.h"

bool sb_fs_read_file_str(const char *path, sb_string_t *out) {
    FILE * fp = fopen(path, "r");
    if (fp == NULL) {
        return false;
    }

    typeof(*out->items) * tmp_buf = malloc(sizeof(typeof(*out->items)) * BUFSIZE);
    
    while (0 < fread(tmp_buf, sizeof(*(out->items)), BUFSIZE, fp)) {
        sb_da_push_array(out, tmp_buf, BUFSIZE);
    }

    free(tmp_buf);

    return !(fclose(fp));
}
