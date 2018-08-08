#include <assert.h>
#include <stdio.h>

extern long loop(long x, int n);
extern long loop_me(long x, int n);

int main(int argc, char const *argv[])
{

    long x = 0xABCD4321;
    printf("x =%8ld", x);

    for (int n = 0; n <= 64; n++)
    {
        printf("loop(0x%8lX, %d) = 0x%8lX\n", x, n, loop(x, n));
        assert(loop(x, n) == loop_me(x, n));
    };

    return 0;
}