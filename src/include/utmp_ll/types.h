#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>
#include <pwd.h>

#define UTMPSIZ sizeof(struct utmp)
#define LLSIZ sizeof(struct lastlog)

typedef struct utmp utmp_t;
typedef struct passwd passwd_t;
typedef struct lastlog lastlog_t;
