## 1.下面的程序将打印什么内容？

```c
#include <stdio.h>
int main(void)
{
  int ref[] = { 8, 4, 0, 2 };
  int *ptr;
  int index;
  for (index = 0, ptr = ref; index < 4; index++, ptr++)
  printf("%d %d\n", ref[index], *ptr);
  return 0;
}
```

打印内容如下：

```
8 8
4 4
0 0
2 2
```

## 2.在复习题1中，ref有多少个元素？

四个

## 3.在复习题1中，ref的地址是什么？ref + 1是什么意思？++ref指向什么？

ref的地址是数组内第一个元素的存储地址

ref + 1的意思是先将1乘以一个int类型的大小（以字节为单位），然后加上ref，也就是指向数组第二个元素

++ref无效，ref是一个常量

## 4.在下面的代码中，*ptr和*(ptr + 2)的值分别是什么？

a.

```c
int *ptr;
int torf[2][2] = {12, 14, 16};
ptr = torf[0];
```

*ptr是12， *(ptr + 2)是16

b.

```c
int * ptr;
int fort[2][2] = { {12}, {14,16} };
ptr = fort[0];
```

*ptr是12

*(ptr + 2)是14，因为第一个数组中还有一个未初始化的值

## 5.在下面的代码中，`**ptr`和`**(ptr + 1)`的值分别是什么？

a.

```c
int (*ptr)[2];
int torf[2][2] = {12, 14, 16};
ptr = torf;
```

`**ptr`是12，`**(ptr + 1)`是16

b.

```c
int (*ptr)[2];
int fort[2][2] = { {12}, {14,16} };
ptr = fort;
```

`**ptr`是12，`**(ptr + 1)`是14


## 6.假设有下面的声明： `int grid[30][100];`

- a.用1种写法表示`grid[22][56]`的地址

```c
&grid[22][56]
```

- b.用2种写法表示`grid[22][0]`的地址

```c
&grid[22][0]
grid[22]
```

- c.用3种写法表示`grid[0][0]`的地址

```c
&grid[0][0]
grid[0]
*grid
```

## 7.正确声明以下各变量：

- a. digits是一个内含10个int类型值的数组

`int digits[10]`

- b. rates是一个内含6个float类型值的数组

`float rates[6]`

- c.mat是一个内含3个元素的数组，每个元素都是内含5个整数的数组

`int mat[3][5]`

- d.psa是一个内含20个元素的数组，每个元素都是指向int的指针

`int * psa[20]`

- e.pstr是一个指向数组的指针，该数组内含20个char类型的值

`char (*pstr)[20]`

## 8.

- a. 声明一个内含6个int类型值的数组，并初始化各元素为1、2、4、8、 16、32

`int ar[] = { 1, 2, 4, 8, 16, 32 };`

- b.用数组表示法表示a声明的数组的第3个元素（其值为4）

`ar[2]`

- c.假设编译器支持C99/C11标准，声明一个内含100个int类型值的数组，并初始化最后一个元素为-1，其他元素不考虑

`int ar[100] = { [99] = -1 };`

- d.假设编译器支持C99/C11标准，声明一个内含100个int类型值的数组， 并初始化下标为5、10、11、12、13的元素为101，其他元素不考虑

`int ar[100] = { [5] = 101, [10] = 101, 101, 101, 101 };`

## 9.内含10个元素的数组下标范围是什么？

0 ~ 9

## 10.假设有下面的声明：

```c
float rootbeer[10], things[10][5], *pf, value = 2.2;
int i = 3;
```

判断以下各项是否有效：

- a. `rootbeer[2] = value;`

有效

- b. `scanf("%f", &rootbeer );`

无效

- c. `rootbeer = value;`

无效

- d. `printf("%f", rootbeer);`

无效

- e. `things[4][4] = rootbeer[3];`

有效

- f. `things[5] = rootbeer;`

无效

- g. `pf = value;`

无效

- h. `pf = rootbeer;`

有效

## 11.声明一个800×600的int类型数组。

`int ar[800][600];`

## 12.下面声明了3个数组： 

```c
double trots[20];
short clops[10][30];
long shots[5][10][15];
```
- a.分别以传统方式和以变长数组为参数的方式编写处理trots数组的void 函数原型和函数调用 

```c
void fn(double ar[], int n);
fn(trots, 20);
void fn(int n, double ar[n]);
fn(20, trots);
```

- b.分别以传统方式和以变长数组为参数的方式编写处理clops数组的void 函数原型和函数调用 

```c
void fn(short ar[][30], int rows);
fn(clops, 10);
void fn(int rows, int cols, short ar[rows][cols]);
fn(10, 30, clops);
```

- c.分别以传统方式和以变长数组为参数的方式编写处理shots数组的void 函数原型和函数调用

```c
void fn(int ar[][10][15], int m);
fn(shots, 5);
void fn(int m, int n, int o, int ar[m][n][o]);
fn(5, 10, 15, shots);
```

13.下面有两个函数原型：

```c
void show(const double ar[], int n);     // n是数组元素的个数
void show2(const double ar2[][3], int n);  // n是二维数组的行数
```

- a. 编写一个函数调用，把一个内含8、3、9和2的复合字面量传递给 show()函数。

```c
show((int []){ 8, 3, 9, 2 }, 4);
```

- b.编写一个函数调用，把一个2行3列的复合字面量（8、3、9作为第1 行，5、4、1作为第2行）传递给show2()函数。

```c
show2((int [][3]){ { 8, 3, 9 }, { 5, 4, 1 } }, 2);
```