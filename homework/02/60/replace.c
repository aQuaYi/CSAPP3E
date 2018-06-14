#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    if (i < 0)
    {
        printf("error: i is negtive\n");
        return x;
    }

    if (i > sizeof(unsigned) - 1)
    {
        printf("error: i == %d, is too big", i);
        return x;
    }

    unsigned replace_byte = ((unsigned)b) << (i << 3);
    unsigned mask = ~(0xff << (i << 3));
    return (x & mask) | replace_byte;
}

void main()
{
    unsigned x = 0x12345678;
    unsigned char b = 0xAB;
    printf("   x = %x, b = %x\n", x, b);
    int i = 0;
    printf("i = %d, %x\n", i, replace_byte(x, i, b));
    i = 1;
    printf("i = %d, %x\n", i, replace_byte(x, i, b));
    i = 2;
    printf("i = %d, %x\n", i, replace_byte(x, i, b));
    i = 3;
    printf("i = %d, %x\n", i, replace_byte(x, i, b));
}