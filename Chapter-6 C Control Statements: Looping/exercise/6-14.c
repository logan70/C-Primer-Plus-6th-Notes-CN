// 14. 编写一个程序，创建两个包含8个元素的double类型数组，
// 使用循环提示用户为第一个数组输入8个值。
// 第二个数组元素的值设置为第一个数组对应元素的累积之和。
// 例如，第二个数组的第4个元素的值是第一个数组前4个元素之和，
// 第二个数组的第5个元素的值是第一个数组前5个元素之和
// （用嵌套循环可以完成，但是利用第二个数组的第5个元素是第二个数组的第4个元素
// 与第一个数组的第5个元素之和，只用一个循环就能完成任务，不需要使用嵌套循环）。
// 最后，使用循环显示两个数组的内容，第一个数组显示成一行，
// 第二个数组显示在第一个数组的下一行，而且每个元素都与第一 个数组各元素相对应。
#include <stdio.h>

int main(void)
{
  const int len = 8;
  double arr1[len], arr2[len];
  int i = 0;
  for (i = 0; i < len; i++)
  {
    printf("Enter a float num: ");
    scanf("%lf", &arr1[i]);
    if (i == 0) {
      arr2[i] = arr1[i];
    } else {
      arr2[i] = arr2[i - 1] + arr1[i];
    }
  }
  printf("\n");
  for (i = 0; i < len; i++)
  {
    printf("%6.2f", arr1[i]);
  }
  printf("\n");
  for (i = 0; i < len; i++)
  {
    printf("%6.2f", arr2[i]);
  }
  printf("\n");
  return 0;
}