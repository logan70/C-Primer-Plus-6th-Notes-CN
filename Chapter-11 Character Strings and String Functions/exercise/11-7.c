// 7. strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，
// 或者有必要的话在末尾添加空字符。如果s2的长度是n或多于n，目标字符串不能以空字符结尾。
// 该函数返回s1。自己编写一个这样的函数，名为mystrncpy()。
// 在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
#include <stdio.h>
#define LIM 80

char * s_gets(char * st, int n);
char * mystrncpy(char * s1, const char * s2, int n);

int main(void)
{
  char s1[LIM];
  char s2[LIM];
  int n;
  printf("Enter a string: ");
  while (s_gets(s2, LIM - 1) && s2[0] != '\0')
  {
    printf("Enter the number of characters you want to copy(from the start): ");
    scanf("%d", &n);
    while (getchar() != '\n')
      continue;
    mystrncpy(s1, s2, n);
    s1[n] = '\0';
    puts("Copied string is:");
    puts(s1);
    printf("Enter a string(blank line to quit): ");
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

char * mystrncpy(char * s1, const char * s2, int n)
{
  int ct = 0;
  char * val = s1;
  while (*s2 && ct < n)
  {
    *s1++ = *s2++;
    ct++;
  }
  if (ct < n)
  *s1 = '\0';
  return val;
}