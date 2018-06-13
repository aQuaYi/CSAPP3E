#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian()
{
    int x = 0xff;
    byte_pointer byte_start = (byte_pointer)&x;
    return 0xff == byte_start[0];
}

void main(int argc, char *argv[])
{
    printf("This system is little endian: %d\n", is_little_endian());
}
