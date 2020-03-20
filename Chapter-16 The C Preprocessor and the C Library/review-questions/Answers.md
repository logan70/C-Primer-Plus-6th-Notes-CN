## 1. 下面的几组代码由一个或多个宏组成，其后是使用宏的源代码。在每种情况下代码的结果是什么？这些代码是否是有效代码？（假设其中的变量已声明）

- a.

```c
#define FPM 5280 /*每英里的英尺数*/
dist = FPM * miles;
```

有效

- b.

```c
#define FEET 4
#define POD FEET + FEET
plort = FEET * POD;
```

有效，但是plort 是`4 * 4 + 4`，可能与预想的有出入

- c.

```c
#define SIX = 6;
nex = SIX;
```

无效，编写预处理器代码时不用加等号和分号，应为`#define SIX 6`。

- d.

```c
#define NEW(X) X + 5
y = NEW(y);
berg = NEW(berg) * lob;
est = NEW(berg) / NEW(y);
nilp = lob * NEW(-berg);
```

均有效，但是可能得不到想要的结果。

## 2. 修改复习题1中d部分的定义，使其更可靠。

```c
#define NEW(X) ((X) + 5)
```

## 3. 定义一个宏函数，返回两值中的较小值。

```c
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))
```

## 4. 定义`EVEN_GT(X, Y)`宏，如果X为偶数且大于Y，该宏返回1。

```c
#define EVEN_GT(X, Y) (((X) % 2) == 0 && ((X) > (Y)) ? 1 : 0)
```

## 5. 定义一个宏函数，打印两个表达式及其值。例如，若参数为3+4和 4*12，则打印： `3+4 is 7 and 4*12 is 48`

```c
#define SHOW(X, Y) printf(#X " is %d and " #Y " is %d\n", X, Y)
```

## 6. 创建#define指令完成下面的任务。

- a. 创建一个值为25的命名常量。

```c
#define NUM 25
```

- b. SPACE表示空格字符。

```c
#define SPACE ' '
```

- c. PS()代表打印空格字符。

```c
#define PS() putchar(' ')
```

- d. BIG(X)代表X的值加3。

```c
#define BIG(X) ((X) + 3)
```

- e. SUMSQ(X, Y)代表X和Y的平方和。

```c
#define SUMSQ(X, Y) ((X) * (X) + (Y) * (Y))
```

## 7. 定义一个宏，以下面的格式打印名称、值和int类型变量的地址：

`name: fop; value: 23; address: ff464016`

```c
#define P(X) printf("name: " #X "; value: %d; address: %p\n", X, &X)
```

## 8. 假设在测试程序时要暂时跳过一块代码，如何在不移除这块代码的前提下完成这项任务？

使用条件编译指令

```c
#define SKIP // 不需要跳过，则删除这条指令
#ifndef SKIP
// 跳过的代码
#endif
```

## 9. 编写一段代码，如果定义了PR_DATE宏，则打印预处理的日期。

```c
#ifdef PR_DATE
printf("Date = %s\n", __DATE__);
#endif
```

## 10. 内联函数部分讨论了3种不同版本的`square()`函数。从行为方面看，这3种版本的函数有何不同？

接受参数和返回值的类型不同。

## 11. 创建一个使用泛型选择表达式的宏，如果宏参数是`_Bool`类型， 对"boolean"求值，否则对"not boolean"求值。

```c
#define BOOL(X) _Generic((X),\
  _Bool: "boolean",\
  default: "not boolean"
)
```

## 12. 下面的程序有什么错误？

```c
#include <stdio.h>
int main(int argc, char argv[])
{
  printf("The square root of %f is %f\n", argv[1],sqrt(argv[1]) );
}
```

1. argv参数的类型错误，是字符串指针数组，应为`char * argv[]`；
2. `argv[1]`不一定存在，需要判断；
3. 使用了`sqrt()`函数，所以应该包含`math.h`头文件
4. `argv[1]`存在的话也是字符串，不能当做数值直接计算，需要转换，；
5. 因为是求平方根，所以要排除参数为负数的情况；
6. 函数结尾缺少`return 0`。

## 13. 假设 scores 是内含 1000 个 `int` 类型元素的数组，要按降序排序该数组中的值。假设你使用`qsort()`和`comp()`比较函数。

- a.如何正确调用`qsort()`？

```c
qsort(scores, 1000, sizeof(int), comp);
```

- b.如何正确定义comp()？

```c
int comp(const void * pt1, const void * pt2)
{
  const int * cp1 = (const int *) pt1;
  const int * cp2 = (const int *) cp2;
  if (*cp1 < *cp2)
    return 1;
  else if (*cp1 == *cp2)
    return 0;
  else
    return -1;
}
```

## 14. 假设data1是内含100个double类型元素的数组，data2是内含300个double类型元素的数组。

- a. 编写`memcpy()`的函数调用，把data2中的前100个元素拷贝到data1中。

```c
memcpy(data1, data2, 100 * sizeof(double));
```

- b.编写`memcpy()`的函数调用，把data2中的后100个元素拷贝到data1中。

```c
memcpy(data1, data2 + 200, 100 * sizeof(double));
```
