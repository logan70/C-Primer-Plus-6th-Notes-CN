## 1. 下面的结构模板有什么问题：

```c
structure {
  char itable;
  int num[20];
  char * togs
}
```

1. `structure`应为`struct`；
2. 左花括号前应该有一个标记，或者在右花括号前应该有一个结构变量名（匿名结构模板方式）；
3. togs后缺少分号；
4. 模板结尾缺少分号。

## 2. 下面是程序的一部分，输出是什么？

```c
#include <stdio.h>
struct house {
  float sqft;
  int rooms;
  int stories;
  char address[40];
};
int main(void)
{
  struct house fruzt = {1560.0, 6, 1, "22 Spiffo Road"};
  struct house *sign;
  sign = &fruzt;
  printf("%d %d\n", fruzt.rooms, sign->stories);
  printf("%s \n", fruzt.address);
  printf("%c %c\n", sign->address[3], fruzt.address[4]);
  return 0;
}
```

输出内容如下：

```
6 1
22 Spiffo Road
S p
```

## 3. 设计一个结构模板储存一个月份名、该月份名的3个字母缩写、该月 的天数以及月份号。

```c
struct month {
  char name[10];
  char abbr[4];
  int days;
  int monnumb;
};
```

## 4. 定义一个数组，内含12个结构（第3题的结构类型）并初始化为一个 年份（非闰年）。

```c
struct month months[12] = {
  { "January", "jan", 31, 1 },
  { "February", "feb", 28, 2 },
  { "March", "mar", 31, 3 },
  { "April", "apr", 30, 4 },
  { "May", "may", 31, 5 },
  { "June", "jun", 30, 6 },
  { "July", "jul", 31, 7 },
  { "August", "aug", 31, 8 },
  { "September", "sep", 30, 9 },
  { "October", "oct", 31, 10 },
  { "November", "nov", 30, 11 },
  { "December", "dec", 31, 12 }
};
```

## 5. 编写一个函数，用户提供月份号，该函数就返回一年中到该月为止（包括该月）的总天数。假设在所有函数的外部声明了第3题的结构模版和一个该类型结构的数组。

```c
extern struct month months [];
int days(int month)
{
  int i, count;
  if (month < 1 || month > 12)
    return -1;
  else
  {
    for (i = 0, count = 0; i < month; i++)
      count += months[i].days;
    return count;
  }
}
```

## 6.

- a.假设有下面的 typedef，声明一个内含 10 个指定结构的数组。然后，单独给成员赋值（或等价字符串），使第3个元素表示一个焦距长度有500mm，孔径为f/2.0的Remarkata镜头。

```c
typedef struct lens {　 /* 描述镜头　　　　　 */
  float foclen; /* 焦距长度，单位为mm　 */
  float fstop; /* 孔径　　　　　　　*/
  char brand[30]; /* 品牌名称　　　　　 */
} LENS;
```

```c
LENS bigEye[10];
bigEye[2].foclen = 500;
bigEye[2].fstop = 2.0;
strcpy(bigEye[2].brand, "Remarkatar");
```

- b.重写a，在声明中使用一个待指定初始化器的初始化列表，而不是对 每个成员单独赋值。

```c
LENS bigEye[10] {[2] = { 500.0, 2.0, "Remarkatar" }};
```

## 7. 考虑下面程序片段：

```c
struct name {
  char first[20];
  char last[20];
};
struct bem {
  int limbs;
  struct name title;
  char type[30];
};
struct bem * pb;
struct bem deb = {
  6,
  { "Berbnazel", "Gwolkapwolk" },
  "Arcturan"
};
pb = &deb;
```

- a.下面的语句分别打印什么？ 

```c
printf("%d\n", deb.limbs);
printf("%s\n", pb->type);
printf("%s\n", pb->type + 2);
```

打印内容如下：

```
6
Arcturan
cturan
```

- b.如何用结构表示法（两种方法）表示"Gwolkapwolk"？

```c
deb.title.last
pb->title.last
```

