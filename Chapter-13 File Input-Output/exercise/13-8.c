// 8. 编写一个程序，以一个字符和任意文件名作为命令行参数。
// 如果字符后面没有参数，该程序读取标准输入；
// 否则，程序依次打开每个文件并报告每个文件中该字符出现的次数。
// 文件名和字符本身也要一同报告。程序应包含错误检查，以确定参数数量是否正确
// 和是否能打开文件。如果无法打开文件，程序应报告这一情况，
// 然后继续处理下一个文件。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 256
char * s_gets(char * st, int n);
void srch_char_from_stdin(char ch);
void srch_char_from_files(char ch, int argc, char * argv[]);

int main(int argc, char * argv[])
{
  if (argc  < 2)
  {
    fprintf(stderr, "Usage: %s character [file1] [file2] ...", argv[0]);
    exit(EXIT_FAILURE);
  }
  else if (argc == 2)
    srch_char_from_stdin(argv[1][0]);
  else
    srch_char_from_files(argv[1][0], argc, argv);
  return 0;
}

void srch_char_from_stdin(char ch)
{
  char st[STRLEN];
  char * pt;
  int count;
  printf("Enter a string: ");
  while (s_gets(st, STRLEN) && st[0] != '\0')
  {
    count = 0;
    pt = st;
    while (*pt)
      if (*(pt++) == ch)
        count++;
    printf("String you input has %d %c.\n", count, ch);
    printf("Enter a string (new line to quit): ");
  }
  puts("Done");
}

void srch_char_from_files(char ch, int argc, char * argv[])
{
  FILE *fp;
  int count;
  int i;
  char temp;
  for (i = 2; i < argc; i++)
  {
    if ((fp = fopen(argv[i], "r")) == NULL)
    {
      fprintf(stderr, "Could not open %s.\n", argv[i]);
      continue;
    }
    count = 0;
    while ((temp = getc(fp)) != EOF && temp == ch)
      count++;
    printf("File \"%s\" has %d %c.\n", argv[i], count, ch);
  }
  puts("Done");
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