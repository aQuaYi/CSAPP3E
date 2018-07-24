#include "show-bytes.h"

int main(int argc, char const *argv[])
{
    int N = 99;

    int a[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i * 3;
    }

    for (int i = 0; i < N; i++)
    {
        show_bytes((byte_pointer)&a[i], sizeof(int));
    }

    return 0;
}
