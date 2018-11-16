/**
 *输入格式
 *　输入的第一行包含一个整数n，表示学生的数量，学生的学号由1到n编号。
 *　第二行包含一个整数m，表示调整的次数。
 *　接下来m行，每行两个整数p, q，如果q为正，表示学号为p的同学向后移动q，如果q为负，表示学号为p的同学向前移动-q。
 *输出格式
 *　输出一行，包含n个整数，相邻两个整数之间由一个空格分隔，表示最终从前向后所有学生的学号。
 *样例输入
 *8
 *3
 *3 2
 *8 -3
 *3 -2
 *样例输出
 *1 2 4 3 5 8 6 7
 */
#include<stdio.h>
int n,num,c;
int a[1001];
//移动学生
void move(int p,int q)
{
    int temp,t;
    //找到学生
    for(int i=1;i<=n;i++)
    {
        if(a[i]==p)
        {
            temp=i;
            break;
        }
    }
    if(temp+q<=1) t=1;
    else if(temp+q>=n) t=n;
    else t=temp+q;
    c=a[t];
    a[t]=a[temp];
    //向后移动q
    if(q>0)
    {
        int i;
        for(i=temp;i<t-1;i++)
        {
            a[i]=a[i+1];
        }
        a[i]=c;
    }
    //向前移动q
    if(q<0)
    {
        int i;
        for(i=temp;i>t+1;i--)
        {
            a[i]=a[i-1];
        }
        a[i]=c;
    }
}

int main()
{
    int i;
    scanf("%d",&n);
    scanf("%d",&num);
    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }
    for(i=1;i<=num;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        move(p,q);
    }
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    return 0;
}