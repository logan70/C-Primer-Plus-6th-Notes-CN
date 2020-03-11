// 10. 编写一个函数接受一个字符串作为参数，并删除字符串中的空格。
// 在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行。
// 该程序应该应用该函数只每个输入的字符串，并显示处理后的字符串。
#include <stdio.h>
#define LIM 40
char * s_gets(char * st, int n);
void del_blank(char *st);

int main(void)
{
  char st[LIM];
  printf("Enter a string: ");
  while (s_gets(st, LIM -1) && st[0] != '\0')
  {
    printf("Before delete blank: \n %s\n", st);
    del_blank(st);
    printf("After delete blank: \n %s\n", st);
    printf("Enter next string(blank line to quit): ");
  }
  puts("Done.");
  return 0;
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  int i = 0;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    while (st[i] != '\n' && st[i] != '\0')
      i++;
    if (st[i] == '\n')
      st[i] = '\0';
    else
      while (getchar() != '\n')
      continue;
  }
  return ret_val;
}

void del_blank(char * st)
{
  char * pt;
  while (*st) {
    if (*st == ' ')
    {
      pt = st;
      do
      {
        *pt = *(pt + 1);
      } while (*++pt);
    }
    else
      st++;
  }
}