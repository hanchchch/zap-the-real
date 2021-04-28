#include "main.h"

void zap() {
    zap_tmp(_PATH_UTMP, username, username_r, flag_R);
    zap_tmp(_PATH_WTMP, username, username_r, flag_R);
    zap_lastlog(username, username_r, flag_R);
}

int main(int argc, char* argv[]) {
    get_opt(argc, argv);

    if (!(flag_A || flag_a || flag_R)) {
        usage(argv[0]);
    }

    zap();

    puts("Zap!");

    return 0;
}