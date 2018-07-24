#include "showBytes.h"
int main(int argc, char const *argv[])
{
    int ival = 0x12345678;
    float fval = (float)ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);

    return 0;
}
