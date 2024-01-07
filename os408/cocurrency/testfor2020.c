#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

#define P(s) (sem_wait((s)));
#define V(s) (sem_post((s)));

sem_t ab;
sem_t cd;
sem_init(&ab, 0, -1);
sem_init(&cd, 0, -1);

void do(char c) {
        printf("%c->", c);
}
void A() {
	do('a');
	V(ab);
}
void B() {
	do('b');
	V(ab);
}

void C() {
	P(ab);
	do('c');
	V(cd);
}

void D() {
	do('d');
	V(cd);
}

void E() {
	P(cd);
	do('e');
}

int
main() {

        return 0;
}