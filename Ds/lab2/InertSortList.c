/**
 *设元素值为整型的线性表L，分别采用顺序结构和链式结构存储，编写程序，用插入排序算法实现线性表的表排序。
 *如下是链式结构的程序
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct lNode
{
	int data;
	struct lNode *next;
}linklist;
//建立一个带头节点的链表
linklist *create(linklist *L, int a[], int length)
{
	linklist *r, *s;
	int i;
	L = (linklist *)malloc(sizeof(linklist));
	r = L;
	for( i=0; i<length; i++ )
	{
		s = (linklist *)malloc(sizeof(linklist));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}
//有小到大排序，暂时分为两个链表比较
linklist *sort(linklist *L)
{
	linklist *p, *q, *pre;
	p = L->next->next;
	L->next->next = NULL;//从第二个结点截断
	while(p!=NULL)
	{
		pre = L;
		q = p->next;
		while(pre->next != NULL && pre->next->data < p->data) pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
	return L;
}

void display(linklist *L)
{
	linklist *p = L->next;
	while(p->next != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d\n", p->data);
}

int main(int argc, char const *argv[])
{
	int a[6] = {3,1,2,5,23,9};
	int length = 6;
	linklist *p,*L;
	p = create(L, a, length);
	display(p);
	sort(p);
	display(p);
	return 0;
}
