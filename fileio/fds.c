#include "tlpi_hdr.h"

int
main()
{
        char buf[16];
        readlink("/proc/self/fd/1", buf, 16); // Buf contains pipe:[12345]
        printf("==>%s\n", buf);
        DONE
}
