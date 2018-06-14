#include <stdio.h>

/** Return 1 when any old bit of x equals 1; 0 oterwise.
 * Assume w=32 */

int any_odd_one(unsigned x)
{
    unsigned mask = 0xaaaaaaaa;
    return !!(x & mask);
}

int main(int argc, char const *argv[])
{

    int x = 2;
    printf("any_odd_one(0x%x) = %d\n", x, any_odd_one(x));

    x = 4;
    printf("any_odd_one(0x%x) = %d\n", x, any_odd_one(x));

    return 0;
}
