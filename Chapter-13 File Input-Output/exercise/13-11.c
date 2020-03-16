// 11. 编写一个程序，接受两个命令行参数。第1个参数是一个字符串，
// 第2个参数是一个文件名。然后该程序查找该文件，打印文件中包含该字符串的
// 所有行。因为该任务是面向行而不是面向字符的，所以要使用fgets()而不是getc()。
// 使用标准C库函数strstr()（11.5.7节简要介绍过）在每一行中查找指定字符串。
// 假设文件中的所有行都不超过255个字符。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int main(int argc, char * argv[])
{
  FILE *fp;
  char buf[SIZE];
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s string filename.\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[2], "r")) == NULL)
  {
    fprintf(stderr, "Could not open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  while (fgets(buf, SIZE, fp))
  {
    if (strstr(buf, argv[1]) != NULL)
      fputs(buf, stdout);
  }
  puts("\nDone.");
  return 0;
}