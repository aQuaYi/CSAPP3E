#include <stdio.h>
#include <limits.h>

/**
 * Determine whether arguments can be subtracted without overflow
 */

int tsub_ok(int x, int y)
{
    int res = 1;

    (y == INT_MIN) && (res = 0);

    int sub = x - y;
    int pos_over = x > 0 && y < 0 && sub < 0;
    int neg_over = x < 0 && y > 0 && sub > 0;

    res = res && !(pos_over || neg_over);

    return res;
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

    x = 0;
    printf("tsub_ok(0x%08x, 0x%08x) = %d\n", x, INT_MIN, tsub_ok(x, INT_MIN));

    x = 1;
    printf("tsub_ok(0x%08x, 0x%08x) = %d\n", x, INT_MIN, tsub_ok(x, INT_MIN));

    return 0;
}
