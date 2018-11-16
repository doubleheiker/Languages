/**
 *编程实现书P19  ADT List 基本操作12个：
 *（1）	用顺序存储结构实现； （2）用链式存储结构实现；
 *如下使用链式结构实现：
 */
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
typedef struct LNode
{
	ElemType data;
	struct LNode *prior;
	struct LNode *next;
}LNode, *LinkList;

Status vist(ElemType c)
{
	printf("%d", c);
	return OK;
}

Status InitList(LinkList &L)
{
	//构造一个空链式线性表
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) return ERROR;
	L->next = NULL;
	return OK;
}

Status DestroyList(LinkList &L)
{
	//销毁线性表
	if (L)
	{
		LinkList p;
		while (L->next)
		{
			p = L->next;
			L->next = p->next;
			free(p);
		}
		free(L);
		return OK;
	}
	else return ERROR;
}

Status ClearList(LinkList &L)
{
	//顺序线性表L已存在。将L重置为空表
	LinkList p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p=q;
	}
	if (L->next = NULL) return OK;
	else return ERROR;
}

Status ListEmpty(LinkList L)
{
	//顺序线性表L已存在。若L为空表，则返回TRUE，否则返回FALSE
	if (L->next) return FALSE;
	else return TRUE;
}

int ListLength(LinkList L)
{
	//返回L中的元素个数
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
	//当第i个元素存在时，其赋值给e并返回OK，否则返回ERROR
	int n = 1;
	LinkList p;
	p = L->next;
	while(p && n < i)
	{
		p = p->next;
		++n;
	}
	if (!p || n > i) return ERROR;
	e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e)
{
	//返回L中第1个与e满足关系的数据元素的位序,若这样的数据元素不存在则返回值为0 
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		if (p->data == e) return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, LinkList &pre_e)
{
	//若存在，返回前驱pre_e,否则返回ERROR
	LinkList p = L;
	while (p && p->prior)
	{
		if (p->data == cur_e)
		{
			pre_e = p->prior;
			return OK;
		}
		else p = p->next;
	}
	return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, LinkList &next_e)
{
	//若存在，返回后驱next_e,否则返回ERROR
	LinkList p = L;
	while(p && p->next)
	{
		if (p->data == cur_e)
		{
			next_e = p->next;
			return OK;
		}
		else p = p->next;
	}
	return ERROR;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
	//在带头结点的单链线性表L中第i个位置前插入元素e
	LinkList p = L, s;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		i++;
	}
	if (!p || j < i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{
	//在带头结点的单链线性表L中,删除第i个元素，并由e返回其值
	int j = 0;
	LinkList p = L, q;
	while (p->next && j < i-1)
	{
		p = p->next;
		++j;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

Status ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		vist(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main(int argc, char const *argv[])
{
	LinkList mylist;
	InitList(mylist);
	ClearList(mylist);
	return 0;
}