#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    if (i < 0)
    {
        printf("error: i=%d is negtive\n", i);
        return x;
    }

    int max = sizeof(unsigned) - 1;
    if (i > max)
    {
        printf("error: i == %d is more than %d \n", i, max);
        return x;
    }

    unsigned mask = ~(0xFF << (i << 3));
    unsigned rb = (unsigned)b << (i << 3);

    return (x & mask) | rb;
}

int main(int argc, char const *argv[])
{
    unsigned x = 0x12345678;
    unsigned char b = 0xAB;
    int i;

    printf("                       x = %8X\n", x);

    for (i = 0; i < 4; i++)
    {
        printf("replace_byte(x, %d, 0x%X) = %8X\n", i, b, replace_byte(x, i, 0xAB));
    }

    printf("\n");

    i = -1;
    printf("replace_byte(x, %d, 0x%X) = %8X\n", i, b, replace_byte(x, i, 0xAB));

    printf("\n");

    i = 4;
    printf("replace_byte(x, %d, 0x%X) = %8X\n", i, b, replace_byte(x, i, 0xAB));

    return 0;
}
