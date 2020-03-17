## 1. 再次运行程序清单 4.1，但是在要求输入名时，请输入名和姓（根据英文书写习惯，名和姓中间有一个空格），看看会发生什么情况？为什么？

程序不能正常运行，因为`scanf()`读取了名，遇到空白时停止读取，姓留在输入缓冲区中，下次读取重量时，将姓当做重量读取，导致读取失败。

## 2. 假设下列示例都是完整程序中的一部分，它们打印的结果分别是什么？

- a. `printf("He sold the painting for $%2.2f.\n", 2.345e2);`
- b. `printf("%c%c%c\n", 'H', 105, '\41');`
- c. `#define Q "His Hamlet was funny without being vulgar." printf("%s\nhas %d characters.\n", Q, strlen(Q));`
- d. `printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);`


- a. `He sold the painting for $234.50.`
- b. `Hi!`
- c. 
```
His hamlet was funny without being valgar.
has 42 characters.
```
- d. `Is 1.20e+003 the same as 1201.00?`

## 3. 在第2题的c中，要输出包含双引号的字符串Q，应如何修改？

```c
printf("\"%s\"\nhas %d characters.\n", Q, strlen(Q));
```

## 4. 找出下面程序中的错误。

```c
define B booboo
define X 10
main(int)
{
  int age;
  char name;
  printf("Please enter your first name.");
  scanf("%s", name);
  printf("All right, %c, what's your age?\n", name);
  scanf("%f", age);
  xp = age + XX;
  printf("That's a %s! You must be at lease %d.\n", B, xp);
  return 0;
}
```

修改后如下所示

```c
#include <stdio.h>
#define B "booboo"
#define X 10

int main(void)
{
  int age;
  int xp;
  char name[40];
  printf("Please enter your first name.");
  scanf("%s", name);
  printf("Allright, %s, what's your age?\n", name);
  scanf("%d", &age);
  xp = age + X;
  printf("That's a %s! You must be at lease %d.\n", B, xp);
  return 0;
}
```

## 5. 假设一个程序的开头是这样：

```c
#define BOOK "War and Peace"
int main(void)
{
  float cost =12.99;
  float percent = 80.0;
```

请构造一个使用BOOK、cost和percent的printf()语句，打印以下内容： 

```
This copy of "War and Peace" sells for $12.99.
That is 80% of list.
```

**答案如下所示**

```c
#include <stdio.h>
#define BOOK "War and Peace"

int main(void)
{
  float cost = 12.99;
  float percent = 80.0;
  printf("This copy of \"%s\" sells for $%.2d.\n", BOOK, cost);
  printf("That is %.0f%% of list.\n", percent);
  return 0;
}
```

## 6. 打印下列各项内容要分别使用什么转换说明？

- a.一个字段宽度与位数相同的十进制整数
- b.一个形如8A、字段宽度为4的十六进制整数
- c.一个形如232.346、字段宽度为10的浮点数
- d.一个形如2.33e+002、字段宽度为12的浮点数
- e.一个字段宽度为30、左对齐的字符串

- a. `%d`
- b. `%4X`
- c. `%10f.3`
- d. `%12.2e`
- e. `%-30s`

## 7. 打印下面各项内容要分别使用什么转换说明？

- a.字段宽度为15的unsigned long类型的整数
- b.一个形如0x8a、字段宽度为4的十六进制整数
- c.一个形如2.33E+02、字段宽度为12、左对齐的浮点数
- d.一个形如+232.346、字段宽度为10的浮点数
- e.一个字段宽度为8的字符串的前8个字符

- a. `%15lu`
- b. `%#4x`
- c. `%-12.2E`
- d. `%+10.3f`
- e. `%8.8s`

## 8. 打印下面各项内容要分别使用什么转换说明？

- a.一个字段宽度为6、最少有4位数字的十进制整数
- b.一个在参数列表中给定字段宽度的八进制整数
- c.一个字段宽度为2的字符
- d.一个形如+3.13、字段宽度等于数字中字符数的浮点数
- e.一个字段宽度为7、左对齐字符串中的前5个字符

- a. `%6.4d`
- b. `%*o`
- c. `%2c`
- d. `%+0.2f`
- e. `%-7.5s`

## 9. 分别写出读取下列各输入行的scanf()语句，并声明语句中用到变量和数组。

- a.101
- b.22.32 8.34E−09
- c.linguini
- d.catch 22
- e.catch 22 （但是跳过catch）

- a. `scanf("%d", &int1);`
- b. `scanf("%f %f", &float1, &float2);`
- c. `scanf("%s", charArr1);`
- d. `scanf("%s %d", charArr1, &int1);`
- e. `scanf("%*s %d", &int1);`

## 10. 什么是空白？

空白包括空格、制表符和换行符。C语言使用空白分隔记号。scanf()使用空白分隔连续的输入项。

## 11. 下面的语句有什么问题？如何修正？

```c
printf("The double type is %z bytes.\n", sizeof(double));
```

%z 中的 z 是修饰符，不是转换字符，所以要在修饰符后面加上一个它修饰的转换字符。可以使用%zd打印十进制数，或用不同的说明符打印不同进制的数，例如，%zx打印十六进制的数。

## 12. 假设要在程序中使用圆括号代替花括号，以下方法是否可行？

```c
#define ( {
#define ) }
```

不可行，预处理器无法区分哪些圆括号应替换成花括号，哪些圆括号不能替换成花括号。
