// 编写一个程序，创建一个包含26个元素的数组，并在其中储存26个小写字母。
// 然后打印数组的所有内容。
#include <stdio.h>
#define COUNT 26
int main(void)
{
  char arr[COUNT];
  char ch = 'a';
  int i;
  for (i = 0; i < COUNT; i++)
  arr[i] = ch + i;
  for (i = 0; i < COUNT; i++)
  printf("%c", arr[i]);
  return 0;
}
