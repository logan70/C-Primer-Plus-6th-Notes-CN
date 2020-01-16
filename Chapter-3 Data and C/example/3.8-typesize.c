/* typesize.c - 打印类型大小 */
#include <stdio.h>

int main(void)
{
  /* C99为类型大小提供%zd转换说明 */
  printf("Type short has a size of %zd bytes.\n", sizeof(short));
  printf("Type int has a size of %zd bytes.\n", sizeof(int));
  printf("Type char has a size of %zd bytes.\n", sizeof(char));
  printf("Type long has a size of %zd bytes.\n", sizeof(long));
  printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
  printf("Type float has a size of %zd bytes.\n", sizeof(float));
  printf("Type double has a size of %zd bytes.\n", sizeof(double));
  printf("Type long double has a size of %zd bytes.\n", sizeof(long double));
  return 0;
}
