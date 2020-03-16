// 6. 使用命令行参数的程序依赖于用户的内存如何正确地使用它们。
// 重写程序清单 13.2 中的程序，不使用命令行参数，而是提示用户输入所需信息。
// reducto.c - 把文件压缩成原来的1/3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
char * s_gets(char * st, int n);
int main(void)
{
  FILE *in, *out;
  int ch;
  char sourcename[LEN];
  char name[LEN];
  int count = 0;
  puts("Enter name of source file");
  s_gets(sourcename, LEN);
  // 设置输入
  if ((in = fopen(sourcename, "r")) == NULL)
  {
    fprintf(stderr, "I couldn't open the file\"%s\"\n", sourcename);
    exit(EXIT_FAILURE);
  }
  puts("Enter name of destination file");
  s_gets(name, LEN);
  // 设置输出
  if ((out = fopen(name, "w")) == NULL)
  {
    fprintf(stderr, "Can't create output file.\n");
    exit(3);
  }
  // 拷贝数据
  while ((ch = getc(in)) != EOF)
    if(count++ % 3 == 0)
      putc(ch, out); // 打印3个字符中的第一个
  // 收尾工作
  if(fclose(in) != 0 || fclose(out) != 0)
    fprintf(stderr, "Error in closing files\n");
  return 0;
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    if ((find = strchr(st, '\n')))
      *find = '\0';
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}