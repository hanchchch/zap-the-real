#include "latest.h"

utmp_t* utmp_array[BUFSIZ];
int utmp_idx;

int compare(const void* a, const void* b);
void append_utmp_array(utmp_t* element);
void get_utmp_array(char* path);
void sort_and_write(char* path);
void zap_tmp(char* path, char* username, char* username_r, int flag_R);
