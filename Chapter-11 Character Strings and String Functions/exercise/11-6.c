// 6. 编写一个名为is_within()的函数，接受一个字符和一个指向字符串的指针作为两个函数
// 形参。如果指定字符在字符串中，该函数返回一个非零值 （即为真）。
// 否则，返回0（即为假）。在一个完整的程序中测试该函数， 使用一个循环给函数提供输入值。
#include <stdio.h>
#define LIM 40
int is_within(char ch, char * st);
char * s_gets(char * st, int n);

int main(void)
{
  char str[LIM];
  char ch;
  int index;
  puts("Enter a string, please(blank line to quit):");
  while (s_gets(str, LIM - 1) && str[0] != '\0')
  {
    printf("Enter the character you want to find:");
    ch = getchar();
    while (getchar() != '\n')
    continue;
    index = is_within(ch, str);
    if (index)
      printf("%c is the %d character of \"%s\"\n", ch, index + 1, str);
    else
      printf("%c is not found in \"%s\"\n", ch, str);
    printf("Enter a string(blank line to quit):");
  }
  printf("Done.\n");
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

int is_within(char ch, char * str)
{
  int i = 0;
  while (*str && *str != ch)
  {
    str++;
    i++;
  }
  return *str ? i : 0; 
}