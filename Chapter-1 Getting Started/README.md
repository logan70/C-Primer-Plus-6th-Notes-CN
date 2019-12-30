## 最简单的C程序

```c
// example.c
#include　<stdio.h>
int　main(void)
{
  printf("A　.c　is　used　to　end　a　C　program　filename.\n");
  return　0;
}
```

## C编程机制

C编程的基本策略是，用程序把源代码文件转换为可执行文件（其中包 含可直接运行的机器语言代码）。典型的C实现通过**编译**和**链接**两个步骤来完成这一过程。

- 编译器：把源代码转换成目标代码；
- 链接器：把目标代码和启动代码（startup code）、库代码合并生成可执行文件。

![C编程机制](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-1%20Getting%20Started/1-compiler-and-linker.png?raw=true)

## C语言各版本标准

- `C89/C90`：ANSI/ISO标准的最终版本
- `C99`：ANSI/ISO联合委员会1999年发布，虽发布很久，但并非所有编译器都已完全实现C99的所有改动
- `C11`：标准委员会11年发布，本次学习浅尝辄止即可

## 编译器

C语言编译器主流的有`gcc`和`clang`两种，各系统都使用 `cc` 别名来代替`gcc`或`clang`命令。

[GCC最新发布和版本](http://www.gnu.org/software/gcc/index.html)

[Clang最新发布和版本](https://clang.llvm.org)

- 显示编译器信息及版本：`cc -v`
- 调用编译器接受C99标准进行编译：`cc -std=c99 example.c`
- 调用编译器接受C11之前的草案标准进行编译：`cc -std=c1x example.c`
- 调用编译器接受C11标准进行编译：`cc -std=c11 example.c`

## Mac上编写、编译、运行C程序

1. 编写程序，保存为`example.c`格式文件
2. 命令行内在文件目录下运行`cc example.c`，编译源文件
3. 命令行内运行`./a.out`，执行编译后的可执行文件

![Prepare for C program](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-1%20Getting%20Started/2-prepare-c.png?raw=true)