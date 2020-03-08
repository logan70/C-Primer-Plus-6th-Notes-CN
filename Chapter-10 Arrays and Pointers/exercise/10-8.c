// 8. 使用编程练习2中的拷贝函数，把一个内含7个元素的数组中第3～第5个元素拷贝
// 至内含3个元素的数组中。该函数本身不需要修改，只需要选择合适的实际参数
// （实际参数不需要是数组名和数组大小，只需要是数组元素的地址和待处理元素的个数）。
#include <stdio.h>
void copy_ptrs(double * target, double *start, double *end);
void print_arr(double ar[], int n);

int main(void)
{
  double source[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
  double target[3];
  copy_ptrs(target, source + 2, source + 5);
  printf("source: ");
  print_arr(source, 7);
  printf("target: ");
  print_arr(target, 3);
  return 0;
}
void copy_ptrs(double * target, double *start, double *end)
{
  while (start < end)
  {
    *target = *start;
    start++;
    target++;
  }
}


void print_arr(double ar[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  printf("%.1f ", ar[i]);
  putchar('\n');
}