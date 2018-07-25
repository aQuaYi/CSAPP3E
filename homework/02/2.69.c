#include <stdio.h>
#include <assert.h>

/**
 * Do rotating left shift. Assume 0<= n < w
 * Example when x = 0x12345678 and w = 32:
 *    n = 4 -> 0x23456781, n = 20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n)
{
    unsigned w = sizeof(unsigned) << 3;
    unsigned left = x << n;
    /**当 n == 0 时，
     * left = x << 0 = x
     * right = x >> w = x
     * left | right = x | x = x
     * 虽然，与 n 等于其他数时，进行的操作不一样，
     * 但是不影响结果的正确性
     * 
     * 把 right 写成以下方式，可以保证所有的操作都一致
     * unsigned right = x >> (w - n - 1) >> 1;
     */
    unsigned right = x >> (w - n);
    return left | right;
}

int main(int argc, char const *argv[])
{
    unsigned x = 0x12345678;
    unsigned a[] = {
        0x12345678,
        0x2468ACF0,
        0x48D159E0,
        0x91A2B3C0,
        0x23456781,
        0x468ACF02,
        0x8D159E04,
        0x1A2B3C09,
        0x34567812,
        0x68ACF024,
        0xD159E048,
        0xA2B3C091,
        0x45678123,
        0x8ACF0246,
        0x159E048D,
        0x2B3C091A,
        0x56781234,
        0xACF02468,
        0x59E048D1,
        0xB3C091A2,
        0x67812345,
        0xCF02468A,
        0x9E048D15,
        0x3C091A2B,
        0x78123456,
        0xF02468AC,
        0xE048D159,
        0xC091A2B3,
        0x81234567,
        0x2468ACF,
        0x48D159E,
        0x91A2B3C,
    };

    for (int i = 0; i < 32; i++)
    {
        printf("rotate_left(0x%8X,%d) = 0x%8X\n", x, i, rotate_left(x, i));
        assert(rotate_left(x, i) == a[i]);
    }

    return 0;
}
