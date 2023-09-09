#include "../defs.h"

#define S1LEN 3
#define S2LEN 4
#define S3LEN 5

#define dt(a,b) abs((a)-(b))

int
main()
{
        int s1[S1LEN];
        int s2[S2LEN];
        int s3[S3LEN];
        int *slone = (int *)malloc(sizeof(int) * (S1LEN+S2LEN+S3LEN));

        int i1 = 0, i2 = 0, i3 = 0;
        int dmin = RANGE;
        int dist;
        int minof3;

        random_init_arr(slone, RANGE, S1LEN + S2LEN + S3LEN);
        dbga(slone);
        memcpy(s1, slone, S1LEN);
        for (int d = 0; d < S1LEN; d++) slone++;
        memcpy(s2, slone, S2LEN);
        for (int d = 0; d < S2LEN; d++) slone++;
        memcpy(s3, slone, S3LEN);
       
        dbga(s1);
        dbga(s2);
        dbga(s3);

        while (i1 < S1LEN && i2 < S2LEN && i3 < S3LEN && dmin > 0) {
               dist = dt(s1[i1], s2[i2]) 
                       + dt(s1[i1], s3[i3])
                       + dt(s2[i2], s3[i3]);
               minof3 = MIN3(s1[i1], s2[i2], s3[i3]);
               if (dist < dmin) dmin = dist;
               else if ( s1[i1])  {
                               i1++;
                               break;
                       }
               else if ( s2[i2]){
                               i2++;
                               break;
               } else {
                               i3++;
                               break;
               }
               dbgi(dmin);
        }
        return 0;
}
