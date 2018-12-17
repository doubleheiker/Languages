/**
 *输入格式
　　输入的第一行包含三个整数n, L, t，
	用空格分隔，分别表示小球的个数、线段长度和你需要计算t秒之后小球的位置。
　　第二行包含n个整数a1, a2, …, an，用空格分隔，表示初始时刻n个小球的位置。
 输出格式
　　输出一行包含n个整数，用空格分隔，第i个整数代表初始时刻位于ai的小球，在t秒之后的位置。
 样例输入
 3 10 5
 4 6 8
 样例输出
 7 9 9
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//小球转向
void Turn(bool &a){
	if (a) a = false;//左向
	else a = true;//右向
}

//判断小球是否碰撞
void Judge(int a[], int num, bool b[]){
	for (int i = 1; i <= num; ++i)
	{
		for (int j = i + 1; j <= num; ++j)
		{
			if (a[i] == a[j])
			{
				Turn(b[i]);
				Turn(b[j]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int numball, L, t;
	cin >> numball >> L >> t;
	bool *state = new bool[numball + 2];
	int *vir = new int[numball + 2];
	for (int i = 1; i <= numball; ++i)
	{
		cin >> vir[i];
		state[i] = true;
	}
	vir[numball + 1] = -1;
	while(t--){
		Judge(vir, numball, state);
		for (int i = 1; i <= numball; ++i)
		{
			if (vir[i] == L)
			{
				state[i] = false;
			}
			else if (vir[i] == 0)
			{
				state[i] = true;
			}
			if (state[i])
			{
				vir[i]++;
			}
			else if (!state[i])
			{
				vir[i]--;
			}
		}
	}
	for (int i = 1; i <= numball; ++i)
	{
		cout << vir[i] << " ";
	}
	return 0;
}