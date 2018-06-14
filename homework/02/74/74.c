#include <stdio.h>
#include <limits.h>

/**
 * Determine whether arguments can be subtracted without overflow
 */

int tsub_ok(int x, int y)
{
    int sub = x - y;
    int sig_mask = INT_MIN;
    /**
     * 
     */
}

int main()
{

    int x = 0xffffffff;
    int y = 1;
    printf("tsub_ok(0x%08x, 0x%08x) = %d\n", x, y, tsub_ok(x, y));

    y = -y;
    printf("tsub_ok(0x%08x, 0x%08x) = %d\n", x, y, tsub_ok(x, y));

    x = -x;
    y = -y;
    printf("tsub_ok(0x%08x, 0x%08x) = %d\n", x, y, tsub_ok(x, y));

    y = -y;
    printf("tsub_ok(0x%08x, 0x%08x) = %d\n", x, y, tsub_ok(x, y));

    return 0;
}
