#include <stdio.h>

int A(int x)
{
    return !~x;
}

int B(int x)
{
    return !x;
}

int C(int x)
{
    return !~(x | ~0xff);
}

int D(int x)
{
    return !((x >> (sizeof(int) - 1) << 3) & 0xff);
}

int main()
{
    int x = -1;
    printf("A(0x%08x) = %d\n", x, A(x));

    x = -2;
    printf("A(0x%08x) = %d\n", x, A(x));

    x = 0;
    printf("B(0x%08x) = %d\n", x, B(x));

    x = 1;
    printf("B(0x%08x) = %d\n", x, B(x));

    x = 0xff;
    printf("C(0x%08x) = %d\n", x, C(x));

    x = 0xfb;
    printf("C(0x%08x) = %d\n", x, C(x));

    x = 0x345678;
    printf("D(0x%08x) = %d\n", x, D(x));

    x = 0x2345678;
    printf("D(0x%08x) = %d\n", x, D(x));

    return 0;
}
