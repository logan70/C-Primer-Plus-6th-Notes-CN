// 9. 编写一个程序，初始化一个double类型的3×5二维数组，使用一个处理变长数组
// 的函数将其拷贝至另一个二维数组中。还要编写一个以变长数组为形参的函数以显示
// 两个数组的内容。这两个函数应该能处理任意N×M数组
// （如果编译器不支持变长数组，就使用传统C函数处理N×5的数组）。
#include <stdio.h>
void copy_arr2d(int rows, int cols, double source[rows][cols], double target[rows][cols]);
void print_arr2d(int rows, int cols, double ar[rows][cols]);

int main(void)
{
  double source[3][5] = {
    { 1.1, 2.2, 3.3, 4.4, 5.5 },
    { 11.1, 12.2, 13.3, 14.4, 15.5 },
    { 21.1, 22.2, 23.3, 24.4, 25.5 }
  };
  double target[3][5];
  copy_arr2d(3, 5, source, target);
  printf("source: \n");
  print_arr2d(3, 5, source);
  printf("target: \n");
  print_arr2d(3, 5, target);
  return 0;
}

void copy_arr2d(int rows, int cols, double source[rows][cols], double target[rows][cols])
{
  int r, c;
  for (r = 0; r < rows; r++)
  for (c = 0; c < cols; c++)
  target[r][c] = source[r][c];
}

void print_arr2d(int rows, int cols, double ar[rows][cols])
{
  int r, c;
  printf("[\n");
  for (r = 0; r < rows; r++)
  {
    printf("  [ ");
    for (c = 0; c < cols; c++)
    {
      printf("%.1f ", ar[r][c]);
    }
    printf("]\n");
  }
  printf("]\n");
}