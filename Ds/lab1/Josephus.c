/**
 *约瑟夫问题
 *输入正整数n、m（m<n），设有n个人坐成一圈，
 *从第1个人开始循环报数，报到m的人出列，然后再从下一个人开始报数，报到m的人又出列，如此重复，直到所有的人都出列为止。
 *要求用链式结构和顺序结构实现，按出列的先后顺序输出每个人的信息。
 *链表表示如下：
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{
	int value;
	struct LinkNode* next;
} LinkNode, *LinkNodePtr;

LinkNodePtr creatCycle(int total)//建立约瑟夫环
{
	int index = 1;
	LinkNodePtr head = NULL, curr = NULL, prev = NULL;
	head = (LinkNodePtr)malloc(sizeof(LinkNode));
	if (!head)
	{
		printf("Wrong\n");
		exit(0);
	}
	head->value = index;
	prev = head;

	while (--total > 0)
	{
		curr = (LinkNodePtr)malloc(sizeof(LinkNode));
		if (!curr)
		{
			printf("Wrong\n");
			exit(0);
		}
		curr->value = ++index;
		prev->next = curr;
		prev = curr;
	}
	curr->next = head;
	return head;
}

void run(int total, int tag)
{
	if (total == 1)
	{
		printf("\n1");
		exit(0);
	}
	LinkNodePtr node = creatCycle(total);
	LinkNodePtr prev = NULL;
	int start = 1;
	int index = start;
	while (node && node->next)
	{
		if (index == tag)
		{
			printf("\n%d", node->value);
			if (tag == start)
			{
				prev = node->next;
				node->next = NULL;
				node = prev;
			}
			else
			{
				prev->next = node->next;
				node->next = NULL;
				node = prev->next;
			}
			index = start;
		}
		else
		{
			prev = node;
			node = node->next;
			index++;
		}
	}
	free(node);
}

int main()
{
	run(5,2);
	return 0;
}