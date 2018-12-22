/**
 *输入样例:
4 4
1 2 1 
2 3 4
2 4 2
3 4 3  
输出样例:
6  
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 101
int Tree[N];

struct Edge
{
	int a, b;
	int cost;
	bool operator < (const Edge &A)
	const {
		return cost < A.cost;
	}
}edge[6000];

//并查集
int findRoot(int x){
	int tmp;
	if (Tree[x] == -1)
	{
		return x;
	}
	else{
		tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int main(int argc, char const *argv[])
{
	int n, m;//麦田片数和可建水渠数
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
	}
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= n; ++i)
	{
		Tree[i] = -1;
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		int a = findRoot(edge[i].a);
		int b = findRoot(edge[i].b);
		if (a != b)
		{
			Tree[a] = b;
			ans += edge[i].cost;
		}
	}
	printf("%d\n", ans);
	return 0;
}