// 编写一个程序，生成100个1～10范围内的随机数，并以降序排列
// （可以把第11章的排序算法稍加改动，便可用于整数排序，这里仅对整数排序）。
#include <stdio.h>
#include <stdlib.h>
#define LIM 100

void sort_desc(int * ar, int n);

int main(void)
{
  int ar[LIM];
  int i;
  for (i = 0; i < LIM; i++)
  ar[i] = (int)rand() % 10 + 1;
  sort_desc(ar, LIM);
  for (i = 0; i < LIM; i++)
  {
    printf("%2d ", ar[i]);
    if (i % 10 == 9)
      putchar('\n');
  }
}

void sort_desc(int * ar, int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  for (j = i; j < n; j++)
    if (ar[i] < ar[j])
    {
      temp = ar[i];
      ar[i] = ar[j];
      ar[j] = temp;
    }
}
