#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <assert.h>
#include "tlpi_hdr.h"

#define lenof(a) (sizeof(a) / sizeof(a[0]))
#define dbgl(x) printf("%s => %ld\n",(#x), (x));
#define dbgi(x) printf("%s => %d\n",(#x), (x));
#define dbgs(x) printf("%s => \"%s\"\n",(#x), (x));
#define dbgp(x) printf("%s @ %p\n",(#x), (x));
#define dbga(a) \
        int i##a;\
        int len_##a = lenof(a);\
        for (i##a = 0; i##a < len_##a; i##a++) printf("%d,", a[i##a]);\
        puts("\n");
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX3(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#define randin(r) (rand()%r)
