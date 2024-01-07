#include <stdio.h>
#include <stdint.h>
#include <assert.h>
int
main()
{
        unsigned int x = 134;
        unsigned int y = 246;

        int m = x;
        int n = y;

        unsigned int z1 = x - y;
        unsigned int z2 = x + y;

        int k1 = m - n;
        int k2 = m +n;

        printf("x: %ud,%x\n y:%ud, %x, \n m = %d, %x\n, m = %d, %x,\n \
                                x-y: %ud, %x, \nx+y, %ud, %x\n,\
                                m-n: %d, %x, \n\
                                m+n: %d, %x, \n,\
                                ", 
                                x, x, y, y, m, m, n, n, z1, z1,  z2, z2, k1, k1, k2, k2);
        uint8_t ui8x = 0b11111111;        
        int8_t ii8x = 0b11111111;
        int8_t i8 = 255;
        int64_t i64x1 = 0b11111111;
        int64_t i64x = ii8x;
        int32_t i32x = 0b11111111;
        printf("uint8_t x = %d, u%u %x\n, int8_t x = %d, %x\n, \n\
                        i8_t(255) = %x, %x \n\
                        int32_t x = %d, %x\n, int64_t x= %ld, %x\
                        int64_t(raw binary) = %ld, %x\n\
                        sizeof(i8)=%ul, sizeof(i32)=%ul, sizeof(i64)=%ul", 
                        ui8x, ui8x, ui8x, ii8x, ii8x, i8, i8,  i32x, i32x,  i64x, i64x, i64x1, i64x1,sizeof(ii8x), sizeof(i32x), sizeof(i64x));
        assert(ui8x > 0);
        assert(ii8x < 0);
        assert(i32x > 0);
        assert(i64x1 > i64x);
        assert(i64x1 == i32x);
        assert(i64x == ii8x);

        int8_t delta1 = i8 - ui8x;
        int8_t sum1 = i8 + ui8x;
        printf("(\ni8 - ui8x) = %d, %x\n, (i8 + ui8x) = %d, %x", delta1, sum1);
        uint8_t deltau = i8 - ui8x;
        uint8_t sumu = i8 + ui8x;
        printf("(\ni8 - ui8x) = %u, %x\n, (i8 + ui8x) = %d, %x", deltau, sumu);
        printf("i8 right shift 3: %d, %x\n", (i8 >> 3), (i8 >> 3));
        return 0;
}
