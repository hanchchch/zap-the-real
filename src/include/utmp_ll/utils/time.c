#include "time.h"

long date_str2long(char* src) {
    tm_t* tm;
    long tmp;
    char month[3] = { src[0], src[1], 0 };
    char day[3] = { src[2], src[3], 0 };
    char year[5] = { '2', '0', src[4], src[5], 0 };

    time(&tmp);
    tm = localtime(&tmp);
    tm->tm_year = atoi(year) - 1900;
    tm->tm_mon = atoi(month) - 1;
    tm->tm_mday = atoi(day);

    return mktime(tm);
}

int is_same_day(long ts1, long ts2) {
    long _ts1 = ts1;
    long _ts2 = ts2;
    tm_t tm1;
    tm_t tm2;

    localtime_r(&_ts1, &tm1);
    localtime_r(&_ts2, &tm2);

    if (tm1.tm_year != tm2.tm_year) return 0;
    if (tm1.tm_mon != tm2.tm_mon) return 0;
    if (tm1.tm_mday != tm2.tm_mday) return 0;

    return 1;
}

long combine_datetime(long date, long time) {
    long _date = date;
    long _time = time;
    tm_t tm;
    tm_t tm_date;

    localtime_r(&_time, &tm);
    localtime_r(&_date, &tm_date);

    tm.tm_year = tm_date.tm_year;
    tm.tm_mon = tm_date.tm_mon;
    tm.tm_mday = tm_date.tm_mday;

    return mktime(&tm);
}
