#include "play.h"

#define N 5
pthread_mutex_t fork_locks[N];

void *philosopher(void *arg) {
        int id = (int) arg;
        int left = id;
        int right = (id + 1) % N;
        while (1) {
                pthread_mutex_lock(&fork_locks[left]);
                pthread_mutex_lock(&fork_locks[right]);
                printf("%d is eating\n",id);
                pthread_mutex_unlock(&fork_locks[left]);
                pthread_mutex_unlock(&fork_locks[right]);
        }
        return NULL;
}

int
main()
{
        pthread_t ps[N];
        for (int i = 0; i < N; i++) {
                pthread_mutex_init(&fork_locks[i], NULL);
        }

        for (int i = 0; i < N; i++) {
                pthread_create(&ps[i], NULL, philosopher, (void *)i);
        }

        for (int i = 0; i < N; i++) {
                pthread_join(ps[i], NULL);
        }

        return 0;
}

