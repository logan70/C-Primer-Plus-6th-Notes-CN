/**
 * 一年大约有3.156e7秒。编写一个程序，提示用户输入年龄，然后显示该年龄对应的秒数。
*/

#include <stdio.h>
#define SECS_IN_ONE_YEAR (3.156e7)

int main(void)
{
  int age;
  printf("请输入您的年龄：");
  scanf("%d", &age);
  printf("该年龄对应 %e 秒\n", SECS_IN_ONE_YEAR * age);
  return 0;
}
