#include <stdio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif
#ifndef usage
#define usage printf
#endif
#ifndef errExit
#define errExit printf
#endif


int
main(int argc, char *argv[])
{
        int infd, outfd, openFlags;
        mode_t filePerms;
        ssize_t numRead;
        char buf[BUF_SIZE]; 

        if (argc != 3 || strcmp(argv[1], "--help") || strcmp(argv[1], "-h") == 0)  {
            usageErr("%s old-file new-file\n", argv[0]);
            exit(-1);
        }
        infd = open(argv[1], O_RDONLY);
        if (infd == -1) {
                errExit("failed in opening file %s", argv[1]);
                return -1;
        }
        
        openFlags = O_CREAT | O_WRONLY | O_TRUNC;
        filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                        S_IROTH | S_IWOTH;
        outfd = open(argv[2], openFlags, filePerms);
        if (outfd == -1) {
            errExit("Failed to copy into the target %s", argv[2]);
            return -1;
        }
        
        while ((numRead = read(infd, buf, BUF_SIZE)) > 0) //read non-zero bytes 
            if (write(outfd, buf, numRead) != numRead) {
                    fatal("couldn't write whole buffer\n");
                    return -1;

            }
        if (numRead == -1) {
                errExit("failed to read from the original file");
                return -1;
        }
        close(infd);
        close(outfd);
        exit(EXIT_SUCCESS);
}
