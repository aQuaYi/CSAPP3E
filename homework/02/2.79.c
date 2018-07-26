#include <stdio.h>
#include <limits.h>
#include <assert.h>

int mul3div4(int x)
{
    int m3x = (x << 1) + x;
    int is_neg = m3x & INT_MIN;
    is_neg && (m3x += 3);
    return m3x >> 2;
}

int main(int argc, char const *argv[])
{
    int limit = INT_MAX / 2;

    for (int x = 1; x < limit; x = x + 1000)
    {
        printf("mul3div4(% 4d) = % 4d\n", x, mul3div4(x));
        assert(mul3div4(x) == x * 3 / 4);
        int neg_x = -x;
        printf("mul3div4(% 4d) = % 4d\n", neg_x, mul3div4(neg_x));
        assert(mul3div4(neg_x) == neg_x * 3 / 4);
    }

    return 0;
}