// 为了让程序清单9.8中的to_binary()函数更通用，编写一个to_base_n()
// 函数接受两个在2～10范围内的参数，然后以第2个参数中指定的进制打印第1个参数的数值。
// 例如，to_base_n(129， 8)显示的结果为201，也就是129的 八进制数。
// 在一个完整的程序中测试该函数。
#include <stdio.h>

void to_base_n(int num, int sys)
{
  if (sys < 2 || sys > 10)
  {
    printf("The secont argument must between 2 and 10.\n");
  }
  if (num >= sys)
    to_base_n(num / sys, sys);
  printf("%d", num % sys);
}
int main(void)
{
  to_base_n(129, 8);
  putchar('\n');
  to_base_n(129, 2);
  return 0;
}