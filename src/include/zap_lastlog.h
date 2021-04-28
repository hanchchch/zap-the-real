#include "latest.h"

int open_lastlog(char* name);
void get_lastlog(lastlog_t* ll, char* name);
void set_lastlog(lastlog_t* ll, char* name);
lastlog_t* modified_lastlog(lastlog_t* ll, utmp_t* latest);
void sync_lastlog(char* name, utmp_t* latest);
void zap_lastlog(char* username, char* username_r, int flag_R);
