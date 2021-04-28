#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils/file.h"
#include "utils/option.h"
#include "utils/time.h"

long max_replace_time(long time);
int is_same(char* one, char* two);
int is_match(char* name, char* line, long time);
int replace(char* name, char* line, long* time);
