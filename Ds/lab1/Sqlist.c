/**
 *编程实现书P19  ADT List 基本操作12个：
 *（1）	用顺序存储结构实现； （2）用链式存储结构实现；
 *如下使用顺序结构实现：
 */
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;
typedef int Status;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{
	//构造一个空的线性表
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (! L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status Destroy_Sq(SqList &L)
{
	//当线性表L已存在，销毁线性表
	if (L.elem != NULL)
	{
		free(L.elem);
	}
	L.length = 0;
	L.listsize = 0;

	if (L.elem == NULL)
	{
		return OK;
	}
	else return ERROR;//销毁失败
}

Status ClearList(SqList &L)
{
	//当线性表L已存在，将L重置为空表
	if (L.elem != NULL)
	{
		L.length = 0;
		return OK;
	}
	else return ERROR;//线性表不存在
}

Status ListEmpty(SqList &L)
{
	//若L为空表，返回TRUE，否则返回FALSE
	if (L.elem != NULL)
	{
		if (L.length) return TRUE;
		else return FALSE;
	}
	else return ERROR;//线性表不存在
}

Status ListLength(SqList L)
{
	//返回L中数据元素的个数
	if (L.elem != NULL)
	{
		return L.length;
	}
	else return ERROR;//线性表不存在
}

Status GetElem(SqList L, int i, ElemType &e)
{
	//用e返回L中第i个数据元素的值
	if (L.elem != NULL && i <= ListLength(L))
	{
		e = L.elem[i-1];
		return e;
	}
	else return ERROR;//线性表不存在或者i大于了ListLength
}

/*Status LocateElem(SqList L, e, compare())
{
	//返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据不存在，则返回值为0
	if (L.elem != NULL)
	{
		for (int i = 0; i < ListLength(L); ++i)
		{
			int flag;
			flag = compare(L.elem[i], e);
			if (flag) return i+1;
		}
		if (!flag) return 0;
	}
	else return ERROR;//线性表不存在
}*/

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	if (L.elem != NULL)
	{
		for (int i = 0; i < ListLength(L); ++i)
		{
			if (i != 0 && cur_e == L.elem[i])
			{
				pre_e = L.elem[i-1];
				return pre_e;
			}
			else if (i == 1) return 0;//无意义
		}
	}
	else return ERROR;//线性表不存在
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
	if (L.elem != NULL)
	{
		for (int i = 0; i < ListLength(L); ++i)
		{
			if (i != 0 && cur_e == L.elem[i])
			{
				next_e = L.elem[i+1];
				return next_e;
			}
			else if (i == 1) return 0;//无意义
		}
	}
	else return ERROR;//线性表不存在
}

Status ListInsert(SqList &L, int i, ElemType e)
{
	//在顺序线性表L中第i个位置之前插入新的元素e
	if (i < 1 || i > L.length + 1) return ERROR; //i值不合法
	if (L.length >= L.listsize)//储存空间已满，增加分配
	{
		ElemType *newbase;
		newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int *p, *q;
	q = &(L.elem[i-1]);
	for (p = &(L.elem[L.length-1]); p >= q; --p) *(p+1) = *p;
	*q = e;
	++L.length;
	return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e)
{
	//在顺序线性表L中删除第i个元素，并用e值返回
	if ((i < 1) || (i > L.length)) return ERROR;
	int *p,*q;
	p = &(L.elem[i-1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p<=q; ++p) *(p-1) = *p;
	--L.length;
	return OK;
}

Status ListDelete(SqList L, vist())
{
	for (int i = 0; i < L.length; ++i)
	{
		if(!vist(L.elem[i])) return ERROR;
	}
	return OK;
}

int main(int argc, char const *argv[])
{
	SqList myList;
	int num, /*d*/;
	//myList.elem[3] = 12;
	InitList_Sq(myList);
	ListEmpty(myList);
	num = ListLength(myList);
	//d = GetElem(myList, 4, d);
	printf("%d\n%d\n", num, d);
	ClearList(myList);
	Destroy_Sq(myList);
	return 0;
}