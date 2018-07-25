#include <stdio.h>
#include <assert.h>
#include <limits.h>

/**
 * Addtion that saturates to TMin or TMax 
 */
int saturating_add(int x, int y)
{
    int sum = x + y;
    int sig_mask = INT_MIN;

    int x_is_neg = x & sig_mask;
    int x_is_pos = !x_is_neg && x != 0;
    int y_is_neg = y & sig_mask;
    int y_is_pos = !y_is_neg && y != 0;
    int sum_is_not_neg = !(sum & sig_mask);
    int sum_is_not_pos = (sum & sig_mask) | sum == 0;

    /** 
     * if x > 0, y > 0 but sum <= 0, it's a positive overflow
     * if x < 0, y < 0 but sum >= 0, it's a negetive overflow
     */

    int pos_over = x_is_pos && y_is_pos && sum_is_not_pos;
    int neg_over = x_is_neg && y_is_neg && sum_is_not_neg;

    (pos_over && (sum = INT_MAX)) || (neg_over && (sum = INT_MIN));

    return sum;
}

int main(int argc, char *argv[])
{

    assert(INT_MAX == saturating_add(INT_MAX, 1));
    assert(INT_MIN == saturating_add(INT_MIN, -1));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));

    return 0;
}