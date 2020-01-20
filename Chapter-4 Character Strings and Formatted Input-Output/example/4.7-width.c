// width.c - 字段宽度
#include <stdio.h>
#define PAGES 959
#define NEG -959

int main(void)
{
  printf("*%d*\n", PAGES);
  printf("*%2d*\n", PAGES);
  printf("*%10d*\n", PAGES);
  printf("*%-10d*\n", PAGES);
  printf("*%010d*\n", PAGES);
  printf("*%x*\n", PAGES);
  printf("*%#x*\n", PAGES);
  printf("*% d*\n", PAGES);
  printf("*% d*\n", NEG);
  printf("*%+d*\n", PAGES);
  printf("*%+d*\n", NEG);
  return 0;
}
