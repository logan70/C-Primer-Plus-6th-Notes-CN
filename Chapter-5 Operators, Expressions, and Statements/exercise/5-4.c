// 编写一个程序，提示用户输入一个身高（单位：厘米），
// 并分别以厘米和英寸为单位显示该值，允许有小数部分。
// 程序应该能让用户重复输入身高，直到用户输入一个非正值。其输出示例如下：
// Enter　a　height　in　centimeters:　182
// 182.0　cm　=　5　feet,　11.7　inches
// Enter　a　height　in　centimeters　(<=0　to　quit):　168.7
// 168.0　cm　=　5　feet,　6.4　inches
// Enter　a　height　in　centimeters　(<=0　to　quit):　0
// bye
#include <stdio.h>
#define CM_PER_INCH 2.54
#define INCH_PER_FEET 12.0

int main(void)
{
  int feets;
  double input, inches, minches;
  printf("Enter a height in centimeters: ");
  scanf("%lf", &input);
  while(input > 0)
  {
    inches = input / CM_PER_INCH;
    feets = (int)(inches / INCH_PER_FEET);
    minches = inches - (feets * INCH_PER_FEET);
    printf("%.1f cm = %d feet, %.1f inches\n",
    input, feets, minches);
    printf("Enter a height in centimeters (<= 0 to quit): ");
    scanf("%lf", &input);
  }
  printf("bye\n");
  return 0;
}