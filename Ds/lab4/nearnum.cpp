/**
 *问题描述：首先输入正整数n（n<10000），接着输入n个正整数（最大值为10000），
 对于这n个数，统计输出其中的相邻数对（差值为1的数对），相同数据只被统计一次。
 问题分析：这个看似是一个ｎ个数与n个数进行比较（O(n2)）的问题,能否用高效的方法解决？
 样例输入
 6
 1 3 8 2 5 2
 样例输出
 2
 样例输入
 5
 4 3 6 3 5 2
 样例输出
 4
 */
#include <iostream>
#include <algorithm>
#include <stdio.h>
 using namespace std;
 
const int N = 1000;
int a[N];
 
int main(void)
{
    int n, cnt = 0;
    // 输入数据
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    // 排序
    sort(a, a + n);
    // 统计
    for(int i=1; i<n; i++)
        if(a[i] - a[i - 1] == 1)
            cnt++;
    // 输出结果
    printf("%d\n", cnt);
    return 0;
}