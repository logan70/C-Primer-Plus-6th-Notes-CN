// 12. 编写一个程序，读取输入，直至读到EOF，
// 报告读入的单词数、大写字母数、小写字母数、标点符号数和数字字符数。
// 使用ctype.h头文件中的函数。
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
  char ch;
  int words_ct = 0;
  int upper_ct = 0;
  int lower_ct = 0;
  int punct_ct = 0;
  int num_ct = 0;
  bool is_in_word = false;
  puts("Enter text to be analyzed(EOF to quit):");
  while ((ch = getchar()) != EOF)
  {
    if (!isspace(ch) && !is_in_word)
    {
      is_in_word = true;
      words_ct++;
    }
    if (isspace(ch) && is_in_word)
      is_in_word = false;
    if (isalpha(ch))
    {
      if (isupper(ch))
        upper_ct++;
      if (islower(ch))
        lower_ct++;
    }
    if (ispunct(ch))
      punct_ct++;
    if (isnumber(ch))
      num_ct++;
  }
  puts("");
  printf("You entered %d words, %d uppers, %d lowers, %d puncts, %d numbers\n",
  words_ct, upper_ct, lower_ct, punct_ct, num_ct);
  return 0;
}