// 5.设计并测试一个函数，搜索第1个函数形参指定的字符串，
// 在其中查找第2个函数形参指定的字符首次出现的位置。
// 如果成功，该函数返指向该字符的指针，如果在字符串中未找到指定字符，
// 则返回空指针（该函数的功能与strchr()函数相同）。
// 在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
#include <stdio.h>
#define MESSAGE "Be the best you can be"
char * strchr(char * st, char ch);

int main(void)
{
  char * start = MESSAGE;
  char * pt = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char * chp;

  printf("MESSAGE = \"%s\"\n", MESSAGE);
  while (*pt)
  {
    chp = strchr(MESSAGE, *pt);
    if (chp)
      printf("char = %c, address = %p\n", *chp, chp);
    else
      printf("'%c' not found in MESSAGE.\n", *pt);
    pt++;
  }
  return 0;
}

char * strchr(char * st, char ch)
{
  char * pt;
  while (*st && ch != *st)
  st++;
  return *st ? st : NULL;
}
