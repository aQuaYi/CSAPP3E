#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "float-bits.h"

/** Compute (float) f. 
*/
float_bits float_i2f(int i)
{
    if (i == 0)
    {
        return 0;
    }

    if (i == INT_MIN)
    {
        return 0xCF000000;
    }

    unsigned sign = i < 0 ? 1 : 0;
    unsigned abs_i = i < 0 ? -i : i;
    unsigned M = abs_i;
    unsigned E = 0;

    while (M > 1)
    {
        M >>= 1;
        E++;
    }

    // printf("1.E=%d\n", E);
    // printf("1.abs_i=%d, %.8X\n", abs_i, abs_i);

    unsigned exp = E + 0x7F;
    M = abs_i;

    // printf("1.M=0x%X\n", M);

    if (E <= 23)
    {
        M <<= (23 - E);
        M -= 1 << 23;
    }
    else // E > 23
    {
        unsigned lsb_is_one = (M >> (E - 23)) & 1;
        unsigned invalid_bit = M & ((1 << (E - 23)) - 1);
        unsigned half_lsb = 1 << (E - 24);
        unsigned round_to_even = (lsb_is_one && invalid_bit >= half_lsb) ||
                                 (!lsb_is_one && invalid_bit > half_lsb);

        // printf("1.lsb_is_one = %d, invalid_bit=%.8X\n", lsb_is_one, invalid_bit);
        // printf("1.round_to_even=%d\n", round_to_even);

        M >>= (E - 23);
        M += round_to_even;
        // printf("2.M=0x%X\n", M);
    }

    if ((M >> 24) == 1)
    {
        M >>= 1;
        exp++;
    }

    // printf("3.M=0x%X\n", M);

    unsigned frac = M - (1 << 23);

    // printf("sign = %.8X, exp = %.8X, frac = %.8X\n", sign << 31, exp << 23, frac);
    return sign << 31 | exp << 23 | frac;
}

int main(int argc, char const *argv[])
{

    // printf("INT_MIN+1 = 0x%8X\n", f2fd((float)(INT_MIN + 1)));

    for (int i = INT_MIN; i <= INT_MAX; i++)
    {
        printf("float_i2f(%d) = 0x%.8X, answer is 0x%.8X\n", i, float_i2f(i), f2fd((float)i));
        assert(float_i2f(i) == f2fd((float)i));
    }

    return 0;
}