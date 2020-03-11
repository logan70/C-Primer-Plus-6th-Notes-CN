// 16. 编写一个程序读取输入，直至读到文件结尾，然后把字符串打印出来。
// 该程序识别和实现下面的命令行参数：
// -p 按原样打印
// -u 把输入全部转换成大写
// -l 把输入全部转换成小写
// 如果没有命令行参数，则让程序像是使用了-p参数那样运行。
#include <stdio.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
  char mode, ch;
  int valid = 0;
  if (argc > 2)
    printf("Usage: %s [-p | -u | -l]\n", argv[0]);
  else if (argc == 2)
  {
    if (argv[1][0] == '-')
    {
      mode = argv[1][1];
      if (mode == 'p' || mode == 'u' || mode == 'l')
        valid = 1;
    }
    else
    {
      printf("Usage: %s [-p | -u | -l]\n", argv[0]);
    }
  }
  else
  {
    mode = 'p';
    valid = 1;
  }
  
  if (!valid)
    return 0;
  while ((ch = getchar()) != EOF)
  {
    switch (mode)
    {
    case 'p':
      putchar(ch);
      break;
    case 'u':
      putchar(toupper(ch));
      break;
    case 'l':
      putchar(tolower(ch));
      break;
    default:
      break;
    }
  }
  printf("\n");
  return 0;
}