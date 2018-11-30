/*编程实现书P45   ADT Stack 基本操作9个，用顺序存储结构实现*/
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int SElemTpye;
typedef int Status;

typedef struct {
	SElemTpye *base; //在栈构造之前和销毁之后，base的值为NULL
	SElemTpye *top;  //栈顶指针
	int stacksize;   //当前已分配的存储空间，以元素为单位
}SqStack;

//visit函数
void visit(SElemTpye e){
	printf("%d\n", e);
}

//构造一个空栈
Status InitStack(SqStack &S){
	S.base = (SElemTpye *)malloc(STACK_INIT_SIZE * sizeof(SElemTpye));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//销毁栈
Status DestroyStack(SqStack &S){
	S.top =NULL;
	free(S.base);
	if (!S.base)
	{
		S.stacksize = 0;
		return OK;
	}
	else return ERROR;
}

//清空栈
void ClearStack(SqStack &S){
	S.top = S.base;
}

//判断是否为空栈
Status StackEmpty(SqStack S){
	if (S.base && S.top == S.base)
	{
		return TRUE;
	}
	else return FALSE;
}

//返回栈的长度
Status StackLength(SqStack S){
	SElemTpye *p;
	int count = 0;
	if (S.base)
	{
		for (p = S.base; p != S.top; p++)
		{
			count++;
		}
		return count;
	}
	else return ERROR;
}

//返回栈顶元素值
Status GetTop(SqStack S, SElemTpye &e){
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

//入栈
Status Push(SqStack &S, SElemTpye e){
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemTpye *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemTpye));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

//出栈
Status Pop(SqStack &S, SElemTpye &e){
	if (S.top == S.base) return ERROR;
	e = * --S.top;
	return OK;
}

//遍历栈
Status StackTraverse(SqStack S){
	SElemTpye *p;
	for (p = S.base; p != S.top; p++)
	{
		printf("%d\n", *p);
	}
	return OK;
}

int main(int argc, char const *argv[])
{
	SqStack sq;
	InitStack(sq);
	StackEmpty(sq);
	free(sq);
	return 0;
}