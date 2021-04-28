#include "file.h"

int open_safe(const char* file, int option) {
    int f;
    if ((f=open(file, option)) < 0) {
        printf("can not open %s\n", file);
        exit(1);
    }
    return f;
}

int open_tmp() {
    int f;
    tmpnam(tmp_file_path);
    f = open_safe(tmp_file_path, O_RDWR | O_CREAT);
    return f;
}

void remove_tmp() {
    remove(tmp_file_path);
}

void copy_tmp(char* dest) {
    char buf;
    int f;
    int tmp_f;

    f = open_safe(dest, O_WRONLY | O_TRUNC);
    tmp_f = open_safe(tmp_file_path, O_RDONLY);

    while(read(tmp_f, &buf, 1) > 0) write(f, &buf, 1);

    close(tmp_f);
    close(f);
}
