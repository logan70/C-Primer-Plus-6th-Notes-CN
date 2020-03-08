// 13. 编写一个程序，提示用户输入3组数，每组数包含5个double类型的数
// （假设用户都正确地响应，不会输入非数值数据）。该程序应完成下列任务
// a.把用户输入的数据储存在3×5的数组中
// b.计算每组（5个）数据的平均值
// c.计算所有数据的平均值
// d.找出这15个数据中的最大值
// e.打印结果
// 每个任务都要用单独的函数来完成（使用传统C处理数组的方式）。
// 完成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该函数3次。
// 对于处理其他任务的函数，应该把整个数组作为参数，
// 完成任务c和d的函数应把结果返回主调函数。
#include <stdio.h>
#define ROWS 3
#define COLS 5
void get_input_arr2d(double ar[][COLS], int rows);
void print_arr2d(double ar[][COLS], int rows);
double get_average(double ar[], int n);
double get_average2d(double ar[][COLS], int rows);
double get_max2d(double ar[][COLS], int rows);

int main(void)
{
  int i;
  double ar[ROWS][COLS];
  get_input_arr2d(ar, ROWS);
  printf("The array is: \n");
  print_arr2d(ar, ROWS);
  for (i = 0; i < ROWS; i++)
  printf("The average of sub array %d is %.2f\n",
    i + 1, get_average(ar[i], COLS));
  printf("The average of all value is %.2f\n",
    get_average2d(ar, ROWS));
  printf("The max value is %.2f\n",
    get_max2d(ar, ROWS));
  return 0;
}

void get_input_arr2d(double ar[][COLS], int rows)
{
  int i;
  for (i = 0; i < ROWS; i++)
  {
    printf("Please enter 5 digits to fill the %d sub array: ", i + 1);
    scanf("%lf %lf %lf %lf %lf",
    ar[i] + 0, ar[i] + 1, ar[i] + 2, ar[i] + 3, ar[i] + 4);
  }
}
void print_arr2d(double ar[][COLS], int rows)
{
  int r, c;
  printf("[\n");
  for (r = 0; r < rows; r++)
  {
    printf("  [ ");
    for (c = 0; c < COLS; c++)
    {
      printf("%.2f ", ar[r][c]);
    }
    printf("]\n");
  }
  printf("]\n");
}
double get_average(double ar[], int n)
{
  int i;
  double total;
  for (total = 0,i = 0; i < n; i++)
  total += ar[i];
  return total / n;
}
double get_average2d(double ar[][COLS], int rows)
{
  int r, c;
  double total = 0;
  for (r = 0; r < rows; r++)
  for (c = 0; c < COLS; c++)
  total += ar[r][c];
  return total / (rows * COLS);
}
double get_max2d(double ar[][COLS], int rows)
{
  int r, c;
  double max = ar[0][0];
  for (r = 0; r < rows; r++)
  for (c = 0; c < COLS; c++)
  if (ar[r][c] > max)
  max = ar[r][c];
  return max;
}
