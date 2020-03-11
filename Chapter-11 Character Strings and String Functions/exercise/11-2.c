// 2. 修改并编程练习1的函数，在n个字符后停止，或在读到第1个空白、制表符或换行符时停止，
// 哪个先遇到哪个停止。不能只使用scanf()。
#include <stdio.h>
#include <ctype.h>
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
    puts("No input!");
  return 0;
}

char * get_chars(char * st, int n){
  int i, ch;
  for (i = 0; i < n; i++)
  {
    ch = getchar();
    if (ch == EOF || isspace(ch))
      break;
    else
      *(st + i) = ch;
  }
  return (i == 0) ? NULL : st;
}