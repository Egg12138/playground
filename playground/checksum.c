#include "./play.h"

#define GET_CARRY(s) ((s) >> 16)
#define SPLIT_CARRY(s) ((s) && 0x0ffff)
int
main()
{
        uint32_t data[] = {
                0xc0a8,0x0106,//source IP
                0x0b6f,0x6f6f,//destination IP
                17,//UDP
                17,//UDP length
                60849,//source port
                12345,//destination port
                17,//UDP len
                0x6865,0x6c6c,0x6f20,0x5544,0x5000 //hello UDP对应的ascii码对应的十六进制数
        };

        int hexsum = 0;
        for (int i = 0; i < 14; i++) {
                hexsum += data[i];
                printf("+%x\n", hexsum);
                if (hexsum > 0xffff) { // overflow
                        int carry = GET_CARRY(hexsum);
                        printf("Overflow: %x, add the carry %x to it\n", hexsum, carry);
                        hexsum = SPLIT_CARRY(hexsum);
                        hexsum += carry;
                        printf("+%x\n", hexsum);
                }
        }

        printf("result = %x\n", hexsum);




}
