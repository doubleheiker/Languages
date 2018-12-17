/**
 *实现二叉树的先序、中序、后序遍历，用递归和非递归方法；实现层次遍历。
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

typedef struct BStack{
	BiTree stack[MAXSIZE];
	int top;
}BStack, *Stack;

//栈的初始化
Stack Initstack(){
	Stack s;
	s = (Stack)malloc(sizeof(BStack));
	if (s)
	{
		s->top = -1;
	}
	else printf("Init stack error\n");
	return s;
}

//检查是否栈空
int StackEmpty(Stack s){
	if (s->top == -1)
	{
		return 1;
	}
	else return 0;
}

//检查是否栈满
int StackFull(Stack s){
	if (s->top == MAXSIZE - 1)
	{
		return 1;
	}
	else return 0;
}

void Push(Stack &s, BiTree e){
	if (!(StackEmpty(s)))
	{
		s->top++;
		s->stack[s->top] = e;
	}
}

BiTree Pop(Stack &s){
	BiTree e;
	if (!(StackEmpty(s)))
	{
		e = s->stack[s->top];
		s->top--;
		return e;
	}
	else return NULL;
}

//返回栈顶元素
BiTree GetTop(Stack s){
	if (StackEmpty(s))
	{
		return NULL;
	}
	else return s->stack[s->top];
}

void Free(Stack &s){
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

//先序非递归遍历
void PreTraverse(BiTree T){
	BiTree p;
	Stack s;
	s = Initstack();
	if (T)
	{
		Push(s, T);
		while(!StackEmpty(s)){
			p = Pop(s);
			while(p){
				printf("%c\t", p->data);
				if (p->rchild)
				{
					Push(s, p->rchild);
				}
				p = p->lchild;
			}
		}
	}
}

//中序非递归遍历
void InTraverse(BiTree T){
	BiTree p;
	Stack s;
	s = Initstack();
	Push(s,T);//根节点进栈
	while(!StackEmpty(s)){
		while((p = GetTop(s)) && p){//栈顶元素存在，赋值给p
			Push(s, p->lchild);//p左子树进栈
		}
		p = Pop(s);//去掉最后的空指针
		if (!StackEmpty(s))
		{
			p = Pop(s);//弹出栈顶元素
			printf("%c\t", p->data);
			Push(s,p->rchild); //右子树进栈，然后遍历右子树
		}
	}
}

int main(){
	BiTree T;
	CreateBiTree(T);
	printf("\n");
	PreTraverse(T);
	printf("\n");
	InTraverse(T);
	printf("\n");
	return 0;
}