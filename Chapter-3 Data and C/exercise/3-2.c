/**
 * 编写一个程序，要求提示输入一个ASCII码值（如，66），然后打印输入的字符
*/
#include <stdio.h>

int main(void)
{
  int ascii;
  printf("请输入一个ASCII码值（如，66）：\n");
  scanf("%d", &ascii);
  printf("您输入的ASCII码转换为字符后为：%c\n", ascii);
  return 0;
}
