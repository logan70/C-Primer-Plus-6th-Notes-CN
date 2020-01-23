// 4-1 编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。
#include <stdio.h>

int main(void)
{
  char fName[40];
  char lName[40];
  printf("Please enter your first name:\n");
  scanf("%s", fName);
  printf("Please enter your last name:\n");
  scanf("%s", lName);
  printf("%s,%s\n", fName, lName);
  return 0;
}