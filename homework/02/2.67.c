#include <stdio.h>
#include <limits.h>

int int_size_is_32()
{
    int set_msb = 1 << 31;
    // beyond_msb 没有办法一次左移 32 位，需要分两次进行
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16_bit()
{
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main()
{
    printf("This system int size is 32 : %d\n", int_size_is_32());
    printf("This system int size for 16 bit is 32 : %d\n", int_size_is_32_for_16_bit());
    return 0;
}
