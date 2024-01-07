#include <stdio.h>
#include <stdint.h>
#include <assert.h>


int
main() 
{
        uint8_t u8 = 0b11111111; // > 0, u8 = 2^8 - 1 = 255; [t0] = 0xff
        int8_t i8 = 0b11111111; // < 0, -1，[t1] = 0xffffffffffffffff  (64-bit 寄存器)
        int8_t i8255 = 255; // -1， [t2] = 0xffffffffffffffff
        int32_t i32 = 0b11111111; // > 0， [t3] = 0xff
        int32_t i8to32 = i8; // i8to32 == i8 = -1; [t4] = 0xffffffffffffffff
        int64_t i64 = 0b11111111; // [t5] = 0xff
        int8_t deltai = i8 - u8; // [t6] = 0
        int8_t sumi = i8 + u8; // [t7] = 0xfffffffffffffffe
        uint8_t deltau = i8 - u8; // [t8] = 0
        uint8_t sumu = i8 + u8; // [t9] = 0xfe
        assert(sizeof(u8) == 1); // true, 1B
        assert(sizeof(i32) == 4); // true, 4B
        assert(sizeof(i64) == 8); // true, 8B 
        return 0;
}
