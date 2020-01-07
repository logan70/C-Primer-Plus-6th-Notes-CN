## 1.C语言的基本模块是什么？

## 2.什么是语法错误？写出一个英语例子和C语言例子。

## 3.什么是语义错误？写出一个英语例子和C语言例子。

## 4.Indiana Sloth编写了下面的程序，并征求你的意见。请帮助他评定。 

```c
include　studio.h
int main{void} /* 该程序打印一年有多少周 /*
(
  int　s
  s　:=　56;
  print(There　are　s　weeks　in　a　year.);
  return　0;
```
## 5.假设下面的4个例子都是完整程序中的一部分，它们都输出什么结 果？

a.　
```c
printf("Baa　Baa　Black　Sheep.");
printf("Have　you　any　wool?\n");
```

b.　
```c
printf("Begone!\nO　creature　of　lard!\n");
```

c.
```c
printf("What?\nNo/nfish?\n");
```

d.
```c
int　num;
num　=　2;
printf("%d　+　%d　=　%d",　num,　num,　num　+　num);
```

## 6.在main、int、function、char、=中，哪些是C语言的关键字？

## 7.如何以下面的格式输出变量words和lines的值（这里，3020和350代表 两个变量的值）？

`There were 3020 words and 350 lines.`

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

请问，在执行完第7、第8、第9行后，程序的状态分别是什么？

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

请问，在执行完第7、第8、第9行后，程序的状态分别是什么？
