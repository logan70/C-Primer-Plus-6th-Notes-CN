// 15. 编写一个程序，读取一行输入，然后把输入的内容倒序打印出来。
// 可以把输入储存在char类型的数组中，假设每行字符不超过255。
// 回忆一下，根据%c转换说明，scanf()函数一次只能从输入中读取一个字符，
// 而且在用户按下Enter键时scanf()函数会生成一个换行字符（\n）。
#include <stdio.h>

int main(void)
{
  char str[255];
  int i = 0;
  do
  {
    scanf("%c", &str[i]);
  } while (str[i] != '\n' && ++i < 255);
  do {
    printf("%c", str[i]);
  } while (i-- > 0);
  printf("\n");
  return 0;
}