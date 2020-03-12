// r_drive1.c - 测试rand1和srand1()
// 与s_and_r.c一起编译
#include <stdio.h>
#include <stdlib.h>
extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
  int count;
  unsigned seed;
  printf("Please enter your choice for seed.\n");
  while (scanf("%u", &seed) == 1)
  {
    srand1(seed); // 重置种子
    for (count = 0; count < 5; count++)
    printf("%d\n", rand1());
    printf("Please enter next seed(q to quit):\n");
  }
  printf("Done\n");
  return 0;
}