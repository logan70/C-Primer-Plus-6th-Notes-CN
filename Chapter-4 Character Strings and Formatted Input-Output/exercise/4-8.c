// 4-8
// 编写一个程序，提示用户输入旅行的里程和消耗的汽油量。
// 然后计算并显示消耗每加仑汽油行驶的英里数，显示小数点后面一位数字。
// 接下来，使用1加仑大约3.785升，1英里大约为1.609千米，
// 把单位是英里/加仑的值转换为升/100公里（欧洲通用的燃料消耗表示法），
// 并显示结果，显示小数点后面 1 位数字。
// 注意，美国采用的方案测量消耗单位燃料的行程（值越大越好），
// 而欧洲则采用单位距离消耗的燃料测量方案（值越低越好）。
// 使用 #define 创建符号常量或使用 const 限定符创建变量来表示两个转换系数。
#include <stdio.h>
#define GALLON_TO_LITRE 3.785
#define MILE_TO_KM 1.609

int main(void)
{
  double mileage, consumption, stdUS, stdEU;
  printf("Please enter your mileage(miles):\n");
  scanf("%lf", &mileage);
  printf("Please enter your consumption(gallons):\n");
  scanf("%lf", &consumption);
  stdUS = mileage / consumption;
  printf("%.1f miles per gallon.\n", stdUS);
  stdEU = (consumption * GALLON_TO_LITRE) / (mileage * MILE_TO_KM / 100);
  printf("%.1f litres per 100km.\n", stdEU);
  return 0;
}