- c.编写一个函数，以bem结构的地址作为参数，并以下面的形式输出结构的内容（假定结构模板在一个名为starfolk.h的头文件中）： `Berbnazel Gwolkapwolk is a 6-limbed Arcturan.`

```c
#include <stdio.h>
#include <starfolk.h>
struct bem * pb;
struct bem deb = {
  6,
  { "Berbnazel", "Gwolkapwolk" },
  "Arcturan"
};
pb = &deb;
void show(const struct bem * pb);

int main(void)
{
  show(pb);
  return 0;
}
void show(const struct bem * pb)
{
  printf("%s %s is a %d-limbed %s\n",
  pb->title.first, pb->title.last, pb->limbs, pb->type);
}
```

## 8. 考虑下面的声明：

```c
struct fullname {
  char fname[20];
  char lname[20];
};
struct bard {
  struct fullname name;
  int born;
  int died;
};
struct bard willie;
struct bard *pt = &willie;
```


- a.用willie标识符标识willie结构的born成员。

`willie.born`

- b.用pt标识符标识willie结构的born成员。

`pt->born`

- c.调用scanf()读入一个用willie标识符标识的born成员的值。

`scanf("%d", &willie.born);`

- d.调用scanf()读入一个用pt标识符标识的born成员的值。 

`scanf("%d", &pb->born);`

- e.调用scanf()读入一个用willie标识符标识的name成员中lname成员的 值。

`scanf("%s", &willie.name.lname);`

- f.调用scanf()读入一个用pt标识符标识的name成员中lname成员的值。 

`scanf("%s", &pb->name.lname);`

- g.构造一个标识符，标识willie结构变量所表示的姓名中名的第3个字母（英文的名在前）。 

`willie.name.fname[2]`

- h.构造一个表达式，表示willie结构变量所表示的名和姓中的字母总数。

`strlen(willie.name.fname) + strlen(willie.name.lname)`

## 9. 定义一个结构模板以储存这些项：汽车名、马力、EPA（美国环保局）城市交通MPG（每加仑燃料行驶的英里数）评级、轴距和出厂年份。 使用car作为该模版的标记。

```c
struct car {
  char name[20];
  float hp;
  fload rate;
  float wbase;
  int year;
};
```

## 10. 假设有如下结构：

```c
struct gas {
  float distance;
  float gals;
  float mpg;
};
```

- a. 设计一个函数，接受`struct gas`类型的参数。假设传入的结构包含 distance和gals信息。该函数为mpg成员计算正确的值，并把值返回该结构。

```c
struct gas getmpg(struct gas info)
{
  if (info.gals > 0)
    info.mpg = info.distance / info.gals;
  else
    info.mpg = -1.0;
  return info;
}
```

- b.设计一个函数，接受`struct gas *`类型的参数。假设传入的结构包含 distance和gals信息。该函数为mpg成员计算正确的值，并把该值赋给合适的 成员。

```c
void getmpg(struct gas * pt)
{
  if (pt->gals > 0)
    pt->mpg = pt->distance / pt->gals;
  else
    pt->mpg = -1.0;
}
```

## 11. 声明一个标记为choices的枚举，把枚举常量no、yes和maybe分别设置 为0、1、2。

```c
enum choices = { no, yes, maybe };
```

## 12. 声明一个指向函数的指针，该函数返回指向char的指针，接受一个指 向char的指针和一个char类型的值。

```c
char * (* fp)(char *, char);
```

## 13. 声明4个函数，并初始化一个指向这些函数的指针数组。每个函数都 接受两个double类型的参数，返回double类型的值。另外，用两种方法使用 该数组调用带10.0和2.5实参的第2个函数。

```c
double fn1(double x, double y);
double fn2(double x, double y);
double fn3(double x, double y);
double fn4(double x, double y);

double (*fp[4])(double x, double y) = { fn1, fn2, fn3, fn4 };
fp[1](10.0, 2.5);
(*fp[1])(10.0, 2.5);
```
