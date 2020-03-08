// 7. 编写一个程序，初始化一个double类型的二维数组，
// 使用编程练习2中的一个拷贝函数把该数组中的数据拷贝至另一个二维数组中
// （因为二维数组是数组的数组，所以可以使用处理一维数组的拷贝函数来处理数组中的
// 每个子数组）。
#include <stdio.h>
void copy_arr2d(int rows, int cols, double source[rows][cols], double target[rows][cols]);
void print_arr2d(int rows, int cols, double ar[rows][cols]);

int main(void)
{
  double source[2][2] = { { 1.1, 2.2 }, { 3.3, 4.4 } };
  double target[2][2];
  copy_arr2d(2, 2, source, target);
  printf("source: \n");
  print_arr2d(2, 2, source);
  printf("target: \n");
  print_arr2d(2, 2, target);
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
  for (r = 0; r < rows; r++)
  {
    for (c = 0; c < cols; c++)
    printf("%.1f ", ar[r][c]);
    putchar('\n');
  }
}