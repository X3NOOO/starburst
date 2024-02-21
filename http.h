#ifndef STARBURST_HTTP_H
#define STARBURST_HTTP_H

#include <curl/curl.h>
#include <stdbool.h>
#include "string.h"

/*
Perform a GET request.

WARNING: depends on libcurl

Args:
    url: The URL to send the request to.
    headers: The headers to send with the request.
    response: The response from the server.

Returns:
    The response code or 0 if curl failed to initialise.
*/
CURLcode sb_https_get(const char *url, const sb_cstr_arr_t *headers, sb_string_t *response);

// bool sb_https_post(const char *url, const char *headers, const char *post_body, sb_string_t *response);

// bool sb_https_raw(const char *url, const char *headers, const char *body, sb_string_t *response);

#endif // STARBURST_HTTP_H
