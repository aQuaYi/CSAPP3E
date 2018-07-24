/*
 * @Author: aQua Yi
 * @Date: 2018-07-24 15:21:53
 * @LastEditors: aQua Yi
 * @LastEditTime: 2018-07-24 15:22:35
 */
#include <stdio.h>
#include <assert.h>

int int_shifts_are_arithmetic()
{
    int x = -1;
    // -1 >> 1 == -1
    // int32: -1 == 0xFFFFFFFF
    return !~(x >> 1);
}

int main(int argc, char const *argv[])
{
    assert(int_shifts_are_arithmetic());

    if (int_shifts_are_arithmetic())
    {
        printf("int shifts are arithmetic\n");
    }
    else
    {
        printf("int shifts are NOT arithmetic\n");
    }

    return 0;
}