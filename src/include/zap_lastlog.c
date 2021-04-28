#include "zap_lastlog.h"

int open_lastlog(char* name) {
    passwd_t* pwd;
    int f = open_safe(_PATH_LASTLOG, O_RDWR);

    if ((pwd = getpwnam(name)) == NULL) {
        printf("user \"%s\" not found.\n", name);
        exit(1);
    }

    lseek(f, (long)pwd->pw_uid * LLSIZ, SEEK_SET);
    return f;
}

void get_lastlog(lastlog_t* ll, char* name) {
    int f = open_lastlog(name);
    read(f, ll, LLSIZ);
    close(f);
}

void set_lastlog(lastlog_t* ll, char* name) {
    int f = open_lastlog(name);

    if (ll != NULL) write(f, ll, LLSIZ);
    else {
        lastlog_t null_ll;
        memset(&null_ll, 0, LLSIZ);
        write(f, &null_ll, LLSIZ);
    }
    close(f);
}

lastlog_t* modified_lastlog(lastlog_t* ll, utmp_t* latest) {
    /****************************************
    * latest: modified utmp
    * ll    : not modified lastlog
    * if tmp has latest record -> ll := latest
    * else                     -> ll := null
    *****************************************/
    if (latest->ut_time == NO_LATEST_TMP)
        return NULL;
    else {
        strcpy(ll->ll_line, latest->ut_line);
        ll->ll_time = latest->ut_time;
        return ll;
    }
}

void sync_lastlog(char* name, utmp_t* latest) {
    lastlog_t ll;
    get_lastlog(&ll, name);
    set_lastlog(modified_lastlog(&ll, latest), name);
}

void zap_lastlog(char* username, char* username_r, int flag_R) {
    sync_lastlog(username, &latest_user);
    if (flag_R) sync_lastlog(username_r, &latest_user_r);
}
