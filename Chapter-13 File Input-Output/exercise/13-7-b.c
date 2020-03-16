// 7. 编写一个程序打开两个文件。可以使用命令行参数或提示用户输入文 件名。
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  FILE *fp1, *fp2;
  char ch;
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s filename1 filename2\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((fp1 = fopen(argv[1], "r")) == NULL)
  {
    fprintf(stderr, "Could open %s.\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fp2 = fopen(argv[2], "r")) == NULL)
  {
    fprintf(stderr, "Could open %s.\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  while (!feof(fp1) || !feof(fp2))
  {
    while (!feof(fp1)  && (ch = getc(fp1)))
    {
      if (ch == '\n' || ch == EOF)
        break;
      else
        putc(ch, stdout);
    }
    while (!feof(fp2)  && (ch = getc(fp2)))
    {
      if (ch == '\n' || ch == EOF)
        break;
      else
        putc(ch, stdout);
    }
    putchar('\n');
  }
}