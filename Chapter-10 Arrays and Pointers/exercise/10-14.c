// 14. 以变长数组作为函数形参，完成编程练习13。
#include <stdio.h>
#define ROWS 3
#define COLS 5
void get_input_arr2d(int rows, int cols, double ar[rows][cols]);
void print_arr2d(int rows, int cols, double ar[rows][cols]);
double get_average(int n, double ar[n]);
double get_average2d(int rows, int cols, double ar[rows][cols]);
double get_max2d(int rows, int cols, double ar[rows][cols]);

int main(void)
{
  int i;
  double ar[ROWS][COLS];
  get_input_arr2d(ROWS, COLS, ar);
  printf("The array is: \n");
  print_arr2d(ROWS, COLS, ar);
  for (i = 0; i < ROWS; i++)
  printf("The average of sub array %d is %.2f\n",
    i + 1, get_average(COLS, ar[i]));
  printf("The average of all value is %.2f\n",
    get_average2d(ROWS, COLS, ar));
  printf("The max value is %.2f\n",
    get_max2d(ROWS, COLS, ar));
  return 0;
}

void get_input_arr2d(int rows, int cols, double ar[rows][cols])
{
  int i;
  for (i = 0; i < ROWS; i++)
  {
    printf("Please enter 5 digits to fill the %d sub array: ", i + 1);
    scanf("%lf %lf %lf %lf %lf",
    ar[i] + 0, ar[i] + 1, ar[i] + 2, ar[i] + 3, ar[i] + 4);
  }
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
      printf("%.2f ", ar[r][c]);
    }
    printf("]\n");
  }
  printf("]\n");
}
double get_average(int n, double ar[n])
{
  int i;
  double total;
  for (total = 0,i = 0; i < n; i++)
  total += ar[i];
  return total / n;
}
double get_average2d(int rows, int cols, double ar[rows][cols])
{
  int r, c;
  double total = 0;
  for (r = 0; r < rows; r++)
  for (c = 0; c < cols; c++)
  total += ar[r][c];
  return total / (rows * cols);
}
double get_max2d(int rows, int cols, double ar[rows][cols])
{
  int r, c;
  double max = ar[0][0];
  for (r = 0; r < rows; r++)
  for (c = 0; c < cols; c++)
  if (ar[r][c] > max)
  max = ar[r][c];
  return max;
}
