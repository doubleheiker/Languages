/**
 *设元素值为整型的线性表L，分别采用顺序结构和链式结构存储，
 *编写程序，实现线性表的就地逆置
 *如下是链式结构实现
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkListPtr;

LinkListPtr reverse(LinkListPtr head)
{
	LinkListPtr nowhead = NULL;
	LinkListPtr now;
	while (head!=NULL)
	{
		now = head;
		head = head->next;
		now->next = nowhead;
		nowhead = now;
	}
	return nowhead;
}

int main(int argc, char const *argv[])
{
	LinkListPtr head = NULL, curr = NULL, prev = NULL, newhead, p;
	int total, index = 1;
	head = (LinkListPtr)malloc(sizeof(LNode));
	if (!head)
	{
		printf("HEAD_WRONG!\n");
		exit(0);
	}
	head->data = index;
	prev = head;

	scanf("%d", &total);
	for (int i = 0; i < total; ++i)
	{
		curr = (LinkListPtr)malloc(sizeof(LNode));
		if (!curr)
		{
			printf("CURR_WRONG!\n");
			exit(0);
		}
		curr->data = ++index;
		prev->next = curr;
		prev = curr;
	}
	curr->next = NULL;

	newhead = reverse(head);
	p = newhead;
	while(p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}

	free(head);
	return 0;
}
