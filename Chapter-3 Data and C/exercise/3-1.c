/**
 * 通过试验（即编写带有此类问题的程序）观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况。
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
  int bigInt;
  float overflowFloat;
  float underflowFloat;
  bigInt = pow(2, 8 * sizeof(int) - 2);
  printf("%d", bigInt);
  return 0;
}
