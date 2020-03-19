// qsorter.c - 用qsort()排序一组数字
#include <stdio.h>
#include <stdlib.h>
#define NUM 40
void fillarray(double ar[], int n);
void showarray(double ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
  double vals[NUM];
  fillarray(vals, NUM);
  puts("Random list:");
  showarray(vals, NUM);
  qsort(vals, NUM, sizeof(double), mycomp);
  puts("\nSorted list:");
  showarray(vals, NUM);
  return 0;
}

void fillarray(double ar[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    ar[i] = (double)rand() / ((double)rand() + 0.1);
}

void showarray(double ar[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%9.4f", ar[i]);
    if (i % 6 == 5)
      putchar('\n');
  }
  if (i % 6 != 0)
    putchar('\n');
}

// 按从小到大排序
int mycomp(const void * p1, const void * p2)
{
  // 要使用指向double的指针来访问这两个值
  const double * a1 = (const double *) p1;
  const double * a2 = (const double *) p2;
  if (*a1 < *a2)
    return -1;
  else if (*a1 == *a2)
    return 0;
  else
    return 1;
}