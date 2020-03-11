// 15. 使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，
// 该函数返回0。
#include <stdio.h>
#include <ctype.h>

int my_atoi(char * st);
int get_num(char ch);

int main(void)
{
  printf("my_atoi(\"123\") = %d\n", my_atoi("123"));
  printf("my_atoi(\"123a\") = %d\n", my_atoi("123a"));
  return 0;
}

int my_atoi(char * st)
{
  int num;
  while (*st)
  {
    if (isnumber(*st))
    {
      num = num * 10 + get_num(*st);
      st++;
    }
    else
      return 0;
  }
  return num;
}

int get_num(char ch)
{
  int num;
  switch (ch)
  {
  case '0':
    num = 0;
    break;
  case '1':
    num = 1;
    break;
  case '2':
    num = 2;
    break;
  case '3':
    num = 3;
    break;
  case '4':
    num = 4;
    break;
  case '5':
    num = 5;
    break;
  case '6':
    num = 6;
    break;
  case '7':
    num = 7;
    break;
  case '8':
    num = 8;
    break;
  case '9':
    num = 9;
    break;
  default:
    num = 0;
    break;
  }
  return num;
}