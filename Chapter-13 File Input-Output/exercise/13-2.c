// 2. 编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名。
// 尽量使用标准I/O和二进制模式。
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 256

void copy_file(FILE *source, FILE *dest);

int main(int argc, char * argv[])
{
  FILE *fp1;
  FILE *fp2;
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s sourcefile destinationfile\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((fp1 = fopen(argv[1], "r")) == NULL)
  {
    fprintf(stderr, "Could not open %s.\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fp2 = fopen(argv[2], "w")) == NULL)
  {
    fprintf(stderr, "Could not open %s.\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  copy_file(fp1, fp2);
  // 收尾工作
  if(fclose(fp1) != 0 || fclose(fp2) != 0)
    fprintf(stderr, "Error in closing files\n");
  return 0;
}

void copy_file(FILE *source, FILE *dest)
{
  static char temp[BUFSIZE];
  size_t bytes;
  while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
    fwrite(temp, sizeof(char), bytes, dest);
}