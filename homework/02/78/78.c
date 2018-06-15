#include <stdio.h>

/**
 * Divide by power of 2. Assume 0 <= k < w-1
 */

int divide_power2(int x, int k)
{
    int w = sizeof(int) << 3;
    int ui = (unsigned)-1 >> (w - k);
    int bias = (x >> (w - 1)) & ui;
    return (x + bias) >> k;
}

int main(int argc, char const *argv[])
{

    int x = 0x72345678;
    for (int k = 0; k < 31; ++k)
    {
        printf("%d / 2^%d = %d\n", x, k, divide_power2(x, k));
    }

    x = 0x87654321;
    for (int k = 0; k < 31; ++k)
    {
        printf("%d / 2^%d = %d\n", x, k, divide_power2(x, k));
    }

    return 0;
}
