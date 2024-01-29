#include <stdio.h>
#include "../starburst.h"

sb_da_construct_type(da_t, int);

void sb_da_print(da_t *da, FILE *output)
{
    fprintf(output, "[");
    for (size_t i = 0; i < (da)->count; i++)
    {
        fprintf(output, "%s", (i == 0) ? "" : ", ");
        fprintf(output, "%d", (da)->items[i]);
    }
    fprintf(output, "]");
}

int main(void)
{
    da_t da = {0};

    for (int i = 0; i < 10; i++)
    {
        sb_da_push(&da, i);
    }
    sb_da_print(&da, stdout);

    int arr[] = {10, 11, 12};
    sb_da_push_array(&da, arr, sizeof(arr) / sizeof(*arr));
    sb_da_print(&da, stdout);

    sb_da_pop_multiple(&da, 3);
    sb_da_print(&da, stdout);

    sb_da_free(&da);

    return 0;
}
