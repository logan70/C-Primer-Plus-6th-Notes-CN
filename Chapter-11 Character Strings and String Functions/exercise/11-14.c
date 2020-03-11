// 14. 编写一个通过命令行运行的程序计算幂。第1个命令行参数是double类型的数，
// 作为幂的底数，第2个参数是整数，作为幂的指数。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{
  double num;
  int exp;
  if (argc < 3)
    puts("Usage:<program_name> <num> <exp>");
  else
  {
    num = atof(argv[1]);
    exp = atoi(argv[2]);
    printf("%.2f ^ %d = %.2f\n", num, exp, pow(num, (double)exp));
  }
  return 0;
}