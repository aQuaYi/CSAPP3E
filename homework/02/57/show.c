/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */
#include <stdlib.h>
#include <string.h>
/* $begin show-bytes */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]); //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_double(double x)
{
    show_bytes((byte_pointer)&x, sizeof(double)); //line:data:show_bytes_amp3
}
/* $end show-bytes */

/* $begin test-show-bytes */
void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int pval = (double)ival;
    show_int(ival);
    show_float(fval);
    show_double(pval);
}
/* $end test-show-bytes */

int main(int argc, char *argv[])
{
    int val = 0x12345678;

    printf("show %d == 0x%x\n", val, val);
    printf("int     : ");
    show_int(val);

    printf("float   : ");
    show_float(val);

    printf("double  : ");
    show_double(val);
}
