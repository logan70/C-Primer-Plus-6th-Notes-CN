// names1.c - 使用指向结构的指针
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 81
struct namect {
  char * fname;
  char * lname;
  int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); // 调用该函数时释放内存
char * s_gets(char * st, int n);

int main(void)
{
  struct namect person;
  getinfo(&person);
  makeinfo(&person);
  showinfo(&person);
  cleanup(&person);
  return 0;
}
void getinfo(struct namect * pst)
{
  char temp[SLEN];
  printf("Please enter your first name.\n");
  s_gets(temp, SLEN);
  // 分配内存以储存名
  pst->fname = (char *)malloc(strlen(temp) + 1);
  // 把名拷贝到动态分配的内存中
  strcpy(pst->fname, temp);
  printf("Please enter your last name.\n");
  s_gets(temp, SLEN);
  pst->lname = (char *)malloc(strlen(temp) + 1);
  strcpy(pst->lname, temp);
}

void makeinfo(struct namect * pst)
{
  pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
  printf("%s %s, your name contains %d letters.\n",
  pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect * pst)
{
  free(pst->fname);
  free(pst->lname);
}


char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    find = strchr(st, '\n');
    if (find)
      *find = '\0';
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}