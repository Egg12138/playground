/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2023.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 24-1 */

/* t_fork.c

   Demonstrate the use of fork(), showing that parent and child
   get separate copies of stack and data segments.
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "tlpi_hdr.h"

static int idata = 111;             /* Allocated in data segment */

int
main(int argc, char *argv[])
{
    int istack = 222;               /* Allocated in stack segment */
    int fd, flags;
    char template[] = "/tmp/testXXXXXX";
    setbuf(stdout, NULL);

    fd = mkstemp(template);
    if (fd == -1) errExit("mkdtemp failed");

    printf("file offset before fork() %lld\n", 
                    (long long) lseek(fd, 0, SEEK_CUR));
    flags = fcntl(fd, F_GETFL);
    if (flags == -1) errExit("fcntl - F_GETFL");
    
    pid_t childPid;

    switch (childPid = fork()) {
    case -1:
        errExit("fork");

    case 0:
        idata *= 3;
        istack *= 3;
        flags = fcntl(fd, F_GETFL);
        flags |= O_APPEND;
        if (fcntl(fd, F_SETFL, flags) == -1) errExit("fcntl - F_SETFL(child)");
        _exit(EXIT_SUCCESS);
        break;

    default:
        sleep(3);                   /* Give child a chance to execute */
        if (wait(0) == -1) errExit("wait");

        printf("child has exited\n");

        printf("offset in parent: %lld\n", (long long) lseek(fd, 0, SEEK_CUR));

        exit(EXIT_SUCCESS);


    }

    /* Both parent and child come here */

    printf("PID=%ld %s idata=%d istack=%d\n", (long) getpid(),
            (childPid == 0) ? "(child) " : "(parent)", idata, istack);


    exit(EXIT_SUCCESS);
}
