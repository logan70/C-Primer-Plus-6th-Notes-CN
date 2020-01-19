/**
 * 1个水分子的质量约为3.0×10 −23 克。1夸脱水大约是950克。
 * 编写一个程序，提示用户输入水的夸脱数，并显示水分子的数量。
*/
#include <stdio.h>

int main(void)
{
  float kt;
  printf("请输入水的夸脱数：");
  scanf("%f", &kt);
  printf("%f 夸脱水的水分子数量为 %e\n", kt, kt * 950 / 3.0e-23);
  return 0;
}
