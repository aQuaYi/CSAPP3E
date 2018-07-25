#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

/**
 * Extract byte from word. Return as signed integer 
 */

int xbyte(packed_t word, int bytenum)
{
    /** return (word >> (bytenum << 3)) & 0xFF;
     * 以上的错误之处在于，没有处理每个字节的符号位
     * 导致每个分离出来的数都是正数 
     */
    int size = sizeof(int);
    int move_left = (size - 1 - bytenum) << 3;
    int move_right = (size - 1) << 3;
    return (int)word << move_left >> move_right;
}

int main()
{

    packed_t word = 0x5678abcd;
    int bytenum = 0;
    printf("xbyte(0x%X, %d) = 0x%08X\n", word, bytenum, xbyte(word, bytenum));
    assert(xbyte(word, bytenum) == 0xffffffcd);

    bytenum = 1;
    printf("xbyte(0x%X, %d) = 0x%08X\n", word, bytenum, xbyte(word, bytenum));
    assert(xbyte(word, bytenum) == 0xffffffab);

    bytenum = 2;
    printf("xbyte(0x%X, %d) = 0x%08X\n", word, bytenum, xbyte(word, bytenum));
    assert(xbyte(word, bytenum) == 0x00000078);

    bytenum = 3;
    printf("xbyte(0x%X, %d) = 0x%08X\n", word, bytenum, xbyte(word, bytenum));
    assert(xbyte(word, bytenum) == 0x00000056);

    return 0;
}
