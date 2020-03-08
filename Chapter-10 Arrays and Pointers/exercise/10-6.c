// 6. 编写一个函数，把double类型数组中的数据倒序排列，
// 并在一个简单的程序中测试该函数。
#include <stdio.h>
void printArr(double ar[], int n);
void reverseArr(double source[], double target[], int n);

int main(void)
{
  double ar[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target[5];
  reverseArr(ar, target, 5);
  printf("source: ");
  printArr(ar, 5);
  printf("after reversed: ");
  printArr(target, 5);
  return 0;
}

void reverseArr(double source[], double target[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  target[n - 1 - i] = source[i];
}

void printArr(double ar[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  printf("%.1f ", ar[i]);
  putchar('\n');
}
