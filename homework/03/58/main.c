#include <assert.h>
#include <stdio.h>

extern long decode2(long x, long y, long z);
extern long decode2me(long x, long y, long z);

int main(int argc, char const *argv[])
{

    long count = 10;

    for (long i = 0; i < count; i++)
    {
        for (long j = 0; j < count; j++)
        {

            for (long k = 0; k < count; k++)
            {
                printf("decode2(%ld,%ld,%ld) = %ld\n", i, j, k, decode2(i, j, k));
                assert(decode2(i, j, k) == decode2me(i, j, k));
            }
        }
    };

    return 0;
}