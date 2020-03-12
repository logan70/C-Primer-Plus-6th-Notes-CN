// 6. 编写一个程序，生成1000个1～10范围内的随机数。
// 不用保存或打印这些数字，仅打印每个数出现的次数。
// 用10个不同的种子值运行，生成的数字出现的次数是否相同？
// 可以使用本章自定义的函数或ANSI C的rand()和srand()函数，它们的格式相同。
// 这是一个测试特定随机数生成器随机性的方法。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 1000
void anaylize(int * ar, int n);

int main(void)
{
  int ar[LIM];
  int seed, i;
  for (seed = 1; seed <= 10; seed++)
  {
    srand(seed);
    for (i = 0; i < LIM; i++)
      ar[i] = rand() % 10 + 1;
    anaylize(ar, LIM);
  }
}

void anaylize(int * ar, int n)
{
  static int times = 0;
  int i;
  int * pr;
  pr = (int *) calloc(10, sizeof(int));
  for (i = 0; i < n; i++)
    pr[ar[i] - 1]++;
  printf("Anaylize %d time(s): \n", ++times);
  for (i = 0; i < 10; i++)
    printf("%d: %d times\n", i + 1, *(pr + i));
  free(pr);
}
