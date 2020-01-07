// 编写一个程序把你的年龄转换成天数，并显示这两个值。这里不用考 虑闰年的问题。

#include <stdio.h>

int ageToDays(int age);

int main(void)
{
  int myAge = 26;
  int days = ageToDays(myAge);
  printf("age: %d, days: %d\n", myAge, days);
  return 0;
}

int ageToDays(int age)
{
  return age * 365;
}
