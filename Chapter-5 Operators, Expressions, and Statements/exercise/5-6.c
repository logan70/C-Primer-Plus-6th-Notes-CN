// 修改编程练习5的程序，使其能计算整数的平方和（可以认为第1天赚 $1、第2天赚$4、第3天赚$9，以此类推，这看起来很不错）。
// C没有平方函数，但是可以用n * n来表示n的平方。
#include <stdio.h>

int main(void) // 计算20个整数的和
{
  int i = 0, sum = 0, days;
  printf("Please enter the number of days:\n");
  scanf("%d", &days);
  while (i++ < days)
  {
    sum = sum + i * i;
  }
  printf("sum = %d\n", sum);
  return 0;
}