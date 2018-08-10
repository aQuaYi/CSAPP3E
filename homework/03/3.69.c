#include <stdio.h>

#define CNT 7

typedef struct
{
    // 无论 idx 的类型为 char、short、int 或 long
    // 最后的 sizeof(b) 都是 0x128

    // char idx;
    // short idx;
    // int idx;
    long idx;
    long x[4];
} a_struct;

typedef struct
{
    int first;
    a_struct a[CNT];
    int last;
} b_struct;

void test(long i, b_struct *bp)
{
    int n = bp->first + bp->last;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}

typedef struct
{
    char idx;
    long nums[CNT];
} char_index;

long test_char_index(char_index *ci)
{
    /**
     * 运行 gcc -Og 3.69.c -S 查看本函数的汇编代码，可知
     * ci->idx 的汇编指令是 movsbq	(%rdi), %rax
     * 虽然 ci->idx 是 char 型数据，但还是复制到 %rax 寄存器中
     * 可知 a[i] 会隐含地把 i 转换成 long 类型 
     */
    return ci->nums[ci->idx];
}

int main(int argc, char const *argv[])
{
    a_struct a;
    b_struct b;
    printf("sizeof(a.idx) = %ld\n", sizeof(a.idx));
    printf("sizeof(a) = %ld\n", sizeof(a));
    printf("sizeof(b) = 0x%lX\n", sizeof(b));
    return 0;
}