#include "../defs.h"

int
main()
{
      int cnt = 0;
      int sz = ARRSZ;  
      int idx = 0;

      int arr[ARRSZ];
      int cur_num;
      random_init_arr(arr);
      dbga(arr);


      while (idx <= sz - 1) {
              cur_num = arr[idx];
              for (int i = 0; i < sz; i++) {
                      if arr[i] == cur_num      
                              cnt++;
                      else
                              cnt--;
              }
              if (cnt >= 1) 
                        goto success;
              else idx++;
              
      }

success:

      printf(" the major number is %d\n", arr[idx]);
       exit(0);

}
