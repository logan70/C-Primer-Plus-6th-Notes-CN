// postage.c - 一类邮资
#include <stdio.h>

int main(void)
{
  const int FIRST_OZ = 46;
  const int NEXT_OZ = 20;
  int ounces, cost;
  printf("  ounces  cost\n");
  for (ounces = 1, cost = FIRST_OZ; ounces <= 16;
  ounces++, cost += NEXT_OZ)
  printf("%5d     $%4.2f\n", ounces, cost / 100.0);
  return 0;
}