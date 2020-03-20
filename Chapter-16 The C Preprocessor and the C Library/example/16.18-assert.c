// assert.c - 使用assert.c
#include <stdio.h>
#include <math.h>
#define NDEBUG
#include <assert.h>

int main(void)
{
  double x, y, z;
  puts("Enter a pair of numbers (0 0 to quit):");
  while (scanf("%lf %lf", &x, &y) == 2 && (x != 0 || y != 0))
  {
    z = x * x - y * y;
    assert(z >= 0);
    printf("answer is %f\n", sqrt(z));
    puts("Next pair of numbers: ");
  }
  puts("Done");
  return 0;
}