/**
 *问题描述
　　在某图形操作系统中,有 N 个窗口,每个窗口都是一个两边与坐标轴分别平行的矩形区域。窗口的边界上的点也属于该窗口。
	窗口之间有层次的区别,在多于一个窗口重叠的区域里,只会显示位于顶层的窗口里的内容。
　　当你点击屏幕上一个点的时候,你就选择了处于被点击位置的最顶层窗口,并且这个窗口就会被移到所有窗口的最顶层,
	而剩余的窗口的层次顺序不变。如果你点击的位置不属于任何窗口,则系统会忽略你这次点击。
　　现在我们希望你写一个程序模拟点击窗口的过程。
输入格式
	输入的第一行有两个正整数,即 N 和 M。(1 ≤ N ≤ 10,1 ≤ M ≤ 10)
　　接下来 N 行按照从最下层到最顶层的顺序给出 N 个窗口的位置。 
	每行包含四个非负整数 x1, y1, x2, y2,表示该窗口的一对顶点坐标分别为 (x1, y1) 和 (x2, y2)。保证 x1 < x2, y1 < y2。
　　接下来 M 行每行包含两个非负整数 x, y,表示一次鼠标点击的坐标。
　　题目中涉及到的所有点和矩形的顶点的 x, y 坐标分别不超过 2559 和　　1439。
问题分析：这个问题可以用链式线性表来实现。
输出格式：输出包括 M 行,每一行表示一次鼠标点击的结果。
	如果该次鼠标点击选择了一个窗口,则输出这个窗口的编号(窗口按照输入中的顺序从 1 编号到 N);
	如果没有,则输出"IGNORED"(不含双引号)。
样例输入
3 4
0 0 4 4
1 1 5 5
2 2 6 6
1 1
0 0
4 4
0 5
样例输出
2
1
1
IGNORED
样例说明
　　第一次点击的位置同时属于第 1 和第 2 个窗口,但是由于第 2 个窗口在上面,它被选择并且被置于顶层。
　　第二次点击的位置只属于第 1 个窗口,因此该次点击选择了此窗口并将其置于顶层。现在的三个窗口的层次关系与初始状态恰好相反了。
　　第三次点击的位置同时属于三个窗口的范围,但是由于现在第 1 个窗口处于顶层,它被选择。
　　最后点击的 (0, 5) 不属于任何窗口。
 */
#include <stdio.h>
#include <stdlib.h>
int Windowsnum = 0;//窗口为0
//链表结构
typedef struct LNode
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
	struct LNode *next;
}LNode, *LinkList;

//逆序建立链表，最顶层的窗口作为第一个结点
void CreatList(LinkList &L, int n)
{
	//带头结点
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	//新结点
	for (int i = n; i > 0; --i)
	{
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));
		//printf("input x1,y1,x2,y2\n");
		scanf("%d%d%d%d", &p->x1, &p->y1, &p->x2, &p->y2);//增加鲁棒性，应该检验是否x1 < x2, y1 < y2
		if (p->x1 >= p->x2 || p->y1 >= p->y2 || (p->x1 > 2559 || p->x2 > 2559 || p->y1 > 1439 || p->y2 > 1439))
		{
			printf("Windows Wrong!\n");
			exit(0);
		}
		p->num = ++Windowsnum;
		//printf("%d\n", p->num);
		p->next = L->next;
		L->next = p;
	}
}

//窗口改变
void MoveList(LinkList &L)
{
	int x, y;
	LinkList p, q;
	p = L;
	//printf("input x, y\n");
	scanf("%d%d", &x, &y);
	while(p != NULL)
	{
		q = p->next;
		if (!q)
		{
			p = p->next;
			//printf("The last windows now\n");
			break;
		}
		//找到的第一个窗口符合条件，则将该窗口设置为第一个结点
		if (x <= q->x2 && x >= q->x1 && y <= q->y2 && y >=q->y1)
		{
			if (p == L)
			{
				printf("%d\n", q->num);
				break;
			}
			else{
				p->next = q->next;
				q->next = L->next;
				L->next = q;
				printf("%d\n", q->num);
				break;
			}
		}
		p = p->next;
	}
	//如果没有窗口含有该点
	if (!p)
	{
		printf("IGNORED\n");
	}
}

int main(int argc, char const *argv[])
{
	LinkList L;
	//LinkList temp;
	int N, M;
	scanf("%d%d", &N, &M);//为增加鲁棒性应检查N,M的值的大小
	if (N < 1 || N > 10 || M < 1 || M > 10)
	{
		printf("N,M wrong!");
		exit(0);
	}
	CreatList(L, N);
	//temp = L->next;
	//printf("temp x1 %x\n", temp->x1);
	for (int i = 0; i < M; ++i)
	{
		MoveList(L);
	}
	return 0;
}