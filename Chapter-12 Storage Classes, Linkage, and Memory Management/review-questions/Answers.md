## 1. 哪些类别的变量可以成为它所在函数的局部变量？

自动存储类别；寄存器存储类别；静态、无链接存储类别。

## 2. 哪些类别的变量在它所在程序的运行期一直存在？

- 静态、无链接存储类别；
- 静态、内部链接存储类别；
- 静态、外部链接存储类别

## 3. 哪些类别的变量可以被多个文件使用？哪些类别的变量仅限于在一个 文件中使用？

静态、外部链接存储类别可以被多个文件使用；

静态、内部链接存储类别只能在一个文件内使用；

## 4. 块作用域变量具有什么链接属性？

无链接。

## 5. extern关键字有什么用途？

引用式声明，表明该声明不是定义，该变量或函数已定义在别处。

## 6. 考虑下面两行代码，就输出的结果而言有何异同：

```c
int * p1 = (int *)malloc(100 * sizeof(int));
int * p1 = (int *)calloc(100, sizeof(int));

两者都分配了一个内含100个int类型值的数组。第二行代码使用`calloc()`把数组中的每个元素都设置为0。
```

## 7. 下面的变量对哪些函数可见？程序是否有误？

```c
/* 文件 1 */
int daisy;
int main(void)
{
  int lily;
  ..;
}
int petal()
{
  extern int daisy, lily;
  ...;
}
/* 文件 2 */
extern int daisy;
static int lily;
int rose;
int stem()
{
  int rose;
  ...;
}
void root()
{
  ...;
}
```

默认情况下，daisy只对main()可见，以extern声明的daisy才对petal()、 stem()和root()可见。文件2中的extern int daisy;声明使得daisy对文件2中的所 有函数都可见。第1个lily是main()的局部变量。petal()函数中引用的lily是错 误的，因为两个文件中都没有外部链接的lily。虽然文件2中有一个静态的 lily，但是它只对文件2可见。第1个外部rose对root()函数可见，但是stem()中 的局部rose覆盖了外部的rose。

## 8. 下面程序会打印什么？

```c
#include <stdio.h>
char color = 'B';
void first(void);
void second(void);
int main(void)
{
  extern char color;
  printf("color in main() is %c\n", color);
  first();
  printf("color in main() is %c\n", color);
  second();
  printf("color in main() is %c\n", color);
  return 0;
}
void first(void)
{
  char color;
  color = 'R';
  printf("color in first() is %c\n", color);
}
void second(void)
{
  color = 'G';
  printf("color in second() is %c\n", color);
}
```

打印内容如下：

```
color in main() is B
color in first() is R
color in main() is B
color in second() is G
color in main() is G
```

## 9. 假设文件的开始处有如下声明：

```c
static int plink;
int value_ct(const int arr[], int value, int n);
```

  
- a. 以上声明表明了程序员的什么意图？ 

plink为静态、内部链接类别，文件中所有函数可见。

value_ct的第一个形参int加了const修饰，表明不允许通过指针修改原始数组中的值。

- b. 用`const int value`和`const int n`分别替换`int value`和`int n`，是否对主调程序 的值加强保护。

不会，value和n已经是原始数据的备份。