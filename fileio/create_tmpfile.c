#include "play.h"

int
main(int argc, char *argv[])
{
        if (argc != 2) exit(0);

        int fd;
        char *template = argv[1];
        fd = mktemp(template);
        if (fd == -1) fprintf(stderr, "mkstemp err.\n");
        printf("generated temp file was: %s\n", template);
        unlink(template);
        char tmp[10];
        fgets(tmp, 1, stdin);
        DONE
}

