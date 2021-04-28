#include "utmp_ll/types.h"
#include "utmp_ll/search.h"

#define NO_LATEST_TMP 0

utmp_t latest_user;
utmp_t latest_user_r;

void update_latest(utmp_t* latest, char* path, char* username);
int is_latest_modified(lastlog_t* ll, utmp_t* latest);
