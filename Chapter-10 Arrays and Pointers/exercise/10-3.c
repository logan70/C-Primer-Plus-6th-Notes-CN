// 3. 编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的程序中测试该函数。
#include <stdio.h>
int get_max(int ar[], int n);

int main(void)
{
  printf("The max in [5, 10, 15, 20] is %d\n",
  get_max((int []){ 5, 10, 15, 20 }, 4));
  return 0;
}

int get_max(int ar[], int n)
{
  int i, max;
  for (max = 0, i = 0; i < n; i++)
  if (ar[i] > max)
  max = ar[i];
  return max;
}