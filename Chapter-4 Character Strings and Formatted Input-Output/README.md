# 第四章 字符串和格式化输入/输出

## 字符串

**字符串（character string）** 是一个或多个字符的序列。

字符串存储在`char`类型的数组中，字符串中的字符存储在相领的存储单元中，每个单元存储一个字符。

> **数组** 是同类型数据元素的有序序列，是连续的存储单元。

**空字符（null character）** `\0` 用于标记字符串的结束，其ASCII码值是0。

C中的字符串一定以空字符结束，所以数组的容量必须至少比待存储字符串中的字符数多1.

> scanf()在遇到第一个空白字符（空格、制表符或换行符）时就不再读取输入。

**strlen()** 函数给出字符串中的字符长度。

## 常量和C预处理器

预处理器可以用来定义常量，语法为`#define NAME value`：

```c
#define PI 3.14
#define BEEP '\a'
#define TEE 'T'
#define OPPS "Now you have done it!"
```

编译程序时，程序中所有的`NAME`都会被`value`替换。这样定义的常量也成为 **明示常量（manifest constant）**。

#### const 限定符

**const限定符** 用于限定一个变量为只读，为C90标准新增。

```c
const int MONTHS = 12; // MONTHS在程序中不可更改
```

### 明示常量

C头文件 `limits.h` 提供了与整数类型相关的详细信息。其中部分常用明示常量见下图：

![整数类型相关明示常量](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/1-manifest-constants-limits.png?raw=true)

C头文件 `float.h` 提供了与浮点类型相关的详细信息。其中部分常用明示常量见下图：

![浮点类型相关明示常量](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/2-manifest-constants-float.png?raw=true)

[示例程序](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.5-defines.c) 演示了如何使用`float.h`和`limits.h`中的数据。

## printf()和scanf()

### printf()函数

> 打印百分号`%`时使用两个百分号即可。

一些常见的转换说明和各自对应的输出类型见下图：

![printf()转换说明](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/3-printf-conversion-specification.png?raw=true)

[实例程序](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.6-printout.c) 演示了一些转换说明的使用。

**printf()的转换说明修饰符**

在`%`和转换字符之间插入修饰符可修饰基本的转换说明。

`printf()`中的修饰符见下图：

![printf()的修饰符](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/4-printf-modifier.png?raw=true)

`printf()`中的标记见下图：

![printf()中的标记](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/5-printf-flags.png?raw=true)

[示例程序 width.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.7-width.c) 演示了如何使用修饰符和标记处理整形格式值。

[示例程序 floats.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.8-floats.c) 演示了如何使用修饰符处理浮点型格式值。

[示例程序 flags.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.9-flags.c) 演示了标记的使用。

[示例程序 stringf.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.10-stringf.c) 演示了如何使用修饰符和标记处理字符串格式值。

**转换说明的意义**

1. 转换说明应该与待打印值的类型相匹配。
    - [示例程序 intconv.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.11-intconv.c) 演示了整形转换说明与待打印值的类型不匹配的情况。
    - [示例程序 floatcnv.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.12-floatcnv.c) 演示了浮点型转换说明与待打印值的类型不匹配的情况。
2. `printf()`函数的返回值是其打印字符的个数。如果有输出错误，则返回一个负值。
    - [示例程序 prntval.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.13-prntval.c) 演示了`printf()`函数的返回值。 
3. 打印较长的字符串时有三种方法，[示例程序 longstrg.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.14-longstrg.c) 演示了三种方法的使用：
    - 使用多个`printf()`语句。
    - 使用反斜杠`\`（换行符）分隔。
    - 两个双引号括起来的字符串之间用空白隔开，会被看作一个字符串。

**使用scanf()**

`scanf()`用于读取不同格式的数据。和`printf()`不同的是，`scanf()`使用指向变量的指针。 [示例程序 input.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.15-input.c) 演示了`scanf()`的基本使用。

`scanf()`的转换说明如下图所示：

![scanf()的转换说明](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/6-scanf-modifier.png?raw=true)

`scanf()`转换说明中的修饰符如下图所示：

![scanf()转换说明中的修饰符1](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/7-scanf-flags.png?raw=true)
![scanf()转换说明中的修饰符2](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/images/7-scanf-flags-2.png?raw=true)

> `scanf()`函数允许把普通字符放在格式字符串中。除空格字符外的普通字符必须与输入字符串严格匹配。格式字符串中的空白意味着跳过下一个输入项前面的所有空白，**所有空白**包括没有空白的特殊情况。

> `scanf()`返回成功读取的项数。

**printf()和scanf()的`*`修饰符**

`printf()`的`*`修饰符用于替代浮点值指定精度和字段宽度，通过参数来指定，[示例程序 varwid.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.16-varwid.c) 演示了相关用法。

`scanf()`的`*`修饰符，用于跳过相应的输出项，[示例程序 skip2.c](https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/Chapter-4%20Character%20Strings%20and%20Formatted%20Input-Output/example/4.17-skip2.c) 演示了相关用法。

