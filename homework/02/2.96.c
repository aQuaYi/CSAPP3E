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
    unsigned M = (1 << 23) + frac;

    // int is_NaN_or_INF = (exp == 0xFF);
    // 0x4F000000 是 float 在 [-2^31, 2^31] 中能精确表示的最大整数，也就是 2^31
    int is_pos_overflow = (sign == 0 && 0x4F000000 <= f);
    // 0xCF000000 是 float 在 [-2^31, 2^31] 中能精确表示的最小整数，也就是 -2^31.
    int is_neg_overflow = (sign == 1 && 0xCF000000 <= f);
    // 本来上式中 应该是 < f 的，是因为，overflow 时，返回的是 INT_MIN 才加上的等号

    // if (is_NaN_or_INF | is_pos_overflow | is_neg_overflow)
    if (is_pos_overflow | is_neg_overflow)
    {
        return 0x80000000;
    }

    int res = 0;

    if (exp < 127)
    {
        /** 当 exp < 127 时， E < 0 , abs(f) < 1 ,res 等于初始化的 0 */
        return res;
    }
    else if (127 <= exp && exp <= 150) // E >=0，此时，abs(f) >= 1;
    {
        res = M >> (150 - exp);
    }
    else // 150 < exp <= 157
    {
        res = M << (exp - 150);
    }

    if (sign == 1)
    {
        res = -res;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    float_bits fb = 0x0 + 0x800000;

    for (; fb <= 0xFFFFFFFF; fb++)
    {
        printf("float_half(0x%.8X) = 0x%.8X\n", fb, float_half(fb));
        assert(float_half(fb) == f2fd(0.5 * fb2f(fb)));
    }

    return 0;
}