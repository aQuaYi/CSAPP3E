#include <stdio.h>
#include <limits.h>

int mul3div4(int x)
{
    int m3x = (x << 1) + x;
    int bias = (m3x >> 31) & 0x3;
    return (m3x + bias) >> 2;
}

int main(int argc, char const *argv[])
{

    for (int x = 1; x < 1000; x = x + 100)
    {
        printf("mul3div4(% 4d) = % 4d\n", x, mul3div4(x));
        int neg_x = -x;
        printf("mul3div4(% 4d) = % 4d\n", neg_x, mul3div4(neg_x));
    }

    return 0;
}