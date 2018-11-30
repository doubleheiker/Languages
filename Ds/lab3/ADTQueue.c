/*编程实现书P59   ADTQueue 基本操作9个，用链式存储结构实现；*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int QElemType;
typedef int Status;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;//队头指针
	QueuePtr rear; //队尾指针
}LinkQueue;

//visit函数
void visit(QElemType e){
	printf("%d\n", e);
}

//构造一个空队列
Status InitQueue (LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//销毁队列
Status DestoryQueue(LinkQueue &Q){
	while(Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

//清空队列
Status ClearQueue(LinkQueue &Q){
	while(Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//判断队列是否为空
Status QueueEmpty(LinkQueue Q){
	if (Q.front->next == NULL)
	{
		return OK;
	}
	else return ERROR;
}

//返回队列长度
int QueueLength(LinkQueue Q){
	QueuePtr p;
	int len = 0;
	for (p = Q.front->next; p != Q.rear; p = p->next)
	{
		len++;
	}
	return len;
}

//用e返回队头元素
Status GetHead(LinkQueue Q, QElemType &e){
	QueuePtr p;
	if (Q.front->next)
	{
		p = Q.front->next;
		e = p->data;
		return OK;
	}
	else return ERROR;
}

//插入元素e
Status EnQueue(LinkQueue &Q, QElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	return OK;
}

//出列
Status DeQueue(LinkQueue &Q, QElemType &e){
	QueuePtr p;
	if (Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}

//遍历队列
Status QueueTraverse(LinkQueue Q){
	QueuePtr p;
	p = Q.front->next;
	while(p)
	{
		visit(p->data);
		p = p->next;
	}
	return OK;
}

int main(int argc, char const *argv[])
{
	LinkQueue qu;
	InitQueue(qu);
	DestoryQueue(qu);
	return 0;
}