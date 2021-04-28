#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char username[64];
char username_r[64];
char termname[64];
char termname_r[64];
long datetime;
long datetime_r;
int flag_A;
int flag_a;
int flag_R;
int flag_t;
int flag_d;

void usage(char* proc);
void get2params(int argc, char* argv[], char* buf1, char* buf2);
void get_opt(int argc, char* argv[]);
