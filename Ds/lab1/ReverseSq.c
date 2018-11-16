/**
 *设元素值为整型的线性表L，分别采用顺序结构和链式结构存储，
 *编写程序，实现线性表的就地逆置
 *如下是顺序结构实现
 */
#include <stdio.h>
#include <stdlib.h>
#define LIST_SIZE 20
int* reverseSq(int *L)
{
	int *b1;
	b1 = (int*)malloc(LIST_SIZE*sizeof(int));
	for (int i = 0; i < LIST_SIZE; ++i)
	{
		b1[i] = L[LIST_SIZE-i-1];
	}
	return b1;
}

int main(int argc, char const *argv[])
{
	int a[LIST_SIZE], *b;
	for (int j = 0; j < LIST_SIZE; ++j)
	{
		a[j] = j+1;
		printf("%d ", a[j]);
	}
	printf("\n");
	b = reverseSq(a);
	for (int i = 0; i < LIST_SIZE; ++i)
	{
		printf("%d ", b[i]);
	}
	free(b);
	return 0;
}
