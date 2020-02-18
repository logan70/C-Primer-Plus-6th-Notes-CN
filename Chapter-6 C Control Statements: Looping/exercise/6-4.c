// 使用嵌套循环，按下面的格式打印字母：
// A
// BC
// DEF
// GHIJ
// KLMNO
// PQRSTU
#include <stdio.h>
#define ROWS 6

int main(void)
{
  char ch = 'A';
  int i, j;
  for (i = 1; i <= ROWS; i++)
  {
    for (j = 0; j < i; j++)
    printf("%c", ch++);
    printf("\n");
  }
  return 0;
}
