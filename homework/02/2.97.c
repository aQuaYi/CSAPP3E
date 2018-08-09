#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "float-bits.h"

/** Compute (float) f. 
*/
float_bits float_i2f(int i)
{

    // 0 是 int 中的唯一的非规格化数，单独处理
    if (i == 0)
    {
        return 0x0;
    }

    // 由于 -INT_MIN = INT_MIN
    // 后面的 M 无法正确表示，单独处理
    if (i == INT_MIN)
    {
        return 0xCF000000;
    }

    unsigned sign = i < 0 ? 1 : 0;
    unsigned M = i < 0 ? -i : i;
    unsigned E = 0;

    unsigned t = M;
    while (t > 1)
    {
        t >>= 1;
        E++;
    }

    // 左移或者右移 M，使得 (1<<23) <= M < (1<<24)
    if (E <= 23) // float 可以精确表示 int
    {
        M <<= 23 - E;
    }
    else // E > 23， 需要进行取舍
    {
        unsigned tail_length = E - 23;
        unsigned tail_mask = (unsigned)-1 >> (32 - tail_length);
        unsigned tail = tail_mask & M;
        // lsb = Least Significant Bit ， 最低有效位
        unsigned lsb_is_one = (M >> tail_length) & 1;
        unsigned half_lsb = 1 << (tail_length - 1);
        unsigned round_to_even = (lsb_is_one && tail >= half_lsb) ||
                                 (!lsb_is_one && tail > half_lsb);
        M >>= tail_length;
        M += round_to_even;
        if (M == 1 << 24)
        {
            // M >>= E - 23 后，(1<<23) <= M < (1<<24)
            // 但，M += round_to_even 有可能使得 M 的最高位进一
            // 导致 M == 1 << 24 ， 例如 i = INT_MAX 就会发生这种情况
            // 为了使得 (1<<23) <= M < (1<<24)
            M >>= 1;
            E++;
        }
    }

    unsigned exp = E + 127;
    unsigned frac = M - (1 << 23);

    return sign << 31 | exp << 23 | frac;
}

int main(int argc, char const *argv[])
{

    for (int i = INT_MIN; i <= INT_MAX; i++)
    {
        printf("float_i2f(%d) = 0x%.8X, expected = 0x%.8X\n", i, float_i2f(i), f2fd((float)i));
        assert(float_i2f(i) == f2fd((float)i));
    }

    return 0;
}