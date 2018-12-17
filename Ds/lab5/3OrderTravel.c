/**
 *实现二叉树的先序、中序、后序遍历，用递归和非递归方法；实现层次遍历。
 *递归实现方式如下
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

typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;

void CreateBiTree(BiTree &T)
{
	char val;
	val = getchar();
	if (val == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T -> data = val;         //生成根节点
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//先序递归遍历
Status PreOrderTraverse(BiTree T){
	if (T)
	{
		printf("%c ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		return OK;
	}
	else return ERROR;
}

//中序递归遍历
Status InOrderTraverse(BiTree T){
	if (T)
	{
		InOrderTraverse(T->lchild);
		printf("%c ", T->data);
		InOrderTraverse(T->rchild);
		return OK;
	}
	else return ERROR;
}

//后序递归遍历
Status PostOrderTraverse(BiTree T){
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c ", T->data);
		return OK;
	}
	else return ERROR;
}

int main()
{
 
    printf("test code\n");//输入ab#d##c  
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTreeNode));
 
    printf("please input number with PreOrder(empty number:' '):\n");
    CreateBiTree(T);
 
 
    printf("PreOrder:\n");
    PreOrderTraverse(T);
    printf("\n");
 
    printf("InOrder:\n");
    InOrderTraverse(T);
    printf("\n");
 
    printf("PostOrder:\n");
    PostOrderTraverse(T);
    printf("\n");
    return 0;
}