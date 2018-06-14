#include <stdio.h>

/**
 * Return 1 when x can be represented as an n-bit, 2's-complement number;
 * Return 0 otherwise
 * Assume 1 <= n <=w
 */

int fits_bits(int x, int n)
{
    int w = sizeof(int) << 3;
    int offset = w - n;
    return x == ((x << offset) >> offset);
}

int main()
{

    int x = 0xf;
    int n = 4;
    printf("0x%08x can be represented as an %d-bit 2's-complement number: %d\n", x, n, fits_bits(x, n));

    x = 0xf;
    n = 5;
    printf("0x%08x can be represented as an %d-bit 2's-complement number: %d\n", x, n, fits_bits(x, n));

    return 0;
}
