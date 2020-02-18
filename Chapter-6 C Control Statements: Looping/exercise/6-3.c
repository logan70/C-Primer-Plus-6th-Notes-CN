// 3. 使用嵌套循环，按下面的格式打印字母：
// F
// FE
// FED
// FEDC
// FEDCB
// FEDCBA
#include <stdio.h>
#define ROWS 6

int main(void)
{
  char ch = 'F';
  int i, j;
  for (i = 1; i <= ROWS; i++)
  {
    for (j = 0; j < i; j++)
    printf("%c", ch - j);
    printf("\n");
  }
  return 0;
}
