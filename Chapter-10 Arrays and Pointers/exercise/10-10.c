// 10. 编写一个函数，把两个数组中相对应的元素相加，然后把结果储存到第3个数组中。
// 也就是说，如果数组1中包含的值是2、4、5、8，数组2中包含的值是1、0、4、6，
// 那么该函数把3、4、9、14赋给第3个数组。函数接受3个数组名和一个数组大小。
// 在一个简单的程序中测试该函数。
#include <stdio.h>
void sum_arr(int ar1[], int ar2[], int sumar[], int n);
void print_arr(int ar[], int n);

int main(void)
{
  int ar1[] = { 2, 4, 5, 8 };
  int ar2[] = { 1, 0, 4, 6 };
  int sumar[4];
  sum_arr(ar1, ar2, sumar, 4);
  printf("ar1: \n");
  print_arr(ar1, 4);
  printf("ar2: \n");
  print_arr(ar2, 4);
  printf("sumar: \n");
  print_arr(sumar, 4);
  return 0;
}

void sum_arr(int ar1[], int ar2[], int sumar[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  sumar[i] = ar1[i] + ar2[i];
}
void print_arr(int ar[], int n)
{
  int i;
  printf("[ ");
  for (i = 0; i < n; i++)
  printf("%d ", ar[i]);
  printf("]\n");
}