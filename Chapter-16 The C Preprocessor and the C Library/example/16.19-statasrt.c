// statsrt.c - 使用 _Static_assert
#include <stdio.h>
#include <limits.h>
_Static_assert(CHAR_BIT == 16, "16-bix char falsely assumed");

int main(void)
{
  puts("char is 16 bits.");
  return 0;
}