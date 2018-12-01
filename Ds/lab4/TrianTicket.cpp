/**
 *问题描述：请实现一个铁路购票系统的简单座位分配算法，来处理一节车厢的座位分配。
　　假设一节车厢有20排、每一排5个座位。为方便起见，我们用1到100来给所有的座位编号，
	第一排是1到5号，第二排是6到10号，依次类推，第20排是96到100号。
　　购票时，一个人可能购一张或多张票，最多不超过5张。
	如果这几张票可以安排在同一排编号相邻的座位，则应该安排在编号最小的相邻座位。
	否则应该安排在编号最小的几个空座位中（不考虑是否相邻）。
　　假设初始时车票全部未被购买，现在给了一些购票指令，请你处理这些指令。
 输入格式：对于所有评测用例，1 ≤ n ≤ 100，所有购票数量之和不超过100。
　　输入的第一行包含一个整数n，表示购票指令的数量。
　　第二行包含n个整数，每个整数p在1到5之间，表示要购入的票数，相邻的两个数之间使用一个空格分隔。
 输出格式
 输出n行，每行对应一条指令的处理结果。
　　对于购票指令p，输出p张车票的编号，按从小到大排序。
 问题分析：这个问题可以用顺序结构或链式结构实现。
 样例输入
 4
 2 5 4 2
 样例输出
 1 2
 6 7 8 9 10
 11 12 13 14
 3 4
 */
#include<iostream>  
#include<vector>  
#include<algorithm>
using namespace std;

int train[20][5] = { 0 };

int avaliable(int t[])//判断该排还有几个空座位
{
	int tem = 0;
	for (int i = 0; i <5; i++)
	{
		if (t[i] == 0)
			tem++;
	}
	return tem;
}

vector<int> get_ticket(int n)//需要n个座位的情况下，返回值为所有的座位编号
{
	vector<int> rt;
	for (int i = 0; i < 20; i++)//从第一排开始遍历
	{
		if (avaliable(train[i]) >= n) //如果当前排拥有足够的座位
		{
			for (int j = 0; j < 5; j++)
			{
				if (train[i][j] == 0) //遇到空座位就分配
				{
					train[i][j] = 1;
					rt.push_back(5 * i + j + 1);//座位号
					n--;
					if(n==0)
					return rt;//分配完n个座位后返回
				}
			}
		}
		else
			continue;
	}
	for (int i = 0; i < 20; i++)//如果遍历了所有的排都没有连续的n个座位
	{
		for (int j = 0; j < 5; j++)  //从前往后找到n个空的座位
		{
			if (train[i][j] == 0)
			{
				train[i][j] = 1;//标记该座位已经被售出
				rt.push_back(5 * i + j + 1);
				n--;
				if (n == 0)
				return rt;//返回结果
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> need(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> need[i];
	}
	
	for (int i = 0; i < need.size(); i++)//依次处理购票需求
	{
		vector<int> result = get_ticket(need[i]);
		for (int j = 0; j < result.size(); j++)
		{
			cout << result[j]<<" ";
		}
		cout << endl;
	}
}
