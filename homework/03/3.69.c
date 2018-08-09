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

int main(int argc, char const *argv[])
{
    a_struct a;
    b_struct b;
    printf("sizeof(a.idx) = %ld\n", sizeof(a.idx));
    printf("sizeof(a) = %ld\n", sizeof(a));
    printf("sizeof(b) = 0x%lX\n", sizeof(b));
    return 0;
}