// 11. 编写并测试Fibonacci()函数，该函数用循环代替递归计算斐波那契数。
#include <stdio.h>

void Fibonacci(int count);

int main(void)
{
  Fibonacci(10);
  return 0;
}

void Fibonacci(int count)
{
  int i;
  int prev, cur, temp;
  for (i = 1; i <= count; i++)
  {
    if (i == 1)
    {
      prev = 0;
      cur = 1;
    } else {
      temp = prev + cur;
      prev = cur;
      cur = temp;
    }
    printf("%d ", cur);
  }
  printf("\nDone.\n");
}