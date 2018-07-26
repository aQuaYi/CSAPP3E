#include <stdio.h>
#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int x_is_neg = x & INT_MIN;
    x_is_neg && (x += (1 << k) - 1);
    return x >> k;
}

int main(int argc, char const *argv[])
{

    int x = 0x72345678;
    int tx = x;
    for (int k = 0; k < 31; ++k)
    {
        printf("%d / 2^%d = %d\n", x, k, divide_power2(x, k));
        assert(divide_power2(x, k) == tx);
        tx /= 2;
    }

    x = 0x87654321;
    tx = x;
    for (int k = 0; k < 31; ++k)
    {
        printf("%d / 2^%d = %d\n", x, k, divide_power2(x, k));
        assert(divide_power2(x, k) == tx);
        tx /= 2;
    }

    return 0;
}
