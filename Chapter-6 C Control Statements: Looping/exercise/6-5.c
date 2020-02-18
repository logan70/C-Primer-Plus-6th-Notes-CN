// 5. 编写一个程序，提示用户输入大写字母。
// 使用嵌套循环以下面金字塔型的格式打印字母：
// A
// ABA
// ABCBA
// ABCDCBA
// ABCDEDCBA
// 打印这样的图形，要根据用户输入的字母来决定。
// 例如，上面的图形是在用户输入E后的打印结果。
// 提示：用外层循环处理行，每行使用3个内层循环，
// 分别处理空格、以升序打印字母、以降序打印字母。
#include <stdio.h>
#define start 'A'

int main(void)
{
  int rows, i, j;
  char ch, base = 'A';
  do
  {
    printf("Please enter an uppercase character: \n");
    scanf("%c", &ch);
  } while (ch < 'A' || ch > 'Z');
  rows = (int)ch - base + 1;
  for (i = 1; i <= rows; i++) {
    for (j = 0; j < i; j++)
    printf("%c", base +j);
    for (j -= 2; j >= 0; j--)
    printf("%c", base +j);
    printf("\n");
  }
  return 0;
}