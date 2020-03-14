## 1. 下面的程序有什么问题？

```c
int main(void)
{
  int * fp;
  int k;
  fp = fopen("gelatin");
  for (k = 0; k < 30; ++)
    fputs(fp, "Nanette eats gelatin.");
  fclose("gelatin");
  return 0;
}
```

1. 应包含头文件`#include <stdio.h>`
2. fp应声明为文件指针`FILE *fp;`
3. 要给`fopen()`函数提供一种模式，`fp = fopen("gelatin", "w");`
4. `fputs()`函数两个参数位置调换`fputs("Nanette eats gelatin.", fp);`
5. `fclose()`函数应该传入文件指针`fclose(fp);`

## 2. 下面的程序完成什么任务？（假设在命令行环境中运行）

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv [])
{
  int ch;
  FILE *fp;
  if (argc < 2)
    exit(EXIT_FAILURE);
  if ((fp = fopen(argv[1], "r")) == NULL)
    exit(EXIT_FAILURE);
  while ((ch = getc(fp)) != EOF)
    if (isdigit(ch))
      putchar(ch);
  fclose(fp);
  return 0;
}
```

打开命令行第一个参数指定的文件（如果可以打开），并且打印其中的数字字符。

## 3. 假设程序中有下列语句：

```c
#include <stdio.h>
FILE * fp1,* fp2;
char ch;
fp1 = fopen("terky", "r");
fp2 = fopen("jerky", "w");
```

另外，假设成功打开了两个文件。补全下面函数调用中缺少的参数：

- a. `ch = getc();`

`ch = getc(fp1)`

- b. `fprintf( ,"%c\n", );`

`fprintf(fp2, "%c\n", ch);`

- c. `putc( , );`

`putc(ch, fp2);`

- d. `fclose();`

`fclose(fp1);`

## 4. 编写一个程序，不接受任何命令行参数或接受一个命令行参数。如果有一个参数，将其解释为文件名；如果没有参数，使用标准输入（stdin）作为输入。假设输入完全是浮点数。该程序要计算和报告输入数字的算术平均值。

```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
  FILE *fp;
  double n;
  double sum = 0.0;
  int ct = 0;
  if (argc = 1)
    fp = stdin;
  else if (argc = 2)
  {
    if ((fp = fopen(argv[1])) == NULL)
    {
      fprintf(stderr, "Could not open %s.\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  while (fscanf(fp, "%lf", &n) == 1)
  {
    sum += n;
    ct++;
  }
  if (ct > 0)
    printf("Average of %d values = %f\n", ct, num / ct);
  else
    printf("No valid data.\n");
  return 0;
}
```

## 5. 编写一个程序，接受两个命令行参数。第1个参数是字符，第2个参数是文件名。要求该程序只打印文件中包含给定字符的那些行。注意C程序根据`'\n'`识别文件中的行。假设所有行都不超过256个字符，你可能会想到用fgets()。

```c
#include <stdio.h>
#include <stdlib.h>
#define BUF 256
int has_ch(char ch, const char * st);

int main(int argc, char * argv[])
{
  FILE *fp;
  char ch;
  char line[BUF];
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s character filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  ch = argv[1][0];
  if ((fp = fopen(argv[2], "r")) == NULL)
  {
    fprintf(stderr, "Could not open %s.\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  while (fgets(line, BUF, fp) != NULL{
    if (has_ch(ch, line))
      fpouts(line, stdout);
  }
  fclose(fp);
  return 0;
}

int has_ch(char ch, const char * st)
{
  while (*line)
    if (ch == *line++)
     return 1;
  return 0;
}
```



## 6. 二进制文件和文本文件有何区别？二进制流和文本流有何区别？

二进制文件与文本文件的区别是，这两种文件格式对系统的依赖性不同。二进制流和文本流的区别包括是在读写流时程序执行的转换（二进制流 不转换，而文本流可能要转换换行符和其他字符）。

## 7. 

- a. 分别用`fprintf()`和`fwrite()`储存8238201有何区别？

用`fprintf()`储存8238201时，将其视为7个字符，保存在7字节中。用`fwrite()`储存时，使用该数的二进制表示，将其储存为一个4字节的整数。

- b. 分别用`putc()`和`fwrite()`储存字符S有何区别？

没有区别。两个函数都将其储存为一个单字节的二进制码。

## 8. 下面语句的区别是什么？

```c
printf("Hello, %s\n", name);
fprintf(stdout, "Hello, %s\n", name);
fprintf(stderr, "Hello, %s\n", name);
```

第一个和第二个都是将消息输出到标准输出。

第三个是将消息输出到标准错误，通常，标准错误被定向到与标准输出相同的位置，但是标准错误不受标准输出重定向的影响。


## 9. "a+"、"r+"和"w+"模式打开的文件都是可读写的。哪种模式更适合用来更改文件中已有的内容？

"r+"模式更适合用来更改文件中已有的内容。因为"a+"模式打开文件只允许在文件的末尾添加内容，"w+"模式打开文件会丢弃文件原来的内容。