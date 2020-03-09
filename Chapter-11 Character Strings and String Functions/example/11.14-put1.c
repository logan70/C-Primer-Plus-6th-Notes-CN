// put1.c - 打印字符串，不添加\n
#include <stdio.h>

void put1(const char * string)
{
  while (*string != '\0')
  putchar(*string++);
}