// 编写一个名为string_in()的函数，接受两个指向字符串的指针作为参数。
// 如果第2个字符串中包含第1个字符串，该函数将返回第1个字符串开始的地址。
// 例如，string_in("hats","at")将返回hats中a的地址。否则，该函数返回空指针。
// 在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
#include <stdio.h>
#define LIM 80

char * s_gets(char * st, int n);
char * string_in(char * s1, char * s2);

int main(void)
{
  char s1[LIM];
  char s2[LIM];
  char * pt;
  printf("Enter the first string: ");
  while (s_gets(s1, LIM - 1) && s1[0] != '\0')
  {
    printf("Enter the second string: ");
    while (!s_gets(s2, LIM - 1) || s2[0] == '\0')
    printf("Enter the second string: ");
    if ((pt = string_in(s1, s2)) != NULL)
    printf("'%s' is a part of '%s', start from %c, %p\n", s2, s1, *pt, pt);
    printf("Enter the first string(blank line to quit): ");
  }
  printf("Done.\n");
  return 0;
}

char * s_gets(char *st, int n)
{
  char * ret_val;
  int i = 0;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    while (st[i] != '\0' && st[i] != '\n')
      i++;
    if (st[i] == '\n')
      st[i] = '\0';
    else
      while (getchar() != '\n') 
        continue;
  }
  return ret_val;
}

char * string_in(char * s1, char * s2)
{
  int count;
  while (*s1)
  {
    count = 0;
    while (*(s2 + count) && *(s2 + count) == *(s1 + count))
    count++;
    if (*(s2 + count) == '\0')
      return s1;
    s1++;
  }
  return NULL;
}
