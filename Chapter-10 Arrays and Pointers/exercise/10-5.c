// 5. 编写一个函数，返回储存在double类型数组中最大值和最小值的差值，
// 并在一个简单的程序中测试该函数。
#include <stdio.h>
double get_diff(double ar[], int n);

int main(void)
{
  printf("The biggest value in [2.3, 1.8, 3.5] minus the smallest one,"
  " the result is: %.1f\n",
  get_diff((double []){ 2.3, 1.8, 3.5 }, 3));
  return 0;
}

double get_diff(double ar[], int n)
{
  int i;
  double max, min;
  for (i = 0, max = ar[i], min = ar[i]; i < n; i++)
  {
    if (ar[i] > max)
    max = ar[i];
    if (ar[i] < min)
    min = ar[i];
  }
  return max - min;
}