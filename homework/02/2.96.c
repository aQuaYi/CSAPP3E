#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "float-bits.h"

/** Compute (int) f. 
 * If conversion cause overflow or f is NaN, return 0x80000000
*/
int float_f2i(float_bits f)
{
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned M = (1 << 23) | frac;

    if (exp < 127)
    {
        /** 当 exp < 127 时， E < 0 , abs(f) < 1 ,结果为 0 */
        return 0;
    }

    int E = exp - 127; // 0 <= E

    int num;

    if (E <= 23)
    {
        num = M >> (23 - E);
    }
    else if (E <= 30)
    {
        num = M << (E - 23);
    }
    else // 31 <= E
    {
        /**
         * 注意，f 等于 -2^31 不构成溢出，只是返回值 0x80000000 正好就是 -2^31
         * 除此之外的其他情况，是因为题目规定，溢出返回 0x80000000
         */
        return 0x80000000;
    }

    return sign ? -num : num;
}

int main(int argc, char const *argv[])
{

    for (float_bits fb = 0x0; fb <= 0xFFFFFFFF; fb++)
    {
        printf("float_f2i(0x%.8X) = 0x%.8X\n", fb, float_f2i(fb));
        assert(float_f2i(fb) == (int)fb2f(fb));
    }

    return 0;
}