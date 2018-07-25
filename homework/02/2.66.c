#include <stdio.h>
#include <assert.h>

/**Generate mask indicating leftmost 1 in x. Assume w=32.
 * For Example. 0xFF00 -> 0x8000, and 0x6600 -> 0x4000.
 * If x = 0, then return 0.
 */

int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    /** 若原先 x = 0B00101000111001010111100010110011
     *  现在则 x = 0B00111111111111111111111111111111
     */
    return (x >> 1) + (x & 1);
}

int main(int argc, char const *argv[])
{

    unsigned y = 1;
    for (unsigned i = 0; i < 32; i++)
    {
        printf("leftmost_one(0x%X) = 0x%X\n", y, leftmost_one(y));
        assert(leftmost_one(y) == y);
        y <<= 1;
    }

    printf("\n");

    unsigned x = 0xFF00;
    printf("leftmost_one(0x%.8X) = 0x%.8X\n", x, leftmost_one(x));
    assert(leftmost_one(x) == 0x8000);

    x = 0x6600;
    printf("leftmost_one(0x%.8X) = 0x%.8X\n", x, leftmost_one(x));
    assert(leftmost_one(x) == 0x4000);

    x = 0x0;
    printf("leftmost_one(0x%.8X) = 0x%.8X\n", x, leftmost_one(x));
    assert(leftmost_one(x) == 0);

    return 0;
}