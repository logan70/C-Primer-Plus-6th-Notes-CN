// reducto.c - 把文件压缩成原来的1/3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(int argc, char *argv[])
{
  FILE *in, *out;
  int ch;
  char name[LEN];
  int count = 0;
  // 检查命令行参数
  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // 设置输入
  if ((in = fopen(argv[1], "r")) == NULL)
  {
    fprintf(stderr, "I couldn't open the file\"%s\"\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  // 设置输出
  strncpy(name, argv[1], LEN - 5);
  name[LEN - 5] = '\0';
  strcat(name, ".red");
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