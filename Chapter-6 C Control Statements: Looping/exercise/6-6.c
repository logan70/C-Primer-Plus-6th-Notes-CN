// 6. 编写一个程序打印一个表格，每一行打印一个整数、该数的平方、该数的立方。
// 要求用户输入表格的上下限。使用一个for循环。
#include <stdio.h>

int main(void)
{
  int start, end, i;
  printf("Please enter an upper limitand and a lower limit: \n");
  scanf("%d %d", &start, &end);
  printf("number square   cube\n");
  for (i = start; i <= end; i++)
  printf("%6d %6d %6d\n", i, i * i, i * i * i);
  return 0;
}