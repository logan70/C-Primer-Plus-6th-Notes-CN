// 8. 编写一个程序，要求用户输入两个浮点数，并打印两数之差除以两数乘积的结果。
// 在用户输入非数字之前，程序应循环处理用户输入的每对值。
#include <stdio.h>

int main(void)
{
  double num1, num2;
  int valid;
  printf("Enter two float numbers: \n");
  while (scanf("%lf %lf", &num1, &num2) == 2)
  {
    printf("%.2f\n", (num1 - num2) / (num1 * num2));
    printf("Enter next two float numbers(non-numeric to quit): \n");
  }
  return 0;
}
