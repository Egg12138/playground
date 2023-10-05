#include "play.h"
#include <pthread.h>

long g_var = 0x191919191;

void *show_add() {
        int local = 222;
        printf("is at %p and %p\n", &g_var, &local);
}
int
main()
{
        for (int i = 0; i < 30; i++) {
                pthread_t *tid = (pthread_t *)malloc(sizeof(pthread_t));
                pthread_create(tid, NULL, show_add, NULL);
        }
        return 0;
}
