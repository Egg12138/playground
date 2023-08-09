#include <semaphore.h>
#include <pthread.h>
#include "play.h"

sem_t a;
void 
access_critical_section(void) {
        puts("accessed\n");
}
void *
child(void *arg) {
        printf("child\n");
        sem_post(&a);
        return NULL;
}

int
main()
{
        sem_t s;
        // pshared == 0 -> semaphore shared between the threads of a process. 
        sem_init(&s, 0, 1);

        printf("二值信号量作为lock\n");
        sem_t m;
        sem_init(&m, 0, 1);

        sem_wait(&m);
        access_critical_section();
        sem_post(&m);


        printf("信号量用作条件变量\n");
        // 希望输出: 
        // parent: begin 
        // child
        // parent: end
        // 于是init要挂起，初始应该为0
        sem_init(&a, 0, 0); 
        puts("parent: begin\n");
        pthread_t c;
        pthread_create(&c, NULL, child, NULL);
        sem_wait(&a);
        puts("parent: end\n");

        return 0;
}


