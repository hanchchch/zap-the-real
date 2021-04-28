#include "search.h"

long max_replace_time(long time) {
    if (time < datetime_r) return datetime_r;
    else return time;
}

int is_same(char* one, char* two) {
    if (strlen(one) != strlen(two)) return 0;
    return strncmp(one, two, strlen(one)) == 0;
}

int is_match(char* name, char* line, long time) {
    int name_match=0, term_match=1, date_match=1;
    name_match = is_same(name, username);
    if (flag_t) term_match = strncmp(line, termname, strlen(termname)) == 0;
    if (flag_d) date_match = is_same_day(time, datetime);
    return name_match && term_match && date_match;
}

int replace(char* name, char* line, long* time) {
    int time_value = *time;
    if (flag_R) {
        strncpy(name, username_r, strlen(username_r)+1); // len+1 due to copy null 
        if (flag_t) strncpy(line, termname_r, strlen(termname_r)+1);
        if (flag_d) *time = combine_datetime(datetime_r, time_value); // date from datetime_r, time from utmp_ent
        return 1;
    }
    else return 0;
}
