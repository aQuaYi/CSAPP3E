#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef enum
{
    NEG,  // 0
    ZERO, // 1
    POS,  // 2
    OTHER // 3
} range_t;

range_t find_range(float x)
{
    __asm__(
        "movq $1, %rax;"
        "movq $2, %r8;"
        "movq $0, %r9;"
        "movq $3, %r10;"
        "vxorps %xmm1, %xmm1, %xmm1;"
        "vucomiss %xmm1, %xmm0;"
        "cmovaq %r8, %rax;"
        "cmovbq %r9, %rax;"
        "cmovpq %r10, %rax;");
    // 汇编代码中用到的寄存器 %rax, %r8, %r9, %r10
    // 都是调用者保存寄存器，所以，不用保护寄存器中已有的数据
}

int main(int argc, char *argv[])
{
    range_t n = NEG, z = ZERO, p = POS, o = OTHER;

    assert(o == find_range(0.0 / 0.0));
    assert(o == find_range(-0.0 / 0.0));

    assert(n == find_range(-2.3));
    assert(z == find_range(0.0));
    assert(p == find_range(3.33));

    printf("Done.\n");

    printf("checking [-2^31, -1]\n");
    for (float f = -1; f >= INT_MIN; f--)
    {
        assert(n == find_range(f));
    }

    printf("checking [1, 2^31)\n");
    for (float f = 1; f <= INT_MAX; f++)
    {
        assert(p == find_range(f));
    }

    return 0;
}