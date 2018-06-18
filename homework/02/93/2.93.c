#include <stdio.h>

typedef unsigned float_bits;

// Compute |f|. If f is NaN, then return f.
float_bits float_absval(float_bits f)
{
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NAN = (exp == 0xFF) && (frac != 0);
    if (is_NAN)
    {
        return f;
    }

    return 0 << 31 | exp << 23 | frac;
}