#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "float-bits.h"

/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f)
{
    /* Decompose bit representation into parts */
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NaN = (exp == 0xFF && frac != 0);

    if (is_NaN)
    {
        return f;
    }

    // Ressemble bits
    return (exp << 23) | frac;
}

int main(int argc, char const *argv[])
{
    float_bits fb = 0x0;

    for (; fb <= 0xFFFFFFFF; fb++)
    {
        printf("float_absval(0x%.8X) = 0x%.8X\n", fb, float_absval(fb));
        assert(fb2f(float_absval(fb)) == fabs(fb2f(fb)));
    }

    return 0;
}