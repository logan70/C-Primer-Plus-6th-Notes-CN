// nono.c - 千万不要模仿
#include <stdio.h>

int main(void)
{
  char side_a[] = "Side A";
  char dont[] = { 'W', 'O', 'W', '!' };
  char side_b[] = "Side B";
  puts(dont); // dont 不是一个字符串
  return 0;
}