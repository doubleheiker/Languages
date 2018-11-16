/**
 *设元素值为整型的线性表L，分别采用顺序结构和链式结构存储，编写程序，用插入排序算法实现线性表的表排序。
 *如下是顺序结构的程序
 */
#include <stdio.h>
#define MAX_LEN 100

void sortSq(int *a, int len)
{
	int temp;
	for (int i = 1; i < len; ++i)
	{
		int j;
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j]> temp; --j)
		{
			a[j+1] = a[j];
		}
		a[j+1] = temp;
		for (int i = 0; i < len; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int a[MAX_LEN], len;
	printf("input the length of Sqlist\n");
	scanf("%d", &len);
	printf("input the Sqlist\n");
	for (int i = 0; i < len; ++i)
	{
		scanf("%d", &a[i]);
	}
	sortSq(a, len);
	return 0;
}