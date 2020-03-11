// 9. 编写一个函数，把字符串中的内容用其反序字符串代替。
// 在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
#include <stdio.h>
#include <string.h>
#define LEN 81

void reverse_str(char * str);
char * s_gets(char * st, int n);

int main (void)
{
  char string[LEN];

  puts("Enter the string to reverse: ");
  while(s_gets(string,LEN) != NULL && string[0] != '\0')
  {
    reverse_str(string);
    puts(string);
    puts("Enter the string to reverse(enter a new line to quit): ");
  }
  puts("Done.");
  return 0;
}

void reverse_str(char * str)
{
  char temp;
  int len = strlen(str);
  int i;
  for (i = 0; i < len / 2; i++)
  {
    temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
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