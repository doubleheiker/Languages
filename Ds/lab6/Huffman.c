/*输入N个权值（1-100正整数），建立哈夫曼树。*/
#include <stdio.h>
#include <stdlib.h>
typedef struct BiTreeNode
{
    int data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;

BiTree CreateHuffman(int a[], int n){
	int i, j;
	BiTree *bt, q;
	bt = (BiTree *)malloc(n*sizeof(BiTreeNode));
	for (i = 0; i < n; ++i)//初始化bt指针数组，每个指针元素指向a中元素
	{
		bt[i]->data = a[i];
		bt[i]->lchild = bt[i]->rchild = NULL;
	}
	for (i = 0; i < n; ++i)//建立哈夫曼树
	{
		//k1表示最小权值的结点，k2表示次小的结点
		int k1 = -1, k2;
		for (j = 0; j < n; ++j)//k1指向第一棵树，k2指向第二棵
		{
			if (bt[j] && k1 == -1)
			{
				k1 = j;
				continue;
			}
			if (bt[j])
			{
				k2 = j;
				break;
			}
		}
		for (j = k2; j < n; ++j)//从当前森林中求出最小两点
		{
			if (bt[j])
			{
				if (bt[j]->data < bt[k1]->data)
				{
					k2 = k1;
					k1 = j;
				}
				else if (bt[j]->data < bt[k2]->data)
				{
					k2 = j;
				}
			}
		}
		q = (BiTree)malloc(sizeof(BiTreeNode));//建立新树
		q->data = bt[k1]->data + bt[k2]->data;
		q->lchild = bt[k1];
		q->rchild = bt[k2];

		bt[k1] = q;
		bt[k2] = NULL;
	}
	free(bt);
	return q;
}

int main(int argc, char const *argv[])
{
	int n;
	int *a;
	BiTree fbt;
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d ", &a[i]);
	}
	fbt = CreateHuffman(a, n);
	return 0;
}