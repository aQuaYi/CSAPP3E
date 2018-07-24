#include <stdio.h>

int is_little_endian()
{
    int x = 1;
    char *p = (char *)&x;
    return p[0] == 1;
}

int main(int argc, char const *argv[])
{
    if (is_little_endian())
    {
        printf("This machine is little endian\n");
    }
    else
    {
        printf("This machine is big endian\n");
    }
    return 0;
}
