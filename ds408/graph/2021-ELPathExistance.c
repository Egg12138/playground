#include "../defs.h"

#define isodd(n) ((n) % 2 != 0)
int isExistEL(MGraph G) {
        int odd_cnt = 0;
        int deg;// degree of each iterated vertex

        for (int i = 0; i < n; i++) {
                deg = 0;
                for (int j = 0; j < n; j++) 
                        if (G.VerticesList[i][j]) deg++;
                if (isodd(deg))
                        odd_cnt++;
        }

        if (odd_cnt == 0 || odd_cnt == 2) return 1;
        return 0;

}


int
main()
{
        
        return 0;
}
