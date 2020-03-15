// 5. 修改程序清单13.5中的程序，用命令行界面代替交互式界面。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append (FILE *source, FILE *dest);
char * s_gets(char * st, int n);
int main(int argc, char * argv[])
{
  FILE *fa, *fs; // fa指向目标文件，fs指向源文件
  int ch;
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s destinationfile sourcefile\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((fa = fopen(argv[1], "a+")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
  {
    fputs("Can't create output buffer\n", stderr);
    exit(EXIT_FAILURE);
  }
  if (strcmp(argv[2], argv[1]) == 0)
  {
    fputs("Can't append file to itself\n", stderr);
    exit(EXIT_FAILURE);
  }
  else if ((fs = fopen(argv[2], "r")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  else
  {
    if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
    {
      fputs("Can't create input buffer\n", stderr);
      exit(EXIT_FAILURE);
    }
    append(fs, fa);
    if (ferror(fs) != 0)
      fprintf(stderr, "Error in reading file %s.\n", argv[2]);
    if (ferror(fa) != 0)
      fprintf(stderr, "Error in writing file %s.\n", argv[1]);
    fclose(fs);
    printf("File %s appended.\n", argv[2]);
    puts("Next file (empty line to quit):");
  }
  rewind(fa);
  printf("%s contents:\n", argv[1]);
  while ((ch = getc(fa)) != EOF)
    putchar(ch);
  puts("\nDone displaying.");
  fclose(fa);
  return 0;
}

void append(FILE *source, FILE *dest)
{
  size_t bytes;
  static char temp[BUFSIZE]; // 只分配一次
  while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
    fwrite(temp, sizeof(char), bytes, dest);
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