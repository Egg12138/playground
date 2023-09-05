#include "play.h"
#include "ds.h"
#include <time.h>
#include <assert.h>

typedef uint32_t u32;

// test cases for odd lenghth of array
//
#define RANGE 31// max number of the randomed array
#define ODD_LEN_ARR

#define ARRSZEVEN 10
#define ARRSZODD 11

#ifdef ODD_LEN_ARR
#define ARRSZ ARRSZODD
#else
#define ARRSZ ARRSZEVEN
#endif

int test_array[ARRSZ] = {0};

//void random_init_arr(int a[]);

void random_init_arr(int a[], int scale, int len) {
        srand(time(NULL));
        for (int i = 0; i < len; i++) {
                a[i] = rand() % scale;

        }
}

