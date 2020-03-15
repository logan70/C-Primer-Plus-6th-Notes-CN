// 1. 修改程序清单13.1中的程序，要求提示用户输入文件名，
// 并读取用户输入的信息，不使用命令行参数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 81
char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{
  int ch; // 读取文件时，储存每个字符的地方
  FILE *fp; // 文件指针
  unsigned long count = 0;
  char filename[LIM];
  printf("Enter the name of file: ");
  while ((s_gets(filename, LIM)) && filename[0] != '\0')
  {
    if ((fp = fopen(filename, "r")) == NULL)
    {
      printf("Can't open %s\n", filename);
      exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
      putc(ch, stdout); // 与putchar(ch);相同
      count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters\n", filename, count);
    fputs("Enter the name of file: (new line to quit)\n", stdout);
  }
  puts("Done");
  return 0;
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    if ((find = strchr(ret_val, '\n')))
      *find = '\0';
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}
