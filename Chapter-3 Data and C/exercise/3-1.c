/**
 * 通过试验（即编写带有此类问题的程序）观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况。
 */
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#define BIAS (pow(2, 7) - 1)

int main(void)
{
  /**
   * int类型最大值及int类型上溢
   * 最大值即符号位为0，其余数值位为1。
   * 假设为int类型存储为n位，则 2^(n - 1) - 1
   */
  int maxInt;
  maxInt = (int)(pow(2, 8 * sizeof(int) - 1) - 1);
  printf("头文件常量 INT_MAX 值为 %d\n", INT_MAX);
  printf("手动计算int类型的最大值为 %d\n", maxInt);
  if (INT_MAX == maxInt) {
    printf("两者相等\n");
  } else {
    printf("两者不相等");
  }
  printf("最大值加1后为 %d\n\n", maxInt + 1);

  /**
   * int类型最小值及int类型下溢
   * 假设为int类型存储为n位，最小值即符号位为1，其余数值位为0
   * 不是-0，而是代表- 2^(n - 1)。
   */
  int minInt;
  minInt = -(int)(pow(2, 8 * sizeof(int) - 1));
  printf("头文件常量 INT_MIN 值为 %d\n", INT_MIN);
  printf("手动计算int类型的最小值为 %d\n", minInt);
  if (INT_MIN == minInt) {
    printf("两者相等\n");
  } else {
    printf("两者不相等\n");
  }
  printf("最小值减1后为 %d\n\n", minInt - 1);

  // float类型最大值
  // float类型在我的设备上是4字节，32位，1位符号位，8位指数位，23位尾数位
  // 指数位有128的偏移量，即范围为-128~127
  // 指数位全为1时代表特殊值
  // 故符号位为0，指数位除最后一位全为1，尾数位全为1时得到最大值
  float maxFloat;
  maxFloat = (2 - pow(2, -23)) * pow(2, (pow(2, 8) - 2 - BIAS));
  printf("头文件常量 FLT_MAX 值为 %e\n", FLT_MAX);
  printf("手动计算float类型的最大值为 %e\n", maxFloat);
  if (FLT_MAX == maxFloat) {
    printf("两者相等\n");
  } else {
    printf("两者不相等\n");
  }
  printf("最大值乘2后为 %e\n\n", maxFloat * 2);

  // float类型最小格式化数
  // 指数位全为0表示的是非格式化值，即不包含隐含的开头的 1
  // 故符号位为0，指数位最后一位为1、其他为0，尾数位全为0时表示float类型最小格式化数
  float minFloat;
  minFloat = 1 * pow(2, 1 - BIAS);
  printf("头文件常量 FLT_MIN 值为 %e\n", FLT_MIN);
  printf("手动计算float类型的最小值为 %e\n", minFloat);
  if (FLT_MIN == minFloat) {
    printf("两者相等\n");
  } else {
    printf("两者不相等\n");
  }
  printf("减去极小数后的最小值仍不变，发生下溢 %e\n\n", minFloat - 1e-58);
  return 0;
}
