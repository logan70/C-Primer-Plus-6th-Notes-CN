// 13. 编写一个程序，创建一个包含8个元素的int类型数组，
// 分别把数组元素设置为2的前8次幂。
// 使用for循环设置数组元素的值，使用do while循环显示数组元素的值。
#include <stdio.h>
#include <math.h>
#define LENGTH 8

int main(void)
{
  int arr[LENGTH];
  int i;
  for (i = 0; i < LENGTH; i++)
  {
    arr[i] = pow(2, i + 1);
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
