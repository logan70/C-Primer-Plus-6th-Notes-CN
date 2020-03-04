// 9. 使用递归函数重写编程练习8
#include <stdio.h>
#include <stdlib.h>

double power(double num, int n);

int main(void)
{
  printf("%.2g ^ %d = %.2g\n", 0.0, 0, power(0.0, 0));
  printf("%.2g ^ %d = %.2g\n", 0.0, 10, power(0.0, 10));
  printf("%.2g ^ %d = %.2g\n", 10.0, 0, power(10.0, 0));
  printf("%.2g ^ %d = %.2g\n", 10.0, 3, power(10.0, 3));
  printf("%.2g ^ %d = %.2g\n", 10.0, -3, power(10.0, -3));
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
  else if (n > 0)
    for (i = 0, res = 1; i < n; i++)
    res *= num;
  else
    res = power(num, -n);
  return res;
}