// recur.c - 递归演示
#include <stdio.h>
void up_and_down(int);
int main(void)
{
  up_and_down(1);
  return 0;
}

void up_and_down(int n)
{
  printf("Level %d: nlocation %p\n", n, &n);
  if (n < 4)
  up_and_down(n + 1);
  printf("LEVEL %d: n location %p\n", n, &n);
}