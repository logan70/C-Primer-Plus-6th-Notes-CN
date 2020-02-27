// proto.c - 使用函数原型
#include <stdio.h>
int imax(int, int); /* 函数原型 */
int main(void)
{
  printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3, 5));
  printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
  return 0;
}
int imax(int n, int m)
{
  return (n > m ? n : m);
}