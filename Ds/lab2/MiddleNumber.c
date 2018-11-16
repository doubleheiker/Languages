/*
 *首先输入正整数n，接着输入n个正整数，如果其中存在一个数，比该数大的个数等于比该数小的个数，则输出该数，如果不存在则输出-1。
 *问题分析：这个问题可以用排序来实现。
 */
#include <stdio.h>
#define LIST_INIT_SZIE 100

//选择排序
void SelectSort(int *a, int len){
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (a[i] < a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void MidNum(int *a, int len)
{
	int mid, rightnum, leftnum;
	mid = len/2;
	leftnum = mid;
	rightnum = len - mid - 1;
	//去掉中间数附近的相同的数
	for (int i = mid - 1; i >= 0; --i)
	{
		if (a[mid] == a[i])
		{
			leftnum--;
		}
		else break;
	}
	for (int i = mid + 1; i < len; ++i)
	{
		if (a[mid] == a[i])
		{
			rightnum--;
		}
		else break;
	}
	//比较左边的数的个数是否等于右边
	if (leftnum == rightnum)
	{
		printf("The middle number is: %d", a[mid]);
	}
	else printf("-1\n");
}

int main(int argc, char const *argv[])
{
	int len;
	int a[LIST_INIT_SZIE];
	printf("Please input the length of array:\n");
	scanf("%d", &len);
	printf("Please input the array:\n");
	for (int i = 0; i < len; ++i)
	{
		scanf("%d", &a[i]);
	}
	SelectSort(a, len);
	MidNum(a, len);
	return 0;
}