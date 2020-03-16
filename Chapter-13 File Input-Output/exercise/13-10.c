// 10. 编写一个程序打开一个文本文件，通过交互方式获得文件名。
// 通过一个循环，提示用户输入一个文件位置。然后该程序打印从该位置开始到
// 下一个换行符之前的内容。用户输入负数或非数值字符可以结束输入循环。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 80
void show_content(FILE * fp, long offset);
char * s_gets(char * st, int n);

int main(void)
{
  FILE *fp;
  char file[LIM];
  long offset;
  printf("Enter name of file: ");
  if (s_gets(file, LIM) && file[0] != '\0')
  {
    if ((fp = fopen(file, "r")) == NULL)
    {
      fprintf(stderr, "Could not open %s.\n", file);
      exit(EXIT_FAILURE);
    }
    printf("Enter the start position: ");
    while (scanf("%ld", &offset) == 1 && offset >= 0L)
    {
      show_content(fp, offset);
      printf("Enter the start position (q to quit): ");
    }
    puts("Done.");
  }
  else
  {
    fprintf(stderr, "Invalid file name.");
    exit(EXIT_FAILURE);
  }
  return 0;
}

void show_content(FILE * fp, long offset)
{
  char ch;
  fseek(fp, offset, SEEK_SET);
  printf("File content:\n");
  while ((ch = getc(fp)) != EOF)
    putchar(ch);
  putchar('\n');
}


char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    find = strchr(st, '\n');
    if (find)
      *find = '\0';
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}