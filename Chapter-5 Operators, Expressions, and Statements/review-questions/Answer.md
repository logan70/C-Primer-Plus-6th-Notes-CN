## 1. 假设所有变量的类型都是int，下列各项变量的值是多少：

- a. `x = (2 + 3) * 6`;
- b. `x = (12 + 6)/2*3`;
- c. `y = x = (2 + 3)/4`;
- d. `y = 3 + 2*(x = 7/2)`;

- a. 30;
- b. 27;
- c. x = 1, y = 1;
- d. x = 3, y = 9;

## 2. 假设所有变量的类型都是int，下列各项变量的值是多少： 

- a. `x = (int)3.8 + 3.3`;
- b. `x = (2 + 3) * 10.5`;
- c. `x = 3 / 5 * 22.0`;
- d. `x = 22.0 * 3 / 5`;

- a. 6
- b. 52
- c. 0
- d. 13

## 3.对下列各表达式求值： 

- a. `30.0 / 4.0 * 5.0`;
- b. `30.0 / (4.0 * 5.0)`;
- c. `30 / 4 * 5`;
- d. `30 * 5 / 4`;
- e. `30 / 4.0 * 5`;
- f. `30 / 4 * 5.0`;

- a. 37.5
- b. 1.5
- c. 35
- d. 37
- e. 37.5
- f. 35.0

## 4.请找出下面的程序中的错误。

```c
int　main(void)
{
  int　i　=　1,
  float　n;
  printf("Watch　out!　Here　come　a　bunch　of　fractions!\n"); while　(i　<　30)
  n　=　1/i;
  printf("%f",　n);
  printf("That's　all,　folks!\n");
  return;
}
```

修改后程序如下

```c
#include <stdio.h>
int main(void)
{
  int i = 1;
  float n;
  printf("Watch! Here coms a bunch of fractions!\n");
  while (i++ < 30)
  {
    n = 1.0 / i;
    printf("%f\n", n);
  }
  printf("That's all, folks!\n");
  return 0;
}
```

## 5. 这是程序清单 5.9 的另一个版本。从表面上看，该程序只使用了一条 scanf()语句，比程序清单5.9简单。请找出不如原版之处。

```c
#include　<stdio.h>
#define　S_TO_M　60
int　main(void)
{
  int　sec,　min,　left;
  printf("This　program　converts　seconds　to　minutes　and　"); printf("seconds.\n");
  printf("Just　enter　the　number　of　seconds.\n");
  printf("Enter　0　to　end　the　program.\n");
  while　(sec　>　0)　{
    scanf("%d",　&sec);
    min　=　sec/S_TO_M;
    left　=　sec　%　S_TO_M;
    printf("%d　sec　is　%d　min,　%d　sec.　\n",　sec,　min,　left); printf("Next　input?\n");
    }
  printf("Bye!\n");
  return　0;
}
```

1. sec无初始值，首次判断可能使用内存位置的垃圾值。
2. 获取输入在块内最前方进行，最后输入0结束程序时，未经过判断，会打印出来。

## 6. 下面的程序将打印出什么内容？

```c
#include　<stdio.h>
#define　FORMAT　"%s!　C　is　cool!\n"
int　main(void) {
  int　num　=　10;
  printf(FORMAT,FORMAT);
  printf("%d\n",　++num);
  printf("%d\n",　num++);
  printf("%d\n",　num--);
  printf("%d\n",　num);
  return　0;
}
```

打印如下内容：

```
%s! C is cool!
! C is cool!
11
11
12
11
```

## 7. 下面的程序将打印出什么内容？

```c
#include　<stdio.h>
int　main(void) {
  char　c1,　c2;
  int　diff;
  float　num;
  c1　=　'S';
  c2　=　'O';
  diff　=　c1　-　c2;
  num　=　diff;
  printf("%c%c%c:%d　%3.2f\n",　c1,　c2,　c1,　diff,　num);
  return　0;
}
```

打印如下内容：

```
SOS:4 4.00
```

## 8. 下面的程序将打印出什么内容？

```c
#include　<stdio.h>
#define　TEN　10
int　main(void)
{
  int　n　=　0;
  while　(n++　<　TEN)
  printf("%5d",　n);
  printf("\n");
  return　0;
}
```

依次打印1到10。

## 9. 修改上一个程序，使其可以打印字母a～g。

修改后程序如下：

```c
#include <stdio.h>
#define TEN 10
int main(void)
{
  char ch = 'a';
  while (ch <= 'g')
  {
    printf("%5c", ch++);
  }
  printf("\n");
  return 0;
}
```

## 10. 假设下面是完整程序中的一部分，它们分别打印什么？

- a.
  ```c
  int　x　=　0;
  while　(++x　<　3)
  printf("%4d",　x);
  ```

依次打印1、2、3

- b.
  ```c
  int　x　=　100;
  while　(x++　<　103)
  printf("%4d\n",x);
  printf("%4d\n",x);
  ```

依次打印101、102、103、104

- c.
  ```c
  char　ch　=　's';
  while　(ch　<　'w')
  {
    printf("%c",　ch);
    ch++;
  }
  printf("%c\n",ch);
  ```
依次打印s、t、u、v、w

## 11. 下面的程序会打印出什么？

```c
#define　MESG　"COMPUTER　BYTES　DOG"
#include　<stdio.h>
int　main(void)
{
  int　n　=　0;
  while　(　n　<　5　)
  printf("%s\n",　MESG);
  n++;
  printf("That's　all.\n");
  return　0;
}
```

while循环没有用花括号将下面两条语句括起来，造成死循环，一直打印"COMPUTER BYTES DOG"

## 12. 分别编写一条语句，完成下列各任务（或者说，使其具有以下副作用）：

- a. 将变量x的值增加10
- b. 将变量x的值增加1
- c. 将a与b之和的两倍赋给c
- d. 将a与b的两倍之和赋给c

- a. `x = x + 10;`
- b. `x++;` / `++x;` / `x = x + 1;`
- c. `c = 2 * (a + b);`
- d. `c = a + 2 * b;`

## 13. 分别编写一条语句，完成下列各任务：

- a. 将变量x的值减少1
- b. 将n除以k的余数赋给m
- c. q除以b减去a，并将结果赋给p
- d. a与b之和除以c与d的乘积，并将结果赋给x

- a. `x--;` / `--x;` / `x = x - 1;`
- b. `m = n % k;`
- c. `p = q / (b - a);`
- d. `x = (a + b) / (c * d)`