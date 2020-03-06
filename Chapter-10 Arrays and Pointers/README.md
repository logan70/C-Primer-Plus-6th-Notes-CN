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