// 2. 编写一个程序，初始化一个double类型的数组，然后把该数组的内容拷贝至3个其他数组中
// （在main()中声明这4个数组）。使用带数组表示法的函数进行第1份拷贝。
// 使用带指针表示法和指针递增的函数进行第2份拷贝。 把目标数组名、源数组名和待拷贝的
// 元素个数作为前两个函数的参数。第3个函数以目标数组名、源数组名和指向源数组最后一个元素
// 后面的元素的指针。也就是说，给定以下声明，则函数调用如下所示：
// double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
// double target1[5];
// double target2[5];
// double target3[5];
// copy_arr(target1, source, 5);
// copy_ptr(target2, source, 5);
// copy_ptrs(target3, source, source + 5);
#include <stdio.h>
void copy_arr(double [], double [], int n);
void copy_ptr(double [], double [], int n);
void copy_ptrs(double *, double *, double *);
void printArr(double ar[], int n);

int main(void)
{
  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target1[5];
  double target2[5];
  double target3[5];
  copy_arr(target1, source, 5);
  copy_ptr(target2, source, 5);
  copy_ptrs(target3, source, source + 5);
  printf("target1: ");
  printArr(target1, 5);
  printf("target2: ");
  printArr(target2, 5);
  printf("target3: ");
  printArr(target3, 5);
  return 0;
}

void copy_arr(double target[], double source[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  target[i] = source[i];
}

void copy_ptr(double * target, double * source, int n)
{
  int i;
  for (i = 0; i < n; i++, source++, target++)
  *target = *source;
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

void printArr(double ar[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  printf("%.1f ", ar[i]);
  putchar('\n');
}