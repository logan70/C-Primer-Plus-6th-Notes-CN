// 4. 两数的调和平均数这样计算：先得到两数的倒数，
// 然后计算两个倒数的平均值，最后取计算结果的倒数。
// 编写一个函数，接受两个double类型的参数，
// 返回这两个参数的调和平均数。
#include <stdio.h>

double getHarmonicAverage(double x, double y);

int main(void)
{
  double res;
  res = getHarmonicAverage(10.0, 20.0);
  printf("The harmonic average of 10.0 and 20.0 is %.2f", res);
  return 0;
}

double getHarmonicAverage(double x, double y)
{
  double recx = 1 / x, recy = 1 / y;
  return 1 / ((recx + recy) / 2);
}