#ifndef STARBURST_LOG_H
#define STARBURST_LOG_H

#include <stdio.h>
#include <time.h>

#define loglevel stderr

#define sb_log(...)                                                                                          \
    do                                                                                                       \
    {                                                                                                        \
        time_t rt;                                                                                           \
        struct tm *t;                                                                                        \
        time(&rt);                                                                                           \
        t = localtime(&rt);                                                                                  \
                                                                                                             \
        fprintf(loglevel, "%s:%d [%02d:%02d:%02d]: ", __FILE__, __LINE__, t->tm_hour, t->tm_min, t->tm_sec); \
        fprintf(loglevel, __VA_ARGS__);                                                                      \
    } while (0)

#endif // STARBURST_LOG_H
