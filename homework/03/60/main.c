#include <assert.h>
#include <stdio.h>

extern long loop(long x, int n);
extern long loop_me(long x, int n);

int main(int argc, char const *argv[])
{

  long x = 0xFFFFFFFF;

  for (int n = 1; n < 64; n++)
  {
    printf("loop(0x%8lX, %2d) = 0x%8lX\n", x, n, loop(x, n));
    assert(loop(x, n) == loop_me(x, n));
  };

  return 0;
}