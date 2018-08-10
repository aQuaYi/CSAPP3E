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
        // 把 %xmm1 置零
        "vxorps %xmm1, %xmm1, %xmm1;"
        // 比较 x-0 与 0 的大小
        "vucomiss %xmm1, %xmm0;"
        // 当 x 为 NaN 时
        // vucomiss 会把 CF，ZF 和 PF 全部设置为 1
        // 所以，需要最先运行 jp 命令
        // jb, je, ja 的顺序随意
        "jp .P;"
        "jb .B;"
        "je .E;"
        "ja .A;"
        ".B:;"
        "movl $0, %eax;"
        "jmp .Done;"
        ".E:;"
        "movl $1, %eax;"
        "jmp .Done;"
        ".A:;"
        "movl $2, %eax;"
        "jmp .Done;"
        ".P:;"
        "movl $3, %eax;"
        ".Done:;");
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