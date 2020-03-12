// 4. 在一个循环中编写并测试一个函数，该函数返回它被调用的次数。
#include <stdio.h>

void my_fun(void);

int main(void)
{
  for (int i = 0; i < 10; i++)
  my_fun();
  return 0;
}

void my_fun(void)
{
  static int times = 0;
  printf("This function has been called for %d times.\n", ++times);
}