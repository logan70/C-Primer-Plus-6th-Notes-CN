// 3.编写一个函数，接受3个参数：一个字符和两个整数。
// 字符参数是待打印的字符，第1个整数指定一行中打印字符的次数，
// 第2个整数指定打印指定字符的行数。编写一个调用该函数的程序。
#include <stdio.h>

void myprint(char ch, int cols, int rows);

int main(void)
{
  myprint('*', 10, 5);
  return 0;
}

void myprint(char ch, int cols, int rows)
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    putchar(ch);
    putchar('\n');
  }
}