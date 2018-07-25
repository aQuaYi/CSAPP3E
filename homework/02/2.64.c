#include <stdio.h>
#include <assert.h>

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32 */
int any_odd_one(unsigned x)
{
    unsigned mask = 0xAAAAAAAA;
    return !!(x & mask);
}

int main(int argc, char const *argv[])
{

    unsigned x = 0x1;
    printf("any_odd_one(0x%X) == %d\n", x, any_odd_one(x));
    assert(any_odd_one(x) == 0);

    x = 0x2;
    printf("any_odd_one(0x%X) == %d\n", x, any_odd_one(x));
    assert(any_odd_one(x) == 1);

    return 0;
}