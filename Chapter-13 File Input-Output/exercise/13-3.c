// 3. 编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作为原始文件名
// 和输出文件名。该程序要使用ctype.h中的 toupper()函数，在写入到输出文件时
// 把所有文本转换成大写。使用标准I/O和文本模式。
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LIM 80
char * s_gets(char * st, int n);

int main(void)
{
  FILE *fp;
  char file[LIM];
  char ch;
  printf("Enter file name: ");
  while (s_gets(file, LIM) && file[0] != '\0')
  {
    if ((fp = fopen(file, "r+")) == NULL)
    {
      fprintf(stderr, "Could not open %s.\n", file);
      exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
      fseek(fp, -1L, SEEK_CUR);
      putc(toupper(ch), fp);
    }
    rewind(fp);
    printf("file content:\n");
    while ((ch = getc(fp)) != EOF)
      putchar(ch);
    printf("\nEnter file name(new line to quit): ");
  }
  puts("Done.");
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