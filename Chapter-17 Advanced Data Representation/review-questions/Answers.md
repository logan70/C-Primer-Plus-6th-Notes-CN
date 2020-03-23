## 1. 定义一种数据类型涉及哪些内容？

1. 如何存储数据
2. 涉及管理该数据的一系列函数

## 2. 为什么程序清单17.2 只能沿一个方向遍历链表？如何修改struct film定 义才能沿两个方向遍历链表？

因为film的结构只包含下一个结构的地址。加入上一个结构的地址即可实现双向遍历链表。

```c
struct film {
  char title[TSIZE];
  int rating;
  struct film * prev;
  struct film * next;
};
```

## 3. 什么是ADT？

ADT是抽象数据类型，是对一种类型属性集和可以对该类型进行的操作的正式定义。ADT应该用一般语言表示，而不是用某种特殊的计算机语言，而且不应该包含实现细节。

## 4. `QueueIsEmpty()`函数接受一个指向queue结构的指针作为参数，但是也可以将其编写成接受一个queue结构作为参数。这两种方式各有什么优缺点？

- 直接传递变量的优点：保证了函数不会更改原始数据。
- 直接传递变量的缺点：拷贝原始数据花费时间、空间。
- 传递变量地址的有点：传递大型结构，传递变量地址和访问原始数据更快，占用内存空间更少。
- 传递变量地址的缺点：函数可能更改原始数据，用`ANSI C`中的`const`限定符可以解决这个问题。

## 5. 栈（stack）是链表系列的另一种数据形式。在栈中，只能在链表的一端添加和删除项，项被“压入”栈和“弹出”栈。因此，栈是一种LIFO（即后进 先出last in,first out）结构。

- a. 设计一个栈ADT

```
类型名：栈
类型属性：可以储存有序项
类型操作：
  初始化栈为空
  确定栈是否为空
  确定栈是否已满
  从栈顶添加项（压入项）
  从栈顶删除项（弹出项）
```

- b. 为栈设计一个C编程接口，例如stack.h头文件

```c
// stack.h - 栈的接口
#include <stdbool.h>
#ifndef _STACK_H_
#define _STACK_H_

#define MAXSTACK 100
typedef struct stack
{
  Item items[MAXStack];
  int top; // 第一个空位索引
} Stack;

/**
 * 操作：初始化栈
 * 前提条件：ps指向一个栈
 * 后置条件：该栈被初始化为空
 */
void InitializeStack(Stack * ps);

/**
 * 操作：检查栈是否已满
 * 前提条件：ps指向之前已被初始化的栈
 * 后置条件：如果栈已满，该函数返回true；否则返回false
 */
bool IsStackFull(const Stack * ps);

/**
 * 操作：检查栈是否为空
 * 前提条件：ps指向之前已被初始化的栈
 * 后置条件：如果栈为空，该函数返回true；否则返回false
 */
bool IsStackEmpty(const Stack * ps);

/**
 * 操作：把项压入栈顶
 * 前提条件：ps指向之前已被初始化的栈
 * 后置条件：如果栈未满，把item放在栈顶，返回true；否则栈不变，返回false
 */
bool Push(Item item, Stack * ps);

/**
 * 操作：从栈顶删除项
 * 前提条件：ps指向之前已被初始化的栈
 * 后置条件：如果栈不为空，把栈顶的item拷贝到*pitem，删除栈顶的item，返回true；
 * 否则栈不变，返回false
 */
bool Pop(Item * pitem, Stack * ps);

#endif
```

## 6. 在一个含有3个项的分类列表中，判断一个特定项是否在该列表中， 用顺序查找和二叉查找方法分别需要最多多少次？当列表中有1023个项时分别是多少次？65535个项是分别是多少次？

- 3个项：顺序查找最多3次，二叉查找最多2次；
- 1023(2^10-1)个项：顺序查找最多1023次，二叉查找最多10次；
- 65535(2^16-1)个项：顺序查找最多65535次，二叉查找最多16次。

## 7. 假设一个程序用本章介绍的算法构造了一个储存单词的二叉查找树。 假设根据下面所列的顺序输入单词，请画出每种情况的树：

- a. `nice food roam dodge gate office wave`

```
          nice
        /     \
    food       roam
    / \       /    \
dodge  gate  office wave
```

- b. `wave roam office nice gate food dodge`

```
         wave
         /
       roam
        /
      office
       /
     nice
     /
   gate
    /
  food
  /
dodge
```

- c. `food dodge roam wave office gate nice`

```
          food
        /     \
    dodge       roam
       \       /    \
      gate  office  wave
             /
           nice
```

- d. `nice roam office food wave gate dodge`

```
          nice
        /     \
    food       roam
    / \       /    \
dodge  gate  office wave
```

## 8. 考虑复习题7构造的二叉树，根据本章的算法，删除单词food之后，各树是什么样子？

- a. `nice food roam dodge gate office wave`

```
          nice
        /     \
    dodge       roam
       \       /    \
      gate  office wave
```

- b. `wave roam office nice gate food dodge`

```
         wave
         /
       roam
        /
      office
       /
     nice
     /
   gate
  /
dodge
```

- c. `food dodge roam wave office gate nice`

```
dodge
    \
    gate
      \
      roam
      /    \
  office  wave
    /
  nice
```

- d. `nice roam office food wave gate dodge`

```
          nice
        /     \
    dodge       roam
       \       /    \
      gate  office wave
```