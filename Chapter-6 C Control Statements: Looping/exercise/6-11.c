// 11. 编写一个程序，在数组中读入8个整数，然后按倒序打印这8个整数。
#include <stdio.h>
#define LENGTH 8

int main(void)
{
  int arr[LENGTH];
  int i = 0;
  do
  {
    printf("Enter a number: ");
    scanf("%d", &arr[i]);
  } while (++i < LENGTH);
  for (i = LENGTH - 1; i >= 0; i--)
  printf("%d\n", arr[i]);
  return 0;
}