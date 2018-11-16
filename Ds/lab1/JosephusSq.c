/**
 *约瑟夫问题
 *输入正整数n、m（m<n），设有n个人坐成一圈，
 *从第1个人开始循环报数，报到m的人出列，然后再从下一个人开始报数，报到m的人又出列，如此重复，直到所有的人都出列为止。
 *要求用链式结构和顺序结构实现，按出列的先后顺序输出每个人的信息。
 *顺序结构表示如下：
 */
#include <stdio.h>
#include <stdlib.h>
int run(int total, int tag)
{
	if (total == 1)
	{
		printf("1\n");
		exit(0);
	}

	//初始化数组
	int *a = (int*)malloc(total*sizeof(int));
	for (int i = 0; i < total; ++i)
	{
		a[i] = 0;
	}

	int i = 0, j = 1;
	//开始约瑟夫环
	int n = total;
	while(n > 0)
	{
		if (i >= total)
		{
			i = i%total;
		}
		if (a[i] != -1)
		{
			if (j == tag)//出列
			{
				printf("%d\n", i+1);
				a[i] = -1;
				j = 1;
				i++;
				n--;
			}
			else
			{
				i++;
				j++;
			}
		}
		else i++;//未出列
	}
	free(a);
}

int main(int argc, char const *argv[])
{
	run(5,2);
	return 0;
}