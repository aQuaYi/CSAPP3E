#include <stdio.h>

int combine(int x, int y)
{
    x = x & 0xff;
    y = y & (-1 << 8);
    return x + y;
}

void main()
{
    int x = 0x89abcdef;
    int y = 0x76543210;
    int cb = combine(x, y);
    printf("x = %x\n", x);
    printf("y = %x\n", y);
    printf("cb= %x\n", cb);
}