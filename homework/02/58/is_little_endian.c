#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

int show_bytes(byte_pointer start)
{
    return (int)start[0];
}

int is_little_endian()
{
    int x = 0x1234;
    return 0x34 == show_bytes((byte_pointer)&x);
}

void main(int argc, char *argv[])
{
    printf("This system is little endian: %d\n", is_little_endian());
}
