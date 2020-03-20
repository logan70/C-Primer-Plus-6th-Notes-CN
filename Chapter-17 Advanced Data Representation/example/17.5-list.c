// list.c - 支持链表操作的函数
#include <stdio.h>
#include <stdlib.h>
#include "17.3-list.h"
// 局部函数原型
static void CopyToNode(Item item, Node * pnode);

// 接口函数-把链表设置为空
void InitializeList(List * plist)
{
  *plist = NULL;
}

// 接口函数-链表是否为空
bool ListIsEmpty(const List * plist)
{
  return *plist == NULL ? true : false;
}

// 接口函数-链表是否已满
bool ListIsFull(const List * plist)
{
  Node * pt;
  bool full;
  pt = (Node *)malloc(sizeof(Node));
  full = pt == NULL ? true : false;
  free(pt);
  return full;
}

// 接口函数-返回节点的数量
unsigned int ListItemCount(const List * plist)
{
  unsigned int count = 0;
  Node * pt = *plist;
  if (pt != NULL)
  {
    count++;
    pt = pt->next;
  }
  return count;
}

// 接口函数-创建储存项的节点，并将其添加至由plist指向的链表末尾（较慢的实现）
bool AddItem(Item item, List * plist)
{
  Node * pnew;
  Node * scan = *plist;
  pnew = (Node *)malloc(sizeof(Node));
  if (pnew == NULL)
    return false;
  CopyToNode(item, pnew);
  pnew->next = NULL;
  if (scan == NULL) // 空链表，把pnew放在开头
    *plist = pnew;
  else
  {
    while (scan->next != NULL)
      scan = scan->next;
    scan->next = pnew;
  }
  return true;  
}

// 接口函数-访问每个节点并执行pfun指向的函数
void Traverse(const List * plist, void(*pfun)(Item item))
{
  Node * pnode = *plist;
  while (pnode != NULL)
  {
    (*pfun)(pnode->item);
    pnode = pnode->next;
  }
}

// 接口函数-释放由malloc()分配的内存
void EmptyTheList(List * plist)
{
  Node * psave;
  while (*plist != NULL)
  {
    psave = (*plist)->next; // 保存下一个节点地址
    free(*plist); // 释放当前节点
    *plist = psave; // 前进至下一个节点
  }
}

// 局部函数-把一个项拷贝到节点中
static void CopyToNode(Item item, Node * pnode)
{
  pnode->item = item; // 拷贝结构
}