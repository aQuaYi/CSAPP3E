#include <stdio.h>

long cread_alt(long *xp)
{
    long result = 0;
    if (xp)
    {
        result = *xp;
    }
    return result;
}