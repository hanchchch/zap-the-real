#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char tmp_file_path[BUFSIZ];

int open_safe(const char* file, int option);
int open_tmp();
void remove_tmp();
void copy_tmp(char* dest);
