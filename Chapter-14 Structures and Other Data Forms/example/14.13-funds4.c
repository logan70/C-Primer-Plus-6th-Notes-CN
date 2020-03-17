// funds1.c - 把结构成员作为参数传递
#include <stdio.h>
#define FUNDLEN 50
#define N 2
struct funds {
  char bank[FUNDLEN];
  double bankfund;
  char save[FUNDLEN];
  double savefund;
};
double sum(const struct funds money[], int n);

int main(void)
{
  struct funds jones[N] = {
    {
      "Garlic-Melon Bank",
      4032.27,
      "Lucky's Savings and Loan",
      8543.94
    },
    {
      "Honest Jack's Bank",
      3620.88,
      "Party Time Savings",
      3802.91
    }
  };
  printf("The Joneses have a total of $%.2f.\n", sum(jones, N));
  return 0;
}
// 两个double 类型的数相加
double sum(const struct funds money[], int n)
{
  double total;
  int i;
  for (i = 0, total = 0; i < n; i++)
    total += money[i].bankfund + money[i].savefund;
  return total;
}