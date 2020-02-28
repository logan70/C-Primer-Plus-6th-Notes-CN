// binary.c - 以二进制形式打印十进制整数
#include <stdio.h>
void to_binary(unsigned long n);

int main(void)
{
  unsigned long number;
  printf("Enter an integer (q to quit):\n");
  while (scanf("%lu", &number) == 1)
  {
    printf("Binary equivalent: ");
    to_binary(number);
    putchar('\n');
    printf("Enter an integer (q to quit):\n");
  }
  printf("Done.\n");
  return 0;
}

void to_binary(unsigned long n)
{
  if (n >= 2)
  to_binary(n / 2);
  printf("%u", (unsigned int)n % 2);
}