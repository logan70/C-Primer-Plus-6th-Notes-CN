// 编写一个程序，创建一个整型变量toes，并将toes设置为10。
// 程序中还要计算toes的两倍和toes的平方。
// 该程序应打印3个值，并分别描述以示区分。

#include <stdio.h>

int getDouble(int);
int getSquare(int);

int main(void) {
  int toes = 10;
  printf("double toes: %d\n", getDouble(toes));
  printf("square toes: %d\n", getSquare(toes));
  return 0;
}

int getDouble(int num)
{
  return 2 * num;
}

int getSquare(int num)
{
  return num * num;
}
