// 4-4 4.编写一个程序，提示用户输入身高（单位：英寸）和姓名，
// 然后以下 面的格式显示用户刚输入的信息：
// Dabney, you are 6.208 feet tall
// 使用float类型，并用/作为除号。
// 如果你愿意，可以要求用户以厘米为 单位输入身高，并以米为单位显示出来。
#include <stdio.h>

int main(void)
{
  char name[40];
  float height;
  printf("Please enter your name:\n");
  scanf("%s", name);
  printf("Please enter your height(cm):\n");
  scanf("%f", &height);
  printf("%s, your are %.3f meter tall\n", name, height / 100);
  return 0;
}