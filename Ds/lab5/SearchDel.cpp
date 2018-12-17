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

//删除以T为根的所有结点
Status DestroyBiTree(BiTree &T){
	if (T)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
	return OK;
}

//查找树要删除的结点并删除
void SearchDel(BiTree &T, char e){
	if (T)
	{	
		if (T->data == e)
		{
			DestroyBiTree(T);
		}
		else{
			SearchDel(T->lchild, e);
			SearchDel(T->rchild, e);
		}
	}
	else return ;
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

int main(int argc, char const *argv[])
{
	char e;
	BiTree T;
	T = (BiTree)malloc(sizeof(BiTreeNode));
		
	CreateBiTree(T);
	scanf("%c", &e);
	SearchDel(T,e);
	PreOrderTraverse(T);
	return 0;
}
