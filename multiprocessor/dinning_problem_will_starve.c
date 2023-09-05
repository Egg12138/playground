#include "play.h"

#define N 15
#define HELD 1
#define FREE 0

//pthread_mutex_t forks[N];
int forks[N];

void *philosopher(void *arg) {

        int id = (int) arg;

        #define left_hand (id)
        #define right_hand (((id) + 1) % N)
        #define left_free (forks[left_hand] == FREE)
        #define right_free (forks[right_hand] == FREE)
        #define hold_forks \
                        forks[left_hand] = HELD; \
                        forks[right_hand] = HELD;\  
                        
        #define free_forks \
                        forks[left_hand] = FREE; \
                        forks[right_hand] = FREE;\  
        


        while (1) {
                while (left_free && right_free) {
                        hold_forks

                        printf("%d,",id);
                        //sleep(1);
                        
                        free_forks
                }
        }
        return NULL;
}
int
main()
{
        pthread_t ps[N];

        for (int i = 0; i < N; i++) {
                pthread_create(&ps[i], NULL, philosopher, (void *)i);
        }
        
        for (int i = 0; i < N; i++) {
                pthread_join(ps[i], NULL);
        }


        DONE
}
