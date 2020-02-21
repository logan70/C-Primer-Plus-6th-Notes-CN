// 17. Chuckie Lucky赢得了100万美元（税后），他把奖金存入年利率8%的账户。
// 在每年的最后一天，Chuckie取出10万美元。编写一个程序，计算多少年后
// Chuckie会取完账户的钱？
#include <stdio.h>

int main(void)
{
  double sum = 100.0;
  int year = 0;
  do {
    year++;
    sum += sum * 0.08 - 10;
  } while (sum > 0);
  printf("year = %d\n", year);
  return 0;
}