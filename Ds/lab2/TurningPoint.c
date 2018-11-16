/*
 *先输入一个十进制整数n，再输入n个正整数，求它们相邻数之差可知是否为上升或下降，
 *由上升转下降或由下降转上升为折点，求折点数。
 *问题分析：如果一个点的值比左右两个都大或都小，则为折点。
 */
#include <stdio.h>
#define LIST_INIT_SZIE 100

//求转折点
int turnP(int *a, int n)
{
	int flag, count = 0;
	if (a[0] < a[1])
	{
		flag = 1;
	}
	else{
		flag = 0;
	}
	for (int i = 1; i < n-1; ++i)
	{
		if (a[i] < a[i+1] && flag != 1)
		{
			flag = 1;
			count++;
		}
		else if (a[i] > a[i+1] && flag !=0)
		{
			flag = 0;
			count++;
		}
		else continue;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int a[LIST_INIT_SZIE];
	int num;
	printf("input the number of the array:\n");
	scanf("%d", &num);
	printf("input the array:\n");
	for (int i = 0; i < num; ++i)
	{
		scanf("%d", &a[i]);
	}
	printf("The number of the turning points: %d\n", turnP(a, num));
	return 0;
}


