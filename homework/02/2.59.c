#include <stdio.h>

void main(int argc, char const *argv[])
{
    int x = 0x89abcdef;
    int y = 0x76543210;
    int res = (x & 0xff) | (y & ~0xff);

    printf("  x = %X\n", x);
    printf("  y = %X\n", y);
    printf("res = %X\n", res);
}
