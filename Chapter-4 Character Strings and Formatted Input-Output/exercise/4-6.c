// 4-6 
// 编写一个程序，先提示用户输入名，然后提示用户输入姓。
// 在一行打印用户输入的名和姓，下一行分别打印名和姓的字母数。
// 字母数要与相应名和姓的结尾对齐
// 接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐
#include <stdio.h>
#include <string.h>

int main(void)
{
  char fName[40];
  char lName[40];
  int len1, len2;
  printf("Please enter your first name:\n");
  scanf("%s", fName);
  printf("Please enter your last name:\n");
  scanf("%s", lName);
  len1 = (int)(strlen(fName));
  len2 = (int)(strlen(lName));
  printf("%s %s\n", fName, lName);
  printf("%*d %*d\n", len1, len1, len2, len2);
  printf("%s %s\n", fName, lName);
  printf("%-*d %-*d\n", len1, len1, len2, len2);
  return 0;
}