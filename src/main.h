#include "include/zap_tmp.h"
#include "include/zap_lastlog.h"

extern char username[64];
extern char username_r[64];
extern char termname[64];
extern char termname_r[64];
extern long datetime;
extern long datetime_r;
extern int flag_A=0;
extern int flag_a=0;
extern int flag_R=0;
extern int flag_t=0;
extern int flag_d=0;
extern char tmp_file_path[BUFSIZ];

void zap();
