#include <stdio.h>

typedef unsigned packed_t;

/**
 * Extract byte from word. Return as signed integer 
 */

int xbyte(packed_t word, int bytenum)
{
    int size = sizeof(int);
    int move_left = (size - 1 - bytenum) << 3;
    int move_right = (size - 1) << 3;
    return (int)word << move_left >> move_right;
}

int main()
{

    packed_t word = 0x5678abcd;
    int bytenum = 0;
    printf("xbyte(0x%x, %d) = 0x%08x\n", word, bytenum, xbyte(word, bytenum));

    bytenum = 1;
    printf("xbyte(0x%x, %d) = 0x%08x\n", word, bytenum, xbyte(word, bytenum));

    bytenum = 2;
    printf("xbyte(0x%x, %d) = 0x%08x\n", word, bytenum, xbyte(word, bytenum));

    bytenum = 3;
    printf("xbyte(0x%x, %d) = 0x%08x\n", word, bytenum, xbyte(word, bytenum));

    return 0;
}
