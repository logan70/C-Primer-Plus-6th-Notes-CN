// 1. 设计并测试一个函数，从输入中获取下n个字符（包括空白、制表 符、换行符），
// 把结果储存在一个数组里，它的地址被传递作为一个参数。
#include <stdio.h>
#define LIM 40
char * get_chars(char * st, int n);

int main(void)
{
  char string[LIM];
  char * check;
  printf("Enter %d characters, please:\n", LIM - 1);
  check = get_chars(string, LIM - 1);
  if (check)
    printf("Your input is:\n %s\n", string);
  else
    puts("Input error!");
  return 0;
}

char * get_chars(char * st, int n){
  int i, ch;
  for (i = 0; i < n; i++)
  {
    ch = getchar();
    if (ch == EOF)
      break;
    else
      *(st + i) = ch;
  }
  return (ch == EOF && i == 0) ? NULL : st;
}