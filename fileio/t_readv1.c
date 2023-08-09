#include <sys/uio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include "tlpi_hdr.h"

#define dbg(x) printf("=>%s\n", (x))
#define dbgi(i) printf("[%ld]\n", (i))
#define errExit(msg) {\
                puts(msg);\
                exit(-1);\
}

int
main(int argc, char *argv[])
{
        int fd;        
        struct iovec iov[3];
        struct stat myStruct; 
        int x;
#define STR_SIZE 100
        char str[STR_SIZE];
        ssize_t numRead, totRequired;
        if (argc != 2 || strcmp(argv[1], "--help") == 0) 
                errExit(argv[0]);
        fd = open(argv[1], O_RDONLY);
        if (fd ==  -1) errExit("open");

        totRequired = 0;
        iov[0].iov_base = &myStruct;
        iov[0].iov_len = sizeof(struct stat);
        totRequired += iov[0].iov_len;
        
        dbgi(totRequired);

        iov[1].iov_base = &x;
        iov[1].iov_len = sizeof(x);
        totRequired += iov[1].iov_len;

        dbgi(totRequired);

        numRead = readv(fd, iov, 3);
        if (numRead = -1) errExit("readv");
        if (numRead < totRequired) puts("Read fwer bytes than requested\n");

        printf("%ld; bytes read: %ld\n",
                        (long)totRequired, (long)numRead);


        DONE
}
