// 7. 编写一个函数，从标准输入中读取字符，直到遇到文件结尾。
// 程序要报告每个字符是否是字母。如果是，还要报告该字母在字母表
// 中的数值位置。例如，c和C在字母表中的位置都是3。
// 合并一个函数，以一个字符作为参数，如果该字符是一个字母则
// 返回一个数值位置，否则返回-1。
#include <stdio.h>
#include <ctype.h>

int get_char_pos(char ch);

int main(void)
{
  int ch;
  int pos;
  while ((ch = getchar()) != EOF)
  pos = get_char_pos(ch);
  printf("Done!\n");
  return 0;
}

int get_char_pos(char ch)
{
  int pos = -1;
  if (isspace(ch))
  return pos;
  if (isalpha(ch))
  {
    pos = tolower(ch) - 'a' + 1;
    printf("the position of %c is %d.\n", ch, pos);
  }
  else
  {
    printf("%c is not a alphabet.\n", ch);
  }
  return pos;
}