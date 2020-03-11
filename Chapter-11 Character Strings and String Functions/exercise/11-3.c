// 3. 设计并测试一个函数，从一行输入中把一个单词读入一个数组中，
// 并丢弃输入行中的其余字符。该函数应该跳过第1个非空白字符前面的所有空白。
// 将一个单词定义为没有空白、制表符或换行符的字符序列。
#include <stdio.h>
#include <ctype.h>
char * get_word(char * st);

int main(void)
{
  char word[40];
  char * check;
  printf("Please enter a word: ");
  check = get_word(word);
  if (check)
    printf("The word you input is: \"%s\"\n", word);
  else
    puts("No input.");
  return 0;
}

char * get_word(char * st)
{
  int count;
  char ch;
  char * cp = st;
  while (isspace(ch = getchar()))
    continue;
  if (ch == EOF)
    return NULL;
  else
    *st++ = ch;
  while ((ch = getchar()) != EOF && !isspace(ch))
    *st++ = ch;
  *st = '\0';
  if (ch == EOF)
    return st;
  else
    while (ch != '\n')
    ch = getchar();
    return cp; 
}