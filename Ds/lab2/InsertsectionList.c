/*
 *设元素值为整型的线性表A,、B，分别采用顺序结构和链式结构存储，编写程序，实现下列功能：
 *假设以递增有序排列的线性表A和B 分别表示两个集合，现要求在A的空间上构成一个新线性表C，其元素为A和B元素的交集，
 *且表C中的元素也是依值递增有序排列。
 *以下为链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

//初始化链表
/*int InitList(LinkList &l){
	l = (LinkList)malloc(sizeof(LNode));
	if (!l) return -1;
	l->next = NULL;
	return 0;
}*/

//新增加结点
void push(LinkList &head_ref, int new_data)  //添加数据成员函数
{ 
    LinkList new_node = (LinkList)malloc(sizeof(struct LNode));  
    new_node->data = new_data;  
    new_node->next = head_ref;  
    head_ref = new_node;  
}

//判断是否存在
int isPresent(LinkList head, int data)  
{  
    LinkList t = head;  
    while(t != NULL)  
    {  
        if( t->data == data )  
            return 1;  
        t = t->next;  
    }  
    return 0;  
} 

//求交集
LinkList insertsection(LinkList a, LinkList b)
{
	LinkList result = NULL, t1 = a;
	while( t1 != NULL )  
    {  
        if(isPresent(b, t1->data))  
            push(result, t1->data);  
        t1 = t1->next;  
    }
    return result;
}

//输出链表函数
void printList(LinkList node)  
{  
    while( node != NULL )  
    {  
        printf("%d ", node->data);  
        node = node->next;  
    }  
} 

int main(int argc, char const *argv[])
{
	LinkList a = NULL, b = NULL, c = NULL;
	push (a, 20);//链表一添加数据元素  
    push (a, 4);  
    push (a, 15);  
    push (a, 10);    
    push (b, 10); //链表二添加数据元素 
    push (b, 2);  
    push (b, 4);  
    push (b, 8);  
	c = insertsection(a, b);
	printf("\nthis is A\n");
	printList(a);
	printf("\nthis is B\n");
	printList(b);
	printf("\nA & B insertsection: \n");
	printList(c);
	free(a);
	free(b);
	free(c);
	return 0;
}
