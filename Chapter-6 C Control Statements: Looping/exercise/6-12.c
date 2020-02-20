// 12. 考虑下面两个无限序列：
// 1.0　+　1.0/2.0　+　1.0/3.0　+　1.0/4.0　+　...
// 1.0　-　1.0/2.0　+　1.0/3.0　-　1.0/4.0　+　...
// 编写一个程序计算这两个无限序列的总和，直到到达某次数。
// 提示：奇数个-1 相乘得-1，偶数个-1相乘得1。
// 让用户交互地输入指定的次数，当用户输入0或负值时结束输入。
// 查看运行100项、1000项、10000项后的总和， 是否发现每个序列都收敛于某值？
#include <stdio.h>
#define BASE 1.0

int main(void)
{
  double divisor = BASE, dividend;
  double result1, result2;
  int count, i;
  printf("Enter the count: ");
  while (scanf("%d", &count) == 1)
  {
    for (i = 0, dividend = 0, result1 = 0, result2 = 0; i < count; i++)
    {
      result1 += divisor / ++dividend;
      if (i % 2 == 0) {
        result2 += divisor / dividend;
      } else {
        result2 -= divisor / dividend;
      }
    }
    printf("%f %f\n", result1, result2);
    printf("Enter the count(q to quit): ");
  }
  printf("Done\n");
  return 0;
}
