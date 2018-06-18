#include <stdio.h>

typedef unsigned float_bits;

// Compute |f|. If f is NaN, then return f.
float_bits float_absval(float_bits f)
{
    unsigned sign = f >> 31;

    if (sign == 1)
    {
        return float_negate(f);
    }

    return f;
}