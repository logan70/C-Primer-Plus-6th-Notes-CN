// echo_eof.c - 重复输入，直到文件结尾
#include <stdio.h>

int main(void)
{
  int ch;
  while ((ch = getchar()) != EOF)
  putchar(ch + 1);
  return 0;
}
