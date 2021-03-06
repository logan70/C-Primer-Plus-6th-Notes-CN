# 第三章 数据和 C

## 变量和常量

- **常量(constant)** : 在程序使用前已预设好，且程序运行过程中不会变化的数据类型。
- **变量(variable)** : 在程序运行期间可能改变或被赋值的数据类型。

## 数据类型关键字

![C语言的数据类型关键字](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/images/1-datatype-key-word.png?raw=true)

### 位、字节和字

- **位(bit)** : 计算机内最小存储单元，也是计算机内存的基本构建块。可存储0或1。
- **字节(byte)** : 常用计算机存储单位，1字节=8位，可表示0~255的整数（2的8次方）。
- **字(word)** : 设计计算机时给定的自然存储单位(8位、16位、32位、64位)。计算机的字长越大，其数据转移越快，允许的内存访问也更多。

### 整数和浮点数

- 计算机把浮点数分成小数部分和指数部分来表示，且分开存储。
- 整数没有小数部分，浮点数有小数部分。
- 浮点数可以表示的范围比整数大。
- 对于一些算术运算（如两个很大的数相减），浮点数损失的精度更多。

## C语言基本数据类型

### int类型

int类型是有符号整形。取值范围依计算机系统而异。目前一般用32位存储一个int值。

打印int类型值时使用`%d`进行转换。例如`printf("%d", 2);`。

在C语言中，用特定的前缀表示使用哪种进制：

- `0x`或`0X`前缀表示十六进制，故十进制的16表示成十六进制是`0x10`或`0X10`
- `0`前缀表示八进制，故十进制的16表示成八进制是`020`。

显示不同进制的数需要使用不同的转换说明（[示例代码](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/example/3.3-bases.c)）：

- `%d`以十进制显示数字；
- `%o`以八进制显示数字；
- `%#o`以八进制显示数字，并显示`0`前缀；
- `%x`以十六进制显示数字
- `%#x`以十六进制显示数字，并显示`0x`前缀；
- `%#X`以十六进制显示数字，并显示`0X`前缀。

### char类型

char类型用于储存字符（如，字母或标点符号），但是从技术层面看， char是整数类型。因为char类型实际上储存的是整数而不是字符。计算机使用数字编码来处理字符，即用特定的整数表示特定的字符。

标准ASCII码的范围是0～127，只需7位二进制数即可表示。通常，char 类型被定义为8位的存储单元，即1字节(byte)。

> 使用ASCII码时，注意数字和数字字符的区别。例如，字符4对应的 ASCII码是52。'4'表示字符4，而不是数值4。

**char类型变量声明和赋值**

> 用单引号括起来的单个字符称为字符常量(character constant)。

```c
char response;
char grade = 'A';
respones = 'T';
```

**转义序列**

一些表示行为的字符（如退格、换行、终端响铃或蜂鸣），可以使用转义序列(escape sequence)来表示。各转义序列及其含义见下图。

![转义序列](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/images/2-escape-squence.png?raw=true)

**打印字符**

`printf()`函数用`%c`指明待打印的字符。[示例代码](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/example/3.5-charcode.c) 演示了打印char类型变量的两种方式。

注意，`printf()`函数中的转换说明决定了数据的显示方式，而不是数据的存储方式（见下图）。

![数据显示和数据存储](genLint(images/3-data-show-and-storage.png))

### _Bool类型

C99标准添加了_Bool类型，用于表示 **布尔值**，即逻辑值true和false。1表示true，0表示false，原则上仅占用1位存储空间。

### float、double和long double

**float**

C语言中的浮点类型有`float`、`double`和`long double`，浮点数的表示类似于科学记数法（即用小数乘以10的幂来表示数字，见下图）。

![记数法示例](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/images/4-decimal.png)?raw=true

C标准规定，`float`类型必须至少能表示6位有效数字，且取值范围至少是`10^-37 ~ 10^37`。通常系统存储一个浮点数要占用32位。1位符号位，7位指数位，24位尾数位。

**double**

`double`意为双精度，占用64位，和`float`类型的最小取值范围相同，但是至少必须能表示10位有效数字。

**浮点型变量及常量**

```c
// 浮点型变量
float noah;
double trouble;
float planck = 6.63e-34;
long double gnp;

// 浮点型常量

-1.56E+12
2.87e-3
```

**打印浮点值**

- `%f` : 十进制记数法的`float`和`double`类型
- `%e` : 指数记数法的`float`和`double`类型
- `%a` : 十六进制指数记数法的`float`和`double`类型
- `%Lf` : 十进制记数法的`long double`类型
- `%Le` : 指数记数法的`long double`类型
- `%La` : 十六进制指数记数法的`long double`类型

代码演示见 [示例代码](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/example/3.7-showf_pt.c) 。

**浮点值的上溢和下溢**

- 上溢（overflow） : 当计算导致数字超过当前类型表达范围时，会发生上溢，`printf()`显示`int`或`infinity`。
- 下溢（underflow） : 当计算导致损失了原末尾有效位上的数字，会发生下溢。C语言把损失了类型全精度的浮点值称为低于正常的（subnormal）浮点值。
- NaN（not a number） ： 一个特殊的浮点值。`printf()`可将其显示未`nan`、`NaN`或其他类似内容。

浮点数舍入错误演示详见 [示例代码](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/example/floaterr.c)。

### 复数和虚数类型

三种复数类型：`float_Complex`、`double_Complex`、`long double_Complex`。

三种虚数类型：`float_Imaginary`、`double_Imaginary`、`long double_Imaginary`。

复数类型的变量应该包含两个`float`类型的值，分别表示复数的实部和虚部。

> 如果包含`complex.h`头文件，可用`complex`代替`_Complex`，用`imaginary`代替`_Imaginary`，还可以用`I`代替-1的平方根。

### 类型大小

`sizeof`是C语言的内置运算符，以字节为单位给出指定类型的大小。

C99 和C11提供`%zd`转换说明匹配`sizeof`的返回类型。一些不支持C99和C11的 编译器可用`%u`或`%lu`代替`%zd`。

`sizeof`的使用演示详见 [示例代码](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-3%20Data%20and%20C/example/3.8-typesize.c)