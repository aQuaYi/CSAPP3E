#include <stdio.h>

long cread_alt(long *xp)
{
    return (!xp ? 0 : *xp);
}