// 13. 编写一个程序，反序显示命令行参数的单词。
// 例如，命令行参数是 see you later，该程序应打印later you see。
#include <stdio.h>

int main(int argc, char * argv[])
{
  int i;
  for (i = 0; i < argc - 1; i++)
  {
    printf("%s",argv[argc - 1 - i]);
    if (i < argc - 2)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}