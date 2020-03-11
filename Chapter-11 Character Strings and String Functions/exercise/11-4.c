// 4.设计并测试一个函数，它类似编程练习3的描述，
// 只不过它接受第2个参数指明可读取的最大字符数。
#include <stdio.h>
#include <ctype.h>
char * get_word(char * st, int n);

int main(void)
{
  char word[10];
  char * check;
  printf("Please enter a word: ");
  check = get_word(word, 9);
  if (check)
    printf("The word you input is: \"%s\"\n", word);
  else
    puts("No input.");
  return 0;
}

char * get_word(char * st, int n)
{
  int count = 0;
  char ch;
  char * cp = st;
  while (isspace(ch = getchar()))
    continue;
  if (ch == EOF)
    return NULL;
  else
  {
    *st++ = ch;
    count++;
  }
  while (count < n && (ch = getchar()) != EOF && !isspace(ch))
  {
    *st++ = ch;
    count++;
  }
  *st = '\0';
  if (ch == EOF)
    return st;
  else
    while (ch != '\n')
    ch = getchar();
    return cp; 
}