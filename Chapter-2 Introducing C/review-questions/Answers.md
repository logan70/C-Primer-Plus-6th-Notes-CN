## 1.C 语言的基本模块是什么？

C 语言的基本模块是函数。

## 2.什么是语法错误？写出一个英语例子和 C 语言例子。

语法错误是指违反了组成语句或程序的规则。例如`print"I am Logan"`。

## 3.什么是语义错误？写出一个英语例子和 C 语言例子。

语义错误是指含义错误。例如`int age = 999`。

## 4.Indiana Sloth 编写了下面的程序，并征求你的意见。请帮助他评定。

```c
include　studio.h
int main{void} /* 该程序打印一年有多少周 /*
(
  int　s
  s　:=　56;
  print(There　are　s　weeks　in　a　year.);
  return　0;
```

修正后代码如下：

```c
#include <stdio.h>
int main(void) /* this prints the number of weeks in a year */
{
  int s;
  s = 52;
  printf("There are %d weeks in a year.\n", s);
  return 0;
}
```

## 5.假设下面的 4 个例子都是完整程序中的一部分，它们都输出什么结 果？

a.

```c
printf("Baa　Baa　Black　Sheep.");
printf("Have　you　any　wool?\n");
```

```
Baa Baa Black Sheep.Have you any wool?
```

b.

```c
printf("Begone!\nO　creature　of　lard!\n");
```

```
Begone!
O creature of lard!
```

c.

```c
printf("What?\nNo/nfish?\n");
```

```
What?
No/nfish?
```

d.

```c
int　num;
num　=　2;
printf("%d　+　%d　=　%d",　num,　num,　num　+　num);
```

```
2 + 2 = 4
```

## 6.在 main、int、function、char、=中，哪些是 C 语言的关键字？

int 和 char 是 C 语言的关键字。

## 7.如何以下面的格式输出变量 words 和 lines 的值（这里，3020 和 350 代表 两个变量的值）？

`There were 3020 words and 350 lines.`

```c
printf("There were %d words and %d lines.\n", words, lines);
```

## 8.考虑下面的程序：

```c
#include　<stdio.h>
int　main(void)
{
  int　a,　b;
  a　=　5;
  b = 2; /* 第7行 */
  b = a; /* 第8行 */
  a = b; /* 第9行 */
  printf("%d　%d\n",　b,　a);
  return　0;
}
```

请问，在执行完第 7、第 8、第 9 行后，程序的状态分别是什么？

- 执行完第 7 行，a 为 5，b 为 2；
- 执行完第 8 行，a 为 5，b 为 5；
- 执行完第 9 行，a 为 5，b 为 5；

## 9.考虑下面的程序：

```c
#include　<stdio.h>
int　main(void)
{
  int　x,　y;
  x　=　10;
  y = 5;　　 /* 第7行 */
  y = x + y; /*第8行*/
  x = x*y;　 /*第9行*/
  printf("%d　%d\n",　x,　y);
  return　0;
}
```

请问，在执行完第 7、第 8、第 9 行后，程序的状态分别是什么？

- 执行完第 7 行，x 为 10，y 为 5；
- 执行完第 8 行，x 为 10，y 为 15；
- 执行完第 9 行，x 为 150，y 为 15；
