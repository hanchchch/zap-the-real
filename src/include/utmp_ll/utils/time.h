#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tm tm_t;

long date_str2long(char* src);
int is_same_day(long ts1, long ts2);
long combine_datetime(long date, long time);