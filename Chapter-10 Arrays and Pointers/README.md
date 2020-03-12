# 第十章 数组和指针

## 数组

### 初始化数组

用以逗号分隔的值列表（用花括号括起来）来初始化数组，各值之间用逗号分隔。

```c
int powers[8] = {1, 2, 4, 6, 8, 16, 32, 64};
```

[示例程序day_mon1.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.1-day_mon1.c)演示了如何初始化数组，打印每个月的天数。

- 使用数组前，必须先初始化。[示例程序no_data.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.2-no_data.c)演示了初始化数组失败的情况。

- 初始化列表中的项数应与数组的大小一致。[示例程序somedata.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.3-somedata.c)演示了两者不一致的情况。

- 可以省略方括号中的数字，让编译器将初始化列表中的项数匹配为数组大小。[示例程序day_mon2.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.4-day_mon2.c)演示了这种情况。

## 多维数组

```c
float rain[5][12]; // 内含5个数组元素的数组，每个数组元素内含12个float类型的元素
```

[示例程序rain.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.7-rain.c)演示了多维数组的初始化及简单应用。

## 指针和数组

数组名是数组首元素的地址。下面语句成立：

```c
arr = &arr[0]
```

指针加1，指针的值递增它所指向类型的大小，反应在数组上，就是指向下一个元素的地址。

```c
arr + 2 == &arr[2]; // 相同的地址
*(arr + 2) == arr[2]; // 相同的值
```

函数接收数组作为参数时，形参其实是一个指针类型，指向数组中元素的类型。

函数原型以下四种等价（可省略参数名）：

```c
int fn(int *ar);
int fn(int *);
int fn(int ar[]);
int fn(int []);
```

函数定义中不能省略参数名，以下两种等价

```c
int fn(int *ar)
{
  // ...
}
int fn(int ar[])
{
  // ...
}
```

函数接收的数组参数，只是指向数组首元素的指针，并不是数组本身，所以无法得知数组元素个数，可以通过一下几种方法获得数组元素个数：

1. 增加一个数组元素个数的参数，见[示例sum_arr1.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.10-sum_arr1.c)；
2. 接收两个指针参数，分别指向数组的开始处与结束处，见[示例sum_arr2.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.11-sum_arr2.c)；

## 指针操作

[示例程序prt_ops.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.13-prt_ops.c)演示了指针变量的8种基本操作。

1. 赋值：可以把地址赋给指针。用数组名、带地址运算符（&）的变量名、另一个指针进行赋值。地址应该和指针类型兼容。
2. 解引用：*运算符给出指针指向地址上的存储的值。
3. 取址：指针变量也有自己的地址和值。&运算符给出指针本身的地址。
4. 指针与整数相加：整数会和指针所指向类型的大小（以字节为单位）相乘，然后把结果与初始地址相加。
5. 递增指针：递增指向数组元素的指针可以让该指针移动至数组的下一个元素。
6. 指针减去整数：整数将乘以指针指向类型的大小（以字节为单位），然后用初始地址减去乘积。
7. 递减指针：递减指向数组元素的指针可以让该指针移动至数组的上一个元素。
8. 指针求差：可以计算两个指针的差值。通常求差的两个指针分别指向同一个数组的不同元素，差值的单位与数组类型的单位相同。
9. 比较：使用关系运算符可以比较两个指针的值，前提是两个指针都指向相同类型的对象。

> 在使用指针之前，必须先用已分配的地址初始化它。

## 保护数组中的数据

**1.对形式参数使用const**

在函数原型和函数定义中声明形式参数时应使用关键字const，使函数在处理数组时将其视为常量，不可更改。

[示例程序arf.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.14-arf.c)演示了需要改变数组的函数和不需要改变数组的函数的形参定义差别。

把const数据或非const数据的地址初始化为指向const的指针或为其赋值是合法的：

```c
double arr1[1] = { 1, 2 };
const double locked[1] = { 1, 2 };
const double * pc = arr1; // 有效
pc = locked; // 有效
pc = &arr1[1]; // 有效
```

但是，只能把非const 数据的地址赋给普通指针：

```c
double arr1[1] = { 1, 2 };
const double locked[1] = { 1, 2 };
double * pc = arr1; // 有效
pc = locked; // 无效
pc = &arr1[1]; // 有效
```

可以用const声明并初始化一个不能指向别处的指针（关键是const的位置）:

```c
double arr1[1] = { 1, 2 };
double * const pc = arr1; // 有效
pc = &arr[1]; // 不允许
*pc = 3; // 有效
```

可以使用const两次，该指针既不能更改它所指向的地址，也不能修改指向地址上的值：

```c
double arr1[1] = { 1, 2 };
const double * const pc = arr1; // 有效
pc = &arr[1]; // 不允许
*pc = 3; // 不允许
```

## 指针和多维数组

[示例程序zippo1.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.15-zippo1.c)演示了多维数组和指针的内容。

**声明指向多维数组的指针**

```c
// pz指向一个内含两个int类型值的数组
int(* pz)[2];
// pax是一个内含两个指针元素的数组，每个元素都是指向int的指针
int * pax[2]; // []优先级高
```

[示例程序zippo2.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.16-zippo2.c)演示了如何使用指向二维数组的指针。

**函数和多维数组**

声明函数的多维数组形参：

```c
void somefunction(int (* pt)[4]);
```

另外，当且仅当pt是一个函数的形式参数时，可以这样声明：

```c
void somefunction(int pt[][4]);
```

[示例程序array2d.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.17-array2d.c)演示了处理二维数组的函数。

## 变长数组（VLA）

要声明一个带二维变长数组参数的函数，如下所示：

```c
// 顺序很重要，rows和cols必须先声明，再使用
int sum2d(int rows, int cols, int ar[rows][cols]);
```

[示例程序vararr2d.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-10%20Arrays%20and%20Pointers/example/10.18-vararr2d.c)演示了如何使用函数操作变长数组。

## 复合字面量

C99新增了**复合字面量**(compound literal)，因为如果有代表数组和结构内容的复合字面量，编程时会更方便。字面量是除符号常量外的常量。

下面的复合字面量创建了一个匿名数组，含有两个int类型的值：

```c
(int [2]){ 10, 20 } // int [2] 是复合字面量的类型名
```

复合字面量也可以省略大小，编译器会自动计算数组当前的元素个数：

```c
(int []){ 50, 20, 90 }
```

复合字面量是匿名的，所以必须在创建的同时使用它。