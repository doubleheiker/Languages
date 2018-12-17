/**
 *实现二叉树的后序遍历，用递归和非递归方法；实现层次遍历。
 *非递归实现方式如下
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
//二叉树的节点结构
typedef struct BiTreeNode{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;

typedef struct{
	BiTreeNode  *q;
	int tag;   //存放当前状态位
}SNode;

typedef struct{
	SNode stack[MAXSIZE];
	int top;
}BStacks, *Stacks;

//栈初始化
Stacks InitStacks(){
	Stacks s;
	s = (BStacks*)malloc(sizeof(BStacks));
	if (s)
	{
		s->top = -1;
	}
	else printf("Init stack error!\n");
	return s;
}

//判断栈是否为空
int StacksEmpty(Stacks s){
	if (s->top == -1)
	{
		return 1;
	}
	else return 0;
}

//判断栈是否已满
int StacksFull(Stacks s){
	if (s->top == MAXSIZE-1)
	{
		return 1;
	}
	else return 0;
}

void Pushs(Stacks &s, SNode *e){
	if (!(StacksFull(s)))
	{
		s->top++;
		s->stack[s->top] = *e;
	}
	else return ;
}

SNode* Pops(Stacks &s){
	SNode *e;
	if (!(StacksEmpty(s)))
	{
		e = &(s->stack[s->top]);
		s->top--;
		return e;
	}
	else return NULL;
}
	
SNode* GetsTop(Stacks s){
	if (StacksEmpty(s))
	{
		return NULL;
	}
	else return &(s->stack[s->top]);
}

void Free(Stacks &s){
	free(s);
}

//二叉树的创建
void CreateBiTree(BiTree &T){
	char val;
	val = getchar();
	if (val == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T->data = val;         //生成根节点
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//非递归后序遍历
void PostTraverse(BiTree T){
	int tag;
	BiTree p;
	Stacks s;
	SNode sdata;

	s = InitStacks();
	p = T;
	while(p || !StacksEmpty(s)){
		while(p){
			sdata.q = p;
			sdata.tag = 0;
			Pushs(s, &sdata);
			p = p->lchild;        //遍历左子树
		}
		sdata = *Pops(s); //退栈
		p = sdata.q;
		tag = sdata.tag;
		if (tag == 0)
		{
			sdata.q = p;
			sdata.tag = 1;//即将进入右子树，将根的tag=1
			Pushs(s, &sdata);
			p = p->rchild;
		}
		else{//tag ==1,说明右子树访问完
			printf("%c ", p->data);
			p = NULL;
		}
	}
}

int main(){
	BiTree T;
	CreateBiTree(T);
	printf("\n");
	PostTraverse(T);
	return 0;
}