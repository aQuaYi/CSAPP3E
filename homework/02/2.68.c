#include <stdio.h>
#include <assert.h>

/**
 * Mask with least signficant n bits  set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */

int lower_one_mask(int n)
{
    int w = sizeof(int) << 3;
    return (unsigned)-1 >> (w - n);
}

int main()
{

    int n = 6;
    int res = 0x3F;
    printf("n = %3d --> %8x\n", n, lower_one_mask(n));
    assert(lower_one_mask(n) == res);

    n = 17;
    res = 0x1FFFF;
    printf("n = %3d --> %8x\n", n, lower_one_mask(n));
    assert(lower_one_mask(n) == res);

    return 0;
}
