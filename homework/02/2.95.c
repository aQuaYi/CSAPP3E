#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "float-bits.h"

/* Compute -f. If f is NaN, then return f. */
float_bits float_half(float_bits f)
{
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NaN_or_INF = (exp == 0xFF);

    if (is_NaN_or_INF)
    {
        return f;
    }

    /**
   * round to even, we care about last 2 bits of frac
   *
   * 00 => 0 just >>1
   * 01 => 0 (round to even) just >>1
   * 10 => 1 just >>1
   * 11 => 1 + 1 (round to even) just >>1 and plus 1
   */
    int round_to_even = ((frac & 0x3) == 0x3);

    if (exp == 0)
    {
        /* Denormalized */
        frac >>= 1;
        frac += round_to_even;
    }
    else if (exp == 1)
    {
        /* Normalize -> Denormalized */
        exp = 0;
        unsigned M = (1 << 23) + frac;
        frac = M >> 1;
        frac += round_to_even;
    }
    else // exp <= 0xFE
    {
        /* Normalized */
        exp--;
    }

    // Ressemble bits
    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char const *argv[])
{
    float_bits fb = 0x0 + 0x800000;

    for (; fb <= 0xFFFFFFFF; fb++)
    {
        printf("float_half(0x%.8X) = 0x%.8X\n", fb, float_half(fb));
        assert(float_half(fb) == f2fd(0.5 * fb2f(fb)));
        printf("-------\n");
    }

    return 0;
}