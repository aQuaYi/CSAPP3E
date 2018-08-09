#include <stdio.h>

union ele {
    struct
    {
        long *p;
        long y;
    } e1;
    struct
    {
        long x;
        union ele *next;
    } e2;
};

void proc(union ele *up)
{
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;
}

int main(int argc, char const *argv[])
{
    union ele up;
    up.e1.y = 0;
    up.e2.x = 1;
    printf("up.e1.y = %ld\nup.e2.x = %ld\n", up.e1.y, up.e2.x);
    return 0;
}