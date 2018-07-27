#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "float-bits.h"

/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f)
{
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && frac != 0)
    {
        // f is NaN
        return f;
    }

    sign ^= 1;

    // Ressemble bits
    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char const *argv[])
{
    float_bits fb = 0x0;

    for (; fb <= 0xFFFFFFFF; fb++)
    {
        printf("float_negate(0x%.8X) = 0x%.8X\n", fb, float_negate(fb));
        assert(fb2f(float_negate(fb)) == -fb2f(fb));
    }

    return 0;
}