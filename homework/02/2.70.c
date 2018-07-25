#include <stdio.h>
#include <assert.h>

/**
 * Return 1 when x can be represented as an n-bit, 2's-complement number;
 * Return 0 otherwise
 * Assume 1 <= n <=w
 * x 能否表示为 n 位二进制补码
 */
int fits_bits(int x, int n)
{
    int w = sizeof(int) << 3;
    int offset = w - n;
    /**n 位二进制补码的特点是，第 n 位为符号位
     * (x << offset) 让 x 的第 n 位左移到了符号位，
     * (x << offset) >> offset 利用算术右移让原先 x 的低 n 位还原。
     * 如果 x 的第 n 位是符号位，
     * 那么，x == (x << offset) >> offset，表示 x 可以用 n 位二进制补码表示
     */
    return x == (x << offset) >> offset;
}

int main()
{

    int x = 0xf;
    int n = 4;
    printf("fits_bits(0x%X, %d) = %d\n", x, n, fits_bits(x, n));
    assert(!fits_bits(x, n));

    x = 0xf;
    n = 5;
    printf("fits_bits(0x%X, %d) = %d\n", x, n, fits_bits(x, n));
    assert(fits_bits(x, n));

    x = 0x0;
    n = 1;
    printf("fits_bits(0x%X, %d) = %d\n", x, n, fits_bits(x, n));
    assert(fits_bits(x, n));

    x = 0x1;
    n = 1;
    printf("fits_bits(0x%X, %d) = %d\n", x, n, fits_bits(x, n));
    assert(!fits_bits(x, n));

    x = -1;
    n = 1;
    printf("fits_bits(0x%X, %d) = %d\n", x, n, fits_bits(x, n));
    assert(fits_bits(x, n));

    return 0;
}
