
#include <stdio.h>

long decode2(long x, long y, long z)
{
    y -= z;
    x *= y;
    return x ^ ((y << 63) >> 63);
}

int main(int argc, char const *argv[])
{
    long x = 3;
    long y = 5;
    long z = 7;

    printf("decode2(%ld,%ld,%ld) = %ld\n", x, y, z, decode2(x, y, z));

    return 0;
}
