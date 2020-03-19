// doubincl.c - 包含头文件两次
#include <stdio.h>
#include "16.10-names.h"
#include "16.10-names.h" // 不小心第二次包含头文件

int main(void)
{
  puts(__FILE__);
  printf("%d\n", __LINE__);
  printf("%ld\n", __STDC_VERSION__);
  names winner = { "Less", "Ismoor" };
  printf("The winner is %s %s.\n", winner.first, winner.last);
  return 0;
}