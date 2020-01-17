## 1.指出下面各种数据使用的合适数据类型（有些可使用多种数据类型）：

- a. East Simpleton的人口 **unsigned short** / **unsigned int**
- b. DVD影碟的价格 **float**
- c. 本章出现次数最多的字母 **char**
- d. 本章出现次数最多的字母次数 **unsigned int**

## 2.在什么情况下要用long类型的变量代替int类型的变量？

1. 数值超出了`int`类型可表示的范围，但没有超出`long`类型所表示的范围；
2. 保证在所有系统上都至少是32位的类型，提高程序的可移植性。

## 3.使用哪些可移植的数据类型可以获得32位有符号整数？选择的理由是什么？

如果要正好获得32位的整数，可以使用int32_t类型。要获得可储存至少32位整数的最小类型，可以使用int_least32_t类型。如果要为32位整数提供最快的计算速度，可以选择int_fast32_t类型（假设你的系统已定义了上述类型）。

## 4.指出下列常量的类型和含义（如果有的话）：

- a. '\b' **char类型常量**
- b. 1066 **int类型常量**
- c. 99.44 **double类型常量**
- d. 0XAA **unsigned int类型常量，十六进制格式**
- e. 2.0e30 **double类型常量**

## 5.Dottie Cawm编写了一个程序，请找出程序中的错误。

```c
include　<stdio.h>

main
(
  float　g;　h;
  float　tax,　rate;
  g　=　e21;
  tax = rate*g;
)
```

修改错误后的程序如下：

```c
#include <stdio.h>

int main(void)
{
  float g, h;
  float tax, rate;
  rate = 0.08;
  g = 1.0e5;
  tax = rate * g;
  h = g + tax;
  printf("%f, %f, %f", g, tax, h);
  return 0;
}
```

## 6.写出下列常量在声明中使用的数据类型和在printf()中对应的转换说明：

补充后的图片如下所示：

![答案](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/images/5-review-question-6.png?raw=true)

## 7.写出下列常量在声明中使用的数据类型和在printf()中对应的转换说明（假设int为16位）：

补充后的图片如下所示：

![答案](genLink(../images/6-review-question-7.png))

## 8.假设程序的开头有下列声明：

```c
int　imate　=　2;
long　shot　=　53456;
char　grade　=　'A';
float　log　=　2.71828;
```

把下面printf()语句中的转换字符补充完整：

```c
printf("The　odds　against　the　%__　were　%__　to　1.\n", imate, shot);
printf("A　score　of　%__　is　not　an　%__　grade.\n", log, grade);
```

补充完整后代码如下：

```c
printf("The odds against the %d were %ld to 1.\n", imate, show);
printf("A score of %f is not an %c grade.\n", log, grade);
```

## 9.假设ch是char类型的变量。分别使用转义序列、十进制值、八进制字符常量和十六进制字符常量把回车字符赋给ch（假设使用ASCII编码值）。

```c
ch = '\r';
ch = 13;
ch = '\015';
ch = '\xd';
```

## 10.修正下面的程序（在C中，/表示除以）。

```c
void　main(int)　/　this　program　is　perfect　/
{
  cows,　legs　integer;
  printf("How　many　cow　legs　did　you　count?\n);
  scanf("%c",　legs);
  cows　=　legs　/　4;
  printf("That　implies　there　are　%f　cows.\n",　cows)
}
```

修正后代码如下：

```c
#include <stdio.h>

int main(void) // this program is perfect
{
  int cows, legs;
  printf("How many cow legs did you count?\n");
  scanf("%d", &legs);
  cows = legs / 4;
  printf("That implies there are %d cows.\n", cows);
  return 0;
}
```

## 11.指出下列转义序列的含义：

- a. \n **换行字符**
- b. \\ **反斜杠字符**
- c. \" **双引号字符**
- d. \t **制表字符**
