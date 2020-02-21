// 16. Daphne以10%的单利息投资了100美元（也就是说，
// 每年投资获利相当于原始投资的10%）。
// Deirdre以5%的复合利息投资了 100 美元（也就是说，利息是当前余额的5%，
// 包含之前的利息）。编写一个程序，
// 计算需要多少年Deirdre的投资额才会超过Daphne，并显示那时两人的投资额。
#include <stdio.h>
#define ORIGINAL_MONEY 100.0

int main(void)
{
  int year = 0;
  double money1 = ORIGINAL_MONEY, money2 = ORIGINAL_MONEY;
  const double RATE1 = 0.1, RATE2 = 0.05;
  do {
    money1 += ORIGINAL_MONEY * RATE1;
    money2 += money2 * RATE2;
    year++;
  } while (money2 <= money1);
  printf("money1 = %.2f, money2 = %.2f, year = %d.\n",
  money1, money2, year);
  return 0;
}