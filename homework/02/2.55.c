#include "show-bytes.h"

int main(int argc, char const *argv[])
{
    int ival = 0x12345678;
    show_int(ival);

    byte_pointer p = (byte_pointer)&ival;
    if ((int)*p == 0x12)
    {
        printf("big endian\n");
    }
    else
    {
        printf("little endian\n");
    }

    return 0;
}
