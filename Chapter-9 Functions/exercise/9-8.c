// 8.第6章的程序清单6.20中，power()函数返回一个double类型数的正整数次幂。
// 改进该函数，使其能正确计算负幂。另外，函数要处理0的任何次幂都为0，
// 任何数的0次幂都为1（函数应报告0的0次幂未定义，因此把该值处理为1）。
// 要使用一个循环，并在程序中测试该函数。
#include <stdio.h>
#include <stdlib.h>

double power(double num, int n);

int main(void)
{
  power(0, 0);
  power(0, 10);
  power(10.0, 0);
  power(10.0, 3);
  power(10.0, -3);
  return 0;
}

double power(double num, int n)
{
  int i;
  double res;
  if (num == 0) {
    res = n == 0 ? 1 : 0;
  }
  if (n == 0)
    res = 1;
  else
  {
    for (i = 0, res = 1; i < abs(n); i++)
    res *= num;
    if (n < 0 )
    res = 1 / res;
  }
  printf("%.2g ^ %d = %.2g\n", num, n, res);
  return res;
}