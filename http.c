#include <stdbool.h>
#include <curl/curl.h>
#include "dynamic_array.h"
#include "string.h"
#include "http.h"

size_t write_callback(char *ptr, size_t size, size_t nmemb, sb_string_t *resp)
{
    size_t datasize = size * nmemb;

    sb_da_push_array(resp, ptr, datasize);

    return datasize;
}

CURLcode sb_https_get(const char *url, const sb_cstr_arr_t *headers, sb_string_t *response)
{
    CURL *curl = curl_easy_init();
    if (!curl)
        return 0;

    struct curl_slist *hlist = NULL;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

    if (headers != NULL && headers->count > 0)
    {
        for (size_t i = 0; i < headers->count; i++)
            curl_slist_append(hlist, headers->items[i]);

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hlist);
    }

    CURLcode res = curl_easy_perform(curl);
    sb_str_append_null(response);

    curl_easy_cleanup(curl);
    curl_slist_free_all(hlist);

    return res;
}

bool sb_https_post(const char *url, const char *headers, const char *post_body, sb_string_t *response)
{
    assert(false && "Not implemented");
}

bool sb_https_raw(const char *url, const char *headers, const char *body, sb_string_t *response)
{
    assert(false && "Not implemented");
}
