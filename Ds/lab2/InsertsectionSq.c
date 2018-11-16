/*
 *设元素值为整型的线性表A,、B，分别采用顺序结构和链式结构存储，编写程序，实现下列功能：
 *假设以递增有序排列的线性表A和B 分别表示两个集合，现要求在A的空间上构成一个新线性表C，其元素为A和B元素的交集，
 *且表C中的元素也是依值递增有序排列。
 *以下为顺序表
 */
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SZIE 100

typedef struct{
    int *elem;
    int length;
}SqList;

//初始化顺序表
int InitList(SqList &l){
	l.elem=(int *)malloc(LIST_INIT_SZIE *sizeof(int));
	if(!l.elem) return -1;
	l.length = 0;
	return 0;
}

//求两个线性表的交集
void insertsection(SqList a, SqList b, SqList &c){
	int k = 0;
	for (int i = 0; i < a.length; ++i)
	{
		int j = 0;
		while (j < b.length && b.elem[j] != a.elem[i])
		{
			j++;
		}
		if (j < b.length)
		{
			c.elem[k++] = a.elem[i];
		}
	}
	c.length = k;
}

int main(int argc, char const *argv[])
{
	SqList A, B ,C;
	InitList(A);
	InitList(B);
	InitList(C);
	printf("please input the length of A & B\n");
	scanf("%d%d", &A.length, &B.length);
	printf("input A increasingly\n");
	for (int i = 0; i < A.length; ++i)
	{
		scanf("%d", &A.elem[i]);
	}
	printf("input B increasingly\n");
	for (int i = 0; i < B.length; ++i)
	{
		scanf("%d", &B.elem[i]);
	}
	insertsection(A, B, C);
	printf("A & B insertsection: \n");
	for (int i = 0; i < C.length; ++i)
	{
		printf("%d\n", C.elem[i]);
	}
	free(A);
	free(B);
	free(C);
	return 0;
}