#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "float-bits.h"

/* Compute -f. If f is NaN, then return f. */
float_bits float_twice(float_bits f)
{
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NaN = exp == 0xFF && frac != 0;

    if (is_NaN)
    {
        return f;
    }

    if (exp == 0)
    {
        /* Denormalized */
        frac <<= 1;
    }
    else if (exp < 0xFE)
    {
        /* Normalized */
        exp++;
    }
    else // exp == 0xFE or 0xFF
    {
        /* twice to INF */
        exp = 0xFF;
        frac = 0;
    }

    // Ressemble bits
    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char const *argv[])
{
    float_bits fb = 0x0;

    for (; fb <= 0xFFFFFFFF; fb++)
    {
        printf("float_twice(0x%.8X) = 0x%.8X\n", fb, float_twice(fb));
        assert(fb2f(float_twice(fb)) == 2 * fb2f(fb));
    }

    return 0;
}