#include "../starburst.h"

int main(void)
{
    sb_string_t resp = {0};
    sb_cstr_arr_t headers = {0};

    sb_https_get("https://ip.ksenon.net", &headers, &resp);

    sb_log("Response: %s\n", resp.items);

    sb_da_free(&resp);
    sb_da_free(&headers);
    
    return 0;
}
