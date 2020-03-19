// names.h - 修订后的names_st头文件，避免重复包含
#ifndef NAMES_H_

#define NAMES_H_
// 明示常量
#define SLEN 32
// 结构声明
struct names_st
{
  char first[SLEN];
  char last[SLEN];
};
// 类型定义
typedef struct names_st names;
// 函数原型
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);

#endif