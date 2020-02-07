// 编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时间。
// 使用#define或const创建一个表示60的符号常量或const变量。
// 通过while循环让用户重复输入值，直到用户输入小于或等于0的值才停止循环。
#include <stdio.h>
#define MIN_PER_HOUR 60

int main(void)
{
  int inputMin, hour, min;
  printf("Please input the number of minutes:\n");
  scanf("%d", &inputMin);
  while (inputMin > 0)
  {
    hour = inputMin / MIN_PER_HOUR;
    min = inputMin % MIN_PER_HOUR;
    printf("%d minutes is %d hours and %d minutes.\n",
    inputMin, hour, min);
    printf("Please input the number of minutes:\n");
    scanf("%d", &inputMin);
  }
  printf("Done!\n");
  return 0;
}