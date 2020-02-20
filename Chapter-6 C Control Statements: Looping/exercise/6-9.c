// 9. 修改练习8，使用一个函数返回计算的结果。
#include <stdio.h>

double getResult(double num1, double num2);

int main(void)
{
  double num1, num2;
  int valid;
  printf("Enter two float numbers: \n");
  while (scanf("%lf %lf", &num1, &num2) == 2)
  {
    printf("%.2f\n", getResult(num1, num2));
    printf("Enter next two float numbers(non-numeric to quit): \n");
  }
  return 0;
}

double getResult(double num1, double num2)
{
  return (num1 - num2) / (num1 * num2);
}
