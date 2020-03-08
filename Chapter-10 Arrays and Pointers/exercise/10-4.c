// 4. 编写一个函数，返回储存在double类型数组中最大值的下标，
// 并在一个简单的程序中测试该函数。
#include <stdio.h>
int get_max_index(double ar[], int n);

int main(void)
{
  printf("The index of the biggest value in [2.3, 1.8, 3.5] is: %d\n",
  get_max_index((double []){ 2.3, 1.8, 3.5 }, 3));
  return 0;
}

int get_max_index(double ar[], int n)
{
  int i, max_idx;
  double max;
  for (i = 0, max = ar[i]; i < n; i++)
  {
    if (ar[i] > max)
    {
      max = ar[i];
      max_idx = i;
    }
  }
  return max_idx;
}