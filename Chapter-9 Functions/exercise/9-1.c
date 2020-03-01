// 1. 设计一个函数min(x, y)，返回两个double类型值的较小值。
// 在一个简单 的驱动程序中测试该函数。
#include <stdio.h>

double min (double x, double y);
int main(void)
{
  double num1 = 10.0, num2 = 9.9, res;
  res = min(num1, num2);
  if (res == num2)
  printf("9.9 is less than 10.0, Correct!\n");
  else
  printf("Wrong");
  return 0;
}

double min(double x, double y)
{
  return x > y ? y : x;
}