// subst.c - 在字符串中替换
#include <stdio.h>
#define PSQR(x) printf("The square of " #x " is %d.\n", ((x)*(x)));

int main(void)
{
  int y = 5;
  PSQR(y);
  PSQR(2 + 4);
  return 0;
}