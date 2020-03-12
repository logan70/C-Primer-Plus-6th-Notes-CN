// diceroll.c - 掷骰子模拟程序
// 与12.13-mandydice.c 一起编译
#include "12.12-diceroll.h"
#include <stdio.h>
#include <stdlib.h> // 提供库函数rand()的原型
int roll_count = 0; // 外部链接
static int rollem(int sides) // 该函数属于该文件私有
{
  int roll;
  roll = rand() % sides + 1;
  ++roll_count; // 计算函数调用次数
  return roll;
}

int roll_n_dice(int dice, int sides)
{
  int d;
  int total = 0;
  if (sides < 2)
  {
    printf("Need at least 2 sides.\n");
    return -2;
  }
  if (dice < 1)
  {
    printf("Need at least 1 die.\n");
    return -1;
  }
  for (d = 0; d < dice; d++)
  total += rollem(sides);
  return total;
}