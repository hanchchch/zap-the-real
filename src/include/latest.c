#include "latest.h"

void update_latest(utmp_t* latest, char* path, char* name) {
    utmp_t utmp_ent;
    int f;
    
    f = open_safe(path, O_RDONLY);

    latest->ut_time = NO_LATEST_TMP;

    while(read(f, &utmp_ent, UTMPSIZ) > 0) {
        if (is_same(utmp_ent.ut_name, name)) {
            if (utmp_ent.ut_time > latest->ut_time) memcpy(latest, &utmp_ent, UTMPSIZ);
        }
    }

    close(f);
}

int is_latest_modified(lastlog_t* ll, utmp_t* latest) {
    return (ll->ll_time >= latest->ut_time);
}
