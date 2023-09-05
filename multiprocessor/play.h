#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include "tlpi_hdr.h"

#define dbgl(x) printf("%s => %ld\n",(#x), (x));
#define dbgs(x) printf("%s => \"%s\"\n",(#x), (x));

#define THREAD_NUM 10
