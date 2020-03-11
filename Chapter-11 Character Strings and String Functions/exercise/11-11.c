// 11. 编写一个函数，读入10个字符串或者读到EOF时停止。
// 该程序为用户提供一个有5个选项的菜单：打印源字符串列表、以ASCII中的顺序
// 打印字符串、按长度递增顺序打印字符串、按字符串中第1个单词的长度打印字符串、
// 退出。菜单可以循环显示，除非用户选择退出选项。当然，该程序要能真正完成菜单
// 中各选项的功能。
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10
#define LIM 80

char * s_gets(char * st, int n);
void get_strs(char (* strs)[], int n);
void print_strs(char * strs[], int n);
void print_strs_originally(char (* strs)[LIM], int n);
void print_strs_by_ascii(char (* strs)[LIM], int n);
void print_strs_by_len(char (* strs)[LIM], int n);
void print_strs_by_first_word(char (* strs)[LIM], int n);
int get_first_word_len(char * st);
char get_choice(void);

int main(void)
{
  char choice;
  char strs[SIZE][LIM];
  get_strs(strs, SIZE);
  while ((choice = get_choice()) != 'e') {
    switch (choice)
    {
    case 'a':
      print_strs_originally(strs, SIZE);
      break;
    case 'b':
      print_strs_by_ascii(strs, SIZE);
      break;
    case 'c':
      print_strs_by_len(strs, SIZE);
      break;
    case 'd':
      print_strs_by_first_word(strs, SIZE);
      break;
    default:
      printf("Not valid!\n");
      break;
    }
  }
  puts("Bye");
  return 0;
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  int i = 0;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    while (st[i] != '\n' && st[i] != '\0')
      i++;
    if (st[i] == '\n')
      st[i] = '\0';
    else
      while (getchar() != '\n')
      continue;
  }
  return ret_val;
}

void get_strs(char (* strs)[LIM], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Enter a string(%d of %d): ", i + 1, n);
    while (!s_gets(strs[i], LIM) || strs[i][0] == '\0')
    printf("Enter a string(%d of %d): ", i + 1, n);
  }
}

void print_strs(char * strs[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  puts(strs[i]);
}

void print_strs_originally(char (* strs)[LIM], int n)
{
  char * pts[n];
  int i;
  for (i = 0; i < n; i++)
  {
    pts[i] = strs[i];
  }
  print_strs(pts, n);
}

void print_strs_by_ascii(char (* strs)[LIM], int n)
{
  char * pts[n];
  char * temp;
  int i, j;
  for (i = 0; i < n; i++)
  {
    pts[i] = strs[i];
  }
  for (i = 0; i < n - 1; i++)
  for (j = i; j < n; j++)
  {
    if (strcmp(pts[i], pts[j]) > 0)
    {
      temp = pts[i];
      pts[i] = pts[j];
      pts[j] = temp;
    }
  }
  print_strs(pts, n);
}

void print_strs_by_len(char (* strs)[LIM], int n)
{
  char * pts[n];
  char * temp;
  int i, j;
  for (i = 0; i < n; i++)
  {
    pts[i] = strs[i];
  }
  for (i = 0; i < n - 1; i++)
  for (j = i; j < n; j++)
  {
    if (strlen(pts[i]) > strlen(pts[j]))
    {
      temp = pts[i];
      pts[i] = pts[j];
      pts[j] = temp;
    }
  }
  print_strs(pts, n);
}

void print_strs_by_first_word(char (* strs)[LIM], int n)
{
  char * pts[n];
  char * temp;
  int i, j;
  for (i = 0; i < n; i++)
  {
    pts[i] = strs[i];
  }
  for (i = 0; i < n - 1; i++)
  for (j = i; j < n; j++)
  {
    if (get_first_word_len(pts[i]) > get_first_word_len(pts[j]))
    {
      temp = pts[i];
      pts[i] = pts[j];
      pts[j] = temp;
    }
  }
  print_strs(pts, n);
}

int get_first_word_len(char * st)
{
  int len = 0;
  while (*st++ != ' ')
  len++;
  return len;
}

char get_choice(void)
{
  char choice;
  puts("Please select an option: ");
  printf("  a)print original string\n");
  printf("  b)print string in ASCII order\n");
  printf("  c)print string in length\n");
  printf("  d)print string in the length of 1st words\n");
  printf("  e)exit program\n");
  ;
  while (isspace(choice = getchar()))
    continue;
  while (getchar() != '\n')
    continue;
  return tolower(choice);
}
