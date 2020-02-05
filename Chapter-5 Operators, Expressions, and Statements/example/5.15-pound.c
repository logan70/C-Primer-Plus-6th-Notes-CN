// pound.c - 定义一个带参数的函数
#include <stdio.h>

void pound(int n); // ANSI函数原型声明

int main(void)
{
  int times = 5;
  char ch = '!'; // ASCII码是33
  float f = 6.0f;
  pound(times); // int类型参数
  pound(ch); // 和pound((int)ch);相同
  pound(f); // 和pound((int)f);相同
  return 0;
}

void pound(int n) // ANSI风格函数头，该函数接受一个int类型的参数
{
  while (n-- > 0)
  printf("#");
  printf("\n");
}