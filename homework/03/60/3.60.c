
#include <stdio.h>

long loop_me(long x, int n)
{
    long result = 0;
    long mask;

    for (mask = 1; mask != 0; mask = mask << n)
    {
        result |= x & mask;
    }

    return result;
}