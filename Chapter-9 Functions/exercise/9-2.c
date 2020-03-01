// 2. 设计一个函数chline(ch, i, j)，打印指定的字符j行i列。
// 在一个简单的驱动程序中测试该函数。
#include <stdio.h>

void chline(char ch, int rows, int cols);
int main(void)
{
  chline('*', 2, 10);
  return 0;
}

void chline(char ch, int rows, int cols)
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    putchar(ch);
    putchar('\n');
  }
}