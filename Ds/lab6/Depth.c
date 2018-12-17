/**
 *对一棵以孩子-兄弟链表表示的树，求树的高度
 */
#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct CSNode
{
	Elemtype data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

void CreatTree(CSTree &T){
	//构造一棵特定的树，仅做演示
	CSTree a, b, c, d, e, f, g;
	a = (CSTree)malloc(sizeof(CSNode));
	b = (CSTree)malloc(sizeof(CSNode));
	c = (CSTree)malloc(sizeof(CSNode));
	d = (CSTree)malloc(sizeof(CSNode));
	e = (CSTree)malloc(sizeof(CSNode));
	f = (CSTree)malloc(sizeof(CSNode));
	g = (CSTree)malloc(sizeof(CSNode));
	a->data = 'a'; b->data = 'b';
	c->data = 'c'; d->data = 'd';
	e->data = 'e'; f->data = 'f';
	g->data = 'g';
	a->firstchild = b; a->nextsibling = NULL;
	b->firstchild = d; b->nextsibling = c;
	c->firstchild = NULL; c->nextsibling = NULL;
	d->firstchild = NULL; d->nextsibling = e;
	e->firstchild = g; e->nextsibling = f;
	f->firstchild = NULL; f->nextsibling = NULL;
	g->firstchild = NULL; g->nextsibling = NULL;
	T = a;//a作为根
}

int Depth(CSTree T){
	CSTree p;
	int m, max = 0;
	if (!T)
	{
		return 0;
	}
	else if (!T->firstchild)
	{
		return 1;
	}
	else{
		//求树的最大深度
		p = T->firstchild;
		while(p){
			m = Depth(p);
			if (max < m)
			{
				max = m;
			}
			p = p->nextsibling;
		}
		return max + 1;
	}
}

int main(int argc, char const *argv[])
{
	CSTree T;
	CreatTree(T);
	printf("%d\n", Depth(T));
	return 0;
}