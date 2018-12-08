/**
 *编程实现书P121  ADT BinaryTree 基本操作20个，用二叉链表结构实现；
 */
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef struct stack_node //栈的结构体
{
    BiTree bt;
    struct stack_node *next;
} stack_list, *stack_link;
 
Status visit(TElemType e){
	printf("%d\n", e);
	return OK;
}

//检查[栈]是否是空
int isStackEmpty(stack_link stack)
{
    if(stack == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
//入栈
stack_link push(stack_link stack,BiTree bt)
{
    stack_link new_node;
 
    new_node=(stack_link)malloc(sizeof(stack_list));
    if(!new_node)
    {
        return NULL;
    }
    new_node->bt=bt;
    new_node->next=stack;
    stack=new_node;
    return stack;
}
 
//出栈
stack_link pop(stack_link stack,BiTree bt)
{
    stack_link top;
 
    if(isStackEmpty(stack))
    {
        bt = NULL;
        return NULL;
    }
    top=stack;
    bt=top->bt;
    stack=top->next;
    free(top);
    return stack;
}

Status InitBiTree(BiTree &T){
	T = NULL;
	return OK;
}

Status DestroyBiTree(BiTree &T){
	if (T)
    {
        DestroyBiTree(T -> lchild);
        DestroyBiTree(T -> rchild);
        free(T);
        T == NULL;
    }
    return OK;
}

Status CreateBiTree(BiTree &T){
	char ch;
    ch = getchar();
    if (ch == ' ')
        T = NULL;
    else
    {
        if(! (T = (BiTree)malloc(sizeof(BiTNode)))) return ERROR;
        T -> data = ch;         //生成根节点
        T -> lchild = NULL;   //构造左子树
        T -> rchild = NULL;   //构造右子树
        CreateBiTree(T -> lchild);
        CreateBiTree(T -> rchild);
    }
    return OK;
}

Status ClearBiTree(BiTree &T){
	DestroyBiTree(T);
	T = (BiTree)malloc(sizeof(BiTree));
	T = NULL;
	return OK;
}

Status BiTreeEmpty(BiTree T){
	if (!T)
	{
		return OK;
	}
	else return ERROR;
}

int BiTreeDepth(BiTree T){
	int h, rh, lh;
	if (!T)
	{
		h = 0;
	}
	else{
		lh = BiTreeDepth(T->lchild);
		rh = BiTreeDepth(T->rchild);
		if (lh > rh)
		{
			h = lh + 1;
		}
		else h = rh + 1;
	}
	return h;
}

BiTree Root(BiTree T){
	return T;
}

TElemType Value(BiTree T, BiTree e){
	TElemType ret;
	if (!T)
	{
		printf("NULL!");
		return T->data;
	}
	if (T == e)
	{
		return T->data;
	}
	else{
		ret = Value(T->lchild, e);
		if (ret != ' ')
		{
			if (ret == e->data)
			{
				return ret;
			}
		}
		ret = Value(T->rchild, e);
	}
	return ret;
}

Status Assign(BiTree T, BiTree &e, TElemType value){
	if (!T)
	{
		printf("NULL!");
		return ERROR;
	}
	if (T == e)
	{
		T->data = value;
		return OK;
	}
	else{
		int ret;
		ret = Assign(T->lchild, e, value);
		if (ret == OK)
		{
				return ret;
		}
		ret = Assign(T->rchild, e,value);
	}
	return ERROR;
}

BiTree Parent(BiTree T, BiTree e){
	if (!T)
	{
		printf("NULL!");
		return ERROR;
	}
	if (T->lchild == e || T->rchild == e)
	{
		return T;
	}
	else{
		BiTree ret;
		ret = Parent(T->lchild, e);
		if (ret)
		{
				return ret;
		}
		ret = Parent(T->rchild, e);
	}
	return ERROR;
}

BiTree LeftChild(BiTree T, BiTree e){
	if (!T)
	{
		printf("NULL!");
		return ERROR;
	}
	if (T == e)
	{
		return T->lchild;
	}
	else{
		BiTree ret;
		ret = LeftChild(T->lchild, e);
		if (ret)
		{
				return ret;
		}
		ret = LeftChild(T->rchild, e);
	}
	return ERROR;
}

BiTree RightChild(BiTree T, BiTree e){
	if (!T)
	{
		printf("NULL!");
		return ERROR;
	}
	if (T == e)
	{
		return T->rchild;
	}
	else{
		BiTree ret;
		ret = RightChild(T->lchild, e);
		if (ret)
		{
				return ret;
		}
		ret = RightChild(T->rchild, e);
	}
	return ERROR;
}

BiTree LeftSibling(BiTree T, BiTree e){
	BiTree ret = NULL;
	if (T == NULL)
	{
		return ret;
	}
	if (T->rchild == e)
	{
		return T->lchild;
	}
	ret = LeftSibling(T->rchild, e);
	if (ret)
	{
		return ret;
	}
	return LeftSibling(T->lchild, e);
}

BiTree RightSibling(BiTree T, BiTree e){
	BiTree ret = NULL;
	if (T == NULL)
	{
		return ret;
	}
	if (T->lchild == e)
	{
		return T->rchild;
	}
	ret = RightSibling(T->lchild, e);
	if (ret)
	{
		return ret;
	}
	return RightSibling(T->rchild, e);
}

BiTree InsertChild(BiTree T, TElemType Value){
	//这里插入操作用查找二叉树实现
	BiTree newnode;
	BiTree current;
	BiTree back;
	newnode = (BiTree)malloc(sizeof(BiTNode));
	if (!newnode)
	{
		exit(1);
	}
	newnode->data = Value;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	if (!T)
	{
		return newnode;
	}
	else{
		current = T;
		while(current != NULL){
			back = current;
			if (current->data > Value)
			{
				current = current->lchild;
			}
			else current = current->rchild;
		}
		if (back->data > Value)
		{
			back->lchild = newnode;
		}
		else back->rchild = newnode;
	}
	return T;
}

Status DeleteChild(BiTree &T, BiTree e){
	if (!T)
	{
		printf("NULL!");
		return ERROR;
	}
	if (T == e)
	{
		//没有释放空间
		T->lchild = NULL;
		T->rchild = NULL;
		return OK;
	}
	else{
		int ret;
		ret = DeleteChild(T->lchild, e);
		if (ret)
		{
				return ret;
		}
		ret = DeleteChild(T->rchild, e);
	}
	return ERROR;
}

Status PreOrderTraverse(BiTree T){
	if (T)
	{
		printf("%d\n", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		return OK;
	}
	else return ERROR;
}

Status InOrderTraverse(BiTree T){
	if (T)
	{
		InOrderTraverse(T->lchild);
		printf("%d\n", T->data);
		InOrderTraverse(T->rchild);
		return OK;
	}
	else return ERROR;
}

Status PostOrderTraverse(BiTree T){
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%d\n", T->data);
		return OK;
	}
	else return ERROR;
}

int main(int argc, char const *argv[])
{
	BiTree T = NULL;
	CreateBiTree(T);
	return 0;
}