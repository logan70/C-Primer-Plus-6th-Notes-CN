# 第二章 C语言概述

## 简单C程序示例及解释

```c
#include <stdio.h> /* 预处理器指令，指包含另一个文件 */

int main(void) /* 函数名，int表示返回一个整形，void表示不带任何参数 */
{
  int num; /* 定义一个名为num的变量，int表示类型为整数 */
  num = 1; /* 将num赋值整数1 */
  printf("I am a simple "); /* 调用printf()函数 */
  printf("computer.\n"); /* 调用printf()函数，`\n`为换行符 */
  printf("My favorite number is %d because it is first.\n", num); /* 将num的值内嵌在字符串中打印，%d表示以整形格式输出 */
  return 0; /* return语句 */
}
```

![C program structure](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-2%20Introducing%20C/images/1-c-program-structure.png?raw=true)

### #include指令和头文件

`#include`是一条C预处理器指令（preprocessor directive）

`stdio.h`文件包含了供编译器使用的输入和输出函数（如，printf()）信息。

通常，在C程序顶部的信息集合被称为**头文件（header）**。

### main函数

C程序一定从main()函数开始执行（目前 不必考虑例外的情况）。

### 注释

多行注释

```c
/*
这是多行注释
这是多行注释
*/
```

单行注释（第二种写法为C99新增）

```c
/* 这是单行注释 */

// 这是单行注释
```

### 程序说明

程序在开始处有一条注释，给出文件名和程序目的。

```c
// fathm_ft.c -- 把2音寻转换成英寸
```

### 多条声明

一条声明语句中声明多个变量，变量名间用逗号隔开。

```c
int feet, fathoms;
```

### 多个函数

使用一个自定义函数主要包括3部分：

- 函数原型（prototype）：也叫函数声明（function declaration），告知编译器在程序中要使用该函数。
- 函数定义（function defination）：即函数本身的源代码。
- 函数调用（function call）：即调用该函数的代码。

```c
// 多个函数
#include <stdio.h>
void print_name(void); // 函数声明

int main(viod)
{
  printf("Start\n");
  print_name();
  printf("End\n");
}

void print_name(void)
{
  printf("My name is Logan.\n");
}
```

## 关键字和保留标识符

**关键字（keywords）**是C语言的词汇，不能用作标识符（如变量名）。

许多关键字用于指定不同的类型（如int）或控制程序中语句的执行顺序（如if）。

![keywords-1](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-2%20Introducing%20C/images/2-keywords-1.png?raw=true)

![keywords-2](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-2%20Introducing%20C/images/2-keywords-2.png?raw=true)

**保留标识符（reserved identifier）**，C语言已经指定了它们的用途或保留它们的使用权，保留标识符包括上图那些以下划线开头的标识符和标准库函数名，如printf。
