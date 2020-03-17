1.下面字符串的声明有什么问题？

```c
int main(void) 
{
  char name[] = { F', 'e', 's', 's' };
  ...
}
```

没有空字符'\0'，不是字符串。

## 2.下面的程序会打印什么？

```c
#include <stdio.h>
int main(void) 
{
  char note[] = "See you at the snack bar.";
  char *ptr;
  ptr = note;
  puts(ptr);
  puts(++ptr);
  note[7] = '\0';
  puts(note);
  puts(++ptr);
  return 0;
}
```

打印如下内容：

```
See you at the snack bar.
ee you at the snack bar.
See you
e you
```

## 3.下面的程序会打印什么？

```c
#include <stdio.h>
#include <string.h>
int main(void) 
{
  char food [] = "Yummy";
  char *ptr;
  ptr = food + strlen(food);
  while (--ptr >= food) puts(ptr);
  return 0;
}
```

打印如下内容：

```
y
my
mmy
ummy
Yummy
```

## 4.下面的程序会打印什么？

```c
#include <stdio.h>
#include <string.h>
int main(void)
{
  char goldwyn[40] = "art of it all ";
  char samuel[40] = "I read p";
  const char * quote = "the way through.";
  strcat(goldwyn, quote);
  strcat(samuel, goldwyn);
  puts(samuel);
  return 0;
}
```

打印如下内容：

```
I read part of it all the way through.
```


## 5.下面的练习涉及字符串、循环、指针和递增指针。首先，假设定义了 下面的函数：
 
 ```c
#include <stdio.h>
char *pr(char *str) 
{
  char *pc;
  pc = str;
  while (*pc) putchar(*pc++);
  do 
  {
    putchar(*--pc);
  } while (pc - str);
  return (pc);
}
```

考虑下面的函数调用： x = pr("Ho Ho Ho!");

- a.将打印什么？

打印`Ho Ho Ho!!oH oH oH`。

- b.x是什么类型？

x是指向字符`char`指针类型。

- c.x的值是什么？

x的值是第一个字符`H`的地址。

- d.表达式`*--pc`是什么意思？与`--*pc`有何不同？

`*--pc`是将pc指针向前移动一个字符，然后解引用pc指向的值；

`--*pc`是先解引用pc指向字符的值，再将其减一。

- e.如果用`*--pc`替换`--*pc`，会打印什么？



- f.两个while循环用来测试什么？

`while(*pc)`检查pc是否指向空字符。

`while(pc - str)`检查pc是否与str指向相同的位置

- g.如果pr()函数的参数是空字符串，会怎样？

死循环，第一个while不满足，pc没有自增，do内自减一次，即此时pc比str小一个字节，第二个while内的条件永远满足。

- h.必须在主调函数中做什么，才能让pr()函数正常运行？

必须声明函数原型。


## 6.假设有如下声明： 

`char sign = '$';`

sign占用多少字节的内存？`'$'`占用多少字节的内存？`"$"`占用多少字节的内存？

sign是个字符变量，占用一个字节。

`'$'`是个字符常量，储存为int类型，占用两个字节或四个字节。

`"$"`是个字符串常量，还有个空字符`'\0'`，所以占用两个字节。


## 7.下面的程序会打印出什么？


```c
#include <stdio.h>
#include <string.h>
#define M1 "How are ya, sweetie? "
char M2[40] = "Beat the clock.";
char * M3 = "chat";

int main(void) 
{
  char words[80];
  printf(M1);
  puts(M1);
  puts(M2);
  puts(M2 + 1);
  strcpy(words, M2);
  strcat(words, " Win a toy.");
  puts(words);
  words[4] = '\0';
  puts(words);
  while (*M3) puts(M3++);
  puts(--M3);
  puts(--M3);
  M3 = M1;
  puts(M3);
  return 0;
}
```

打印如下内容：

```
How are ya, sweetie? How are ya, sweetie? 
Beat the clock.
eat the clock.
Beat the clock. Win a toy.
Beat
chat
hat
at
t
t
at
How are ya, sweetie? 
```


## 8.下面的程序会打印出什么？
 
 ```c
#include <stdio.h>
int main(void) 
{
  char str1 [] = "gawsie";
  char str2 [] = "bletonism";
  char *ps;
  int i = 0;
  for (ps = str1; *ps != '\0'; ps++) 
  {
    if (*ps == 'a' || *ps == 'e')
    putchar(*ps);
    else
    (*ps)--;
    putchar(*ps);
  }
  putchar('\n');
  while (str2[i] != '\0') 
  {
    printf("%c", i % 3 ? str2[i] : '*');
    ++i;
  }
  return 0;
}
```

打印如下内容：

```
favrhe
*le*on*sm
```


## 9.本章定义的s_gets()函数，用指针表示法代替数组表示法便可减少一个 变量i。请改写该函数。

```c
#include <stdio.h>
char * s_gets(char * st, int n)
{
  char * ret_val;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    while (*st != '\n' || *st != '\0')
    st++;
    if (*st == '\n')
    *st = '\0';
    else
    while (getchar() != '\n')
    continue;
  }
  return ret_val;
}
```


## 10. `strlen()`函数接受一个指向字符串的指针作为参数，并返回该字符串 的长度。请编写一个这样的函数。

```c
#inlcude <stdio.h>
int strlen(const char * s)
{
  int ct = 0;
  while (*s++)
  ct++;
  return ct;
}
```


## 11.本章定义的s_gets()函数，可以用strchr()函数代替其中的while循环来 查找换行符。请改写该函数。

```c
#include <stdio.h>
char * s_gets(char * st, int n)
{
  char * ret_val;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    find = strchr(st, '\n');
    if (find)
    *find = '\0';
    else
    while (getchar() != '\n')
    continue;
  }
  return ret_val;
}
```


## 12.设计一个函数，接受一个指向字符串的指针，返回指向该字符串第1 个空格字符的指针，或如果未找到空格字符，则返回空指针。

```c
#include <stdio.h>
char * strblk(char * string)
{
  while (*string != ' ' && *string != '\0')
  string++;
  if (*string == '\0')
  return NULL;
  else
  return string;
}
```


## 13.重写程序清单11.21，使用ctype.h头文件中的函数，以便无论用户选 择大写还是小写，该程序都能正确识别答案。

```c
// compare.c - 该程序能正常运行
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANSWER "GRANT"
#define SIZE 40
char * s_gets(char *st, int n);
void ToUpper(char * str);
int main(void)
{
  char try[SIZE];
  puts("Who is buried in Grant's tomb?");
  s_gets(try, SIZE);
  ToUpper(try);
  while (strcmp(try, ANSWER) != 0)
  {
    puts("No, that's wrong, Try again.");
    s_gets(try, SIZE);
  }
  puts("That's right!");
  return 0;
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  int i = 0;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    while (st[i] != '\n' && st[i] != '\0')
    i++;
    if (st[i] == '\n')
    st[i] = '\0';
    else
    while (getchar() != '\n')
    continue;
  }
  return ret_val;
}

void ToUpper(char * str)
{
  while (*str != '\0')
  {
    *str = toupper(*str);
    str++;
  }
}

```