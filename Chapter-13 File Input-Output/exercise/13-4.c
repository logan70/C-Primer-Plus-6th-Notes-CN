// 4. 编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。
// 使用argc控制循环。
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  FILE *fp;
  int i;
  char ch;
  for (i = 1; i < argc; i++)
  {
    if ((fp = fopen(argv[i], "r")) == NULL)
    {
      fprintf(stderr, "Could not open %s.\n", argv[i]);
      exit(EXIT_FAILURE);
    }
    printf("File \"%s\" content:\n", argv[i]);
    while ((ch = getc(fp)) != EOF)
      putc(ch, stdout);
    putchar('\n');
  }
  return 0;
}