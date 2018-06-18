#include <stdio.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* if f is denorm, return 0. Otherwise, return f */
float_bits float_denorm_zero(float_bits f)
{
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0)
    {
        /* Denormalized. Set fraction to 0 */
        frac = 0;
    }

    // Ressemble bits
    return (sign << 31) | (exp << 23) | frac;
}

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

    sign = ~sign;

    // Ressemble bits
    return (sign << 31) | (exp << 23) | frac;
}