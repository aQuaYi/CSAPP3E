#include <stdio.h>
#include <assert.h>

/**Return 1 when x contains an odd number of 1s; 0 otherwise. 
 * Assume w=32
*/

int odd_ones(unsigned x)
{

    /**下面的 odd_ones_2 是最直接的方法，
     * 可以看到统计了各个位上的 1 后，返回的后果是 res & 1
     * 也就是说 res 只有最低位是有用的
     * 
     * 如果只看最低位的话
     * 1 bit 的二进制加法 和 1 bit 的异或运算 的结果是一样的。
     * 
     * 下面 5 次运算，就是不断对折，然后两两位进行异或运算
     * 
     * 最后，x 的最低位 和 res 的最低位绝对是一样的。
     * 返回的结果是 x & 1
     */

    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 1;
}

int odd_ones_2(unsigned x)
{
    unsigned res = 0;

    for (int i = 0; i < 32; i++)
    {
        res += x & 1;
        x >>= 1;
    }

    return res & 1;
}

int main(int argc, char const *argv[])
{

    for (unsigned i = 0; i < 1 << 31; i += 1021)
    {
        int a = odd_ones(i);
        int b = odd_ones_2(i);
        assert(a == b);
        printf("%.8X with %d ones\n", i, b);
    }

    unsigned x = 0x10101010;
    printf("odd_ones(%.8X) = %d\n", x, odd_ones(x));

    x = 0x10101011;
    printf("odd_ones(%.8X) = %d\n", x, odd_ones(x));

    return 0;
}