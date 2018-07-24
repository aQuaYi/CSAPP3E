#include <stdio.h>
#include <assert.h>

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
    return !~(x | ~0xFF);
}

int D(int x)
{
    int shift = (sizeof(int) - 1) << 3;
    return !(x >> shift);
}

int main(int argc, char const *argv[])
{
    int x = -1;
    assert(A(x));
    printf("A(0x%X) = %d\n", x, A(x));
    x = -1 - 1;
    assert(!A(x));
    printf("A(0x%X) = %d\n", x, A(x));

    x = 0;
    assert(B(x));
    printf("B(0x%X) = %d\n", x, B(x));
    x = 1;
    assert(!B(x));
    printf("B(0x%X) = %d\n", x, B(x));

    x = 0xFF;
    assert(C(x));
    printf("C(0x%X) = %d\n", x, C(x));
    x = 0xF7;
    assert(!C(x));
    printf("C(0x%X) = %d\n", x, C(x));

    x = 0x345678;
    assert(D(x));
    printf("D(0x%X) = %d\n", x, D(x));
    x = 0x1345678;
    assert(!D(x));
    printf("D(0x%X) = %d\n", x, D(x));

    return 0;
}