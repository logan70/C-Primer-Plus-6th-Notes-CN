// 11. 编写一个程序，声明一个int类型的3×COLS二维数组，并用合适的值初始化它。
// 该程序打印数组中的值，然后各值翻倍（即是原值的2倍），并显示出各元素的新值。
// 编写一个函数显示数组的内容，再编写一个函数把各元素的值翻倍。
// 这两个函数都以函数名和行数作为参数。
#include <stdio.h>
#define COLS 5
void print_arr2d(int ar[][COLS], int rows);
void double_arr2d(int ar[][COLS], int rows);

int main(void)
{
  int ar[][COLS] = {
    { 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10 },
    { 11, 12, 13, 14, 15 }
  };
  printf("arr before doubled: \n");
  print_arr2d(ar, 3);
  double_arr2d(ar, 3);
  printf("arr after doubled: \n");
  print_arr2d(ar, 3);
  return 0;
}

void double_arr2d(int ar[][COLS], int rows)
{
  int r, c;
  for (r = 0; r < rows; r++)
  for (c = 0; c < COLS; c++)
  ar[r][c] *= 2;
}
void print_arr2d(int ar[][COLS], int rows)
{
  int r, c;
  printf("[\n");
  for (r = 0; r < rows; r++)
  {
    printf("  [ ");
    for (c = 0; c < COLS; c++)
    {
      printf("%d ", ar[r][c]);
    }
    printf("]\n");
  }
  printf("]\n");
}