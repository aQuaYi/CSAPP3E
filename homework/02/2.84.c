#include <stdio.h>
#include <assert.h>

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    // ref: https://github.com/DreamAndDead/CSAPP-3e-Solutions/issues/1
    return (ux << 1 == 0 && uy << 1 == 0) || /* both zeros */
           (sy && ux >= uy) ||               /* y < 0 */
           (!sy && (sx || ux <= uy));        /* y >= 0, */
    // 理解此题，需要弄懂 CSAPP3e P81 第三段中提到的内容
    // "浮点数能够使用整数排序函数来进行排序"
}

int main(int argc, char *argv[])
{

    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-0, 3));
    assert(float_le(-3, 1));
    assert(float_le(-3, 0));
    assert(float_le(-3, -0));
    assert(float_le(-4, 4));

    return 0;
}