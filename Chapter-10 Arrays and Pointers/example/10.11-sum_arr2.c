// sum_arr2.c - 数组元素之和
#include <stdio.h>
#define SIZE 10
int sum(int * start, int * end);
int main(void)
{
  int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
  long answer;
  answer = sum(marbles, marbles + SIZE);
  printf("The total number of marbles is %ld.\n", answer);
  printf("The size of marbles is %zd bytes.\n", sizeof marbles);
  return 0;
}

int sum(int * start, int * end)
{
  int total = 0;
  while (start < end)
  {
    total += *start;
    start++;
  }
  return total;
}