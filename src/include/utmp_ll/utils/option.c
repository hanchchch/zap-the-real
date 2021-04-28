#include "option.h"
#include "time.h"

void usage(char* proc) {
    puts("usage:");
    printf("\t%s -A username\n", proc);
    printf("\t%s -a username -t tty -d mmddyy\n", proc);
    printf("\t%s -R username1 username2 -t tty1 tty2 -d mmddyy1 mmddyy2\n", proc);
    exit(1);
}

void get2params(int argc, char* argv[], char* buf1, char* buf2) {
    if (argv[optind-1][0] == '-' || argv[optind][0] == '-') {
        printf("%s: invalid argument -- %s requires 2 parameters.\n", argv[0], argv[optind-2]);
        exit(1);
    }
    optind--;
    memcpy(buf1, argv[optind], strlen(argv[optind]));
    optind++;
    memcpy(buf2, argv[optind], strlen(argv[optind]));
    optind++;
}

void get_opt(int argc, char* argv[]) {
    int c;
    flag_A = 0;
    flag_a = 0;
    flag_R = 0;
    flag_t = 0;
    flag_d = 0;
    char datebuf[32];
    char datebuf_r[32];
    while ((c=getopt(argc, argv, "A:a:R:t:d:")) != -1) {
        switch(c) {
            case 'A':
                flag_A = 1;
                memcpy(username, optarg, strlen(optarg));
                break;
            
            case 'a':
                flag_a = 1;
                memcpy(username, optarg, strlen(optarg));
                break;
            
            case 'R':
                flag_R = 1;
                get2params(argc, argv, username, username_r);
                break;

            case 't':
                flag_t = 1;
                if (flag_R) get2params(argc, argv, termname, termname_r);
                else memcpy(termname, optarg, strlen(optarg));
                break;
            
            case 'd':
                flag_d = 1;
                if (flag_R) get2params(argc, argv, datebuf, datebuf_r);
                else memcpy(datebuf, optarg, strlen(optarg));
                break;
        }
    }
    if (flag_d) {
        datetime = date_str2long(datebuf);
        if (flag_R) datetime_r = date_str2long(datebuf_r);
    }
}
