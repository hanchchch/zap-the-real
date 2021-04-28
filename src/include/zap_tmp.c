#include "zap_tmp.h"

int compare(const void* a, const void* b) {
    printf("%d ", (*(utmp_t**)a)->ut_time);
    if ((*(utmp_t**)a)->ut_time > (*(utmp_t**)b)->ut_time) return 1;
    else if ((*(utmp_t**)a)->ut_time < (*(utmp_t**)b)->ut_time) return -1;
    else return 0;
}

void append_utmp_array(utmp_t* element) {
    utmp_array[utmp_idx] = (utmp_t*)malloc(UTMPSIZ);
    memcpy(utmp_array[utmp_idx], element, UTMPSIZ);
    utmp_idx++;
}

void get_utmp_array(char* path) {
    utmp_t utmp_ent;
    int f;
    
    f = open_safe(path, O_RDWR);

    utmp_idx = 0;
    while(read(f, &utmp_ent, UTMPSIZ) > 0) {
        if (is_match(utmp_ent.ut_name, utmp_ent.ut_line, utmp_ent.ut_time)) {
            if (replace(utmp_ent.ut_name, utmp_ent.ut_line, &utmp_ent.ut_time)) // if replaced utmp_ent
                append_utmp_array(&utmp_ent); // then write on tmp file
            else continue; // else write nothing (and do not update latest)
        }
        else append_utmp_array(&utmp_ent); // not match -> write original utmp_ent
    }

    close(f);
}

void sort_and_write(char* path) {
    int tmp_f;
    tmp_f = open_tmp();

    qsort(utmp_array, utmp_idx, sizeof(utmp_t*), compare);

    for (int i=0; i<utmp_idx; i++) {
        write(tmp_f, utmp_array[i], UTMPSIZ);
        free(utmp_array[i]);
    }

    close(tmp_f);

    copy_tmp(path);
}

void zap_tmp(char* path, char* username, char* username_r, int flag_R) {
    get_utmp_array(path);

    sort_and_write(path);

    update_latest(&latest_user, path, username);
    update_latest(&latest_user_r, path, username_r);
}
