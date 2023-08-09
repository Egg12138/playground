#include "play.h"

int
main(int argc, char *argv[])
{
        if (argc != 2) exit(0);
        char *name = argv[1];
        int fd1, fd2, fd3;
        fd1 = open(name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        fd2 = dup(fd1);
        fd3 = open(name, O_RDWR);
        getchar();
        dbgi(fd1);
        dbgi(fd2);
        dbgi(fd3);
        write(fd1, "HHHHH+", 6);
        getchar();
        write(fd2, "----+", 6);
        getchar();
        lseek(fd2, 0, SEEK_SET);
        write(fd1, "OOOOO+", 6);
        getchar();
        write(fd3, "|||||+", 6);
        getchar();
        return 0;
}
