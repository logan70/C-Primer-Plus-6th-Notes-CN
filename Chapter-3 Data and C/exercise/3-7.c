/**
 * 1英寸相当于2.54厘米。
 * 编写一个程序，提示用户输入身高（/英寸），然后以厘米为单位显示身高。
*/
#include <stdio.h>

int main(void)
{
  float inches;
  printf("请输入您的身高（单位：英寸）：");
  scanf("%f", &inches);
  // %.2f代表小数点后保留两位
  printf("您的身高转换为厘米为 %.2f 厘米\n", inches * 2.54);
  return 0;
}
