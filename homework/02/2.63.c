#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */;
    unsigned xsra = (int)x >> k;

    int w = sizeof(int) << 3;
    // 1 << k 实际上是 1 << (k mod w)
    // 把 -1 << (w - k - 1) << 1 写成 -1 << (w-k) 的话，会导致当 k == 0 的时候，
    // -1 << w 不会发生左移
    unsigned mask = ~(-1 << (w - k - 1) << 1);

    return xsra & mask;
}

int sra(int x, int k)
{
    /* Perform shift arithmetically */;
    int xsrl = (unsigned)x >> k;

    int w = sizeof(int) << 3;
    int mask = -1 << (w - k - 1) << 1;

    int neg_sign = 1 << (w - 1);
    // x & neg_sign == neg_sign 的话
    // 说明 x 是一个负数，那么 !(x & neg_sign) == 0
    // !(x & neg_sign) - 1 == -1 == 0xFF FF FF FF
    // mask & !(x & neg_sign) - 1 会保留高位为 1
    // 否则，x & neg_sign == 0 的话
    // 同理也可知， mask & !(x & neg_sign) - 1 不会保留高位为 1
    mask &= !(x & neg_sign) - 1;

    return xsrl | mask;
}

int main(int argc, char const *argv[])
{

    int w = sizeof(int) << 3;

    unsigned x = -1;
    printf("unsigned x = 0x%.8X = %u\n", x, x);
    for (int i = 0; i < w; i++)
    {
        assert(srl(x, i) == x >> i);
        printf("srl(%u, %d) = %10u\n", x, i, srl(x, i));
    }

    x = 0x7FFFFFFF;
    printf("unsigned x = 0x%.8X = %u\n", x, x);
    for (int i = 0; i < w; i++)
    {
        assert(srl(x, i) == x >> i);
        printf("srl(%u, %d) = %10u\n", x, i, srl(x, i));
    }

    int y = 0x80000000;
    printf("int y = 0x%.8X = %d\n", y, y);
    for (int i = 0; i < w; i++)
    {
        assert(sra(y, i) == y >> i);
        printf("sra(%d, %d) = %d\n", y, i, sra(y, i));
    }

    y = 0x76543210;
    printf("int y = 0x%.8X = %u\n", y, y);
    for (int i = 0; i < w; i++)
    {
        assert(sra(y, i) == y >> i);
        printf("sra(%d, %d) = %10d\n", y, i, sra(y, i));
    }

    return 0;
}