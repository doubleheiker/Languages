/**
 *编程实现书P156  ADT Graph 基本操作13个，用邻接矩阵存储结构实现；
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20 //最大顶点个数
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

bool visit[MAX_VERTEX_NUM];
int INFINITY = 100;      //最大值∞

typedef int Status;
typedef struct ArcCell
{
	int adj;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	int vex[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
}MGraph;

//返回点的位置
int LocateVex(MGraph G, int u){
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (u == G.vex[i])
		{
			return i;
		}
	}
	return ERROR;
}

//构造图G, 无向图
Status CreateGraph(MGraph &G){
	int v1, v2, w;
	scanf("%d%d", &G.vexnum, &G.arcnum);
	for (int i = 0; i < G.vexnum; ++i)
	{
		scanf("%d", &G.vex[i]);//构造顶点向量
	}
	for (int i = 0; i < G.vexnum; ++i)//初始化邻接矩阵
	{
		for (int j = 0; j < G.vexnum; ++j) G.arcs[i][j].adj = INFINITY;
	}
	for (int k = 0; k < G.arcnum; ++k)//构造邻接矩阵
	{
		scanf("%d%d%d", &v1, &v2, &w);
		int i = LocateVex(G, v1), j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		//G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

//删除图G
Status DestroyGraph(MGraph &G){
	for (int i = 0; i < G.vexnum; ++i)
	{
		G.vex[i] = -1;
	}
	for (int i = 0; i < G.vexnum; ++i)//初始化邻接矩阵
	{
		for (int j = 0; j < G.vexnum; ++j) G.arcs[i][j].adj = INFINITY;
	}
	return OK;
}

//GetVex()????没明白啥意思
//PutVex()????+1

Status FirstAdjVex(MGraph G, int v){
	int i = LocateVex(G, v);
	for (int j = i; j < G.vexnum; ++j)
	{
		if (G.arcs[i][j].adj != INFINITY)
		{
			return G.vex[j];
		}
	}
	return -1;
}

Status NextAdjVex(MGraph G, int v, int w){
	int i = LocateVex(G, v);
	int x = LocateVex(G, w);
	for (int j = 0; j < G.vexnum; ++j)
	{
		if (G.arcs[i][j].adj != INFINITY && j != x)
		{
			return G.vex[j];
		}
	}
	return -1;
}

Status InsertVex(MGraph &G, int v){
	if (G.vexnum + 1 > MAX_VERTEX_NUM)
	{
		return ERROR;
	}
	for (int i = 0; i <= G.vexnum; ++i)
	{
		G.arcs[i][G.vexnum].adj = INFINITY;
	}
	for (int j = 0; j <= G.vexnum; ++j)
	{
		G.arcs[G.vexnum][j].adj = INFINITY;
	}
	G.vexnum++;
	G.vex[G.vexnum] = v;
	return OK;
}

Status DeleteVex(MGraph &G, int v){
	int x = LocateVex(G, v);
	if (!LocateVex(G, v))
	{
		return ERROR;
	}
	for (int j = 0; j < G.vexnum; ++j)
	{
		G.arcs[x][j] = G.arcs[G.vexnum-1][j];
	}
	for (int i = 0; i < G.vexnum; ++i)
	{
		G.arcs[i][x] = G.arcs[i][G.vexnum-1];
	}
	G.vex[x] = G.vex[G.vexnum];
	G.vexnum--;
	return OK;
}

Status InsertArc(MGraph &G, int v, int w){
	int i = LocateVex(G, v), j = LocateVex(G, w);
	if (!i && !j)
	{
		return ERROR;
	}
	G.arcs[i][j].adj = 1;
	return OK;
}

Status DeleteVex(MGraph &G, int v, int w){
	int i = LocateVex(G, v), j = LocateVex(G, w);
	if (!i && !j)
	{
		return ERROR;
	}
	G.arcs[i][j].adj = INFINITY;
	return OK;
}

void DFS(MGraph G, int v){
	visit[v] = TRUE;
	for (int w = FirstAdjVex(G, v); w >= 0; w=NextAdjVex(G, v, w))
	{
		if (!visit[v])
		{
			DFS(G, w);
		}
	}
}

void DFSTraverse(MGraph G, int v){
	for (int v = 0; v < G.vexnum; ++v) visit[v] = FALSE;
	for (int v = 0; v < G.vexnum; ++v) 
		if (!visit[v]) DFS(G, v);
}

void BFSTraverse(MGraph G, int v){
	for (int v = 0; v < G.vexnum; ++v)
	{
		visit[v] = FALSE;
	}
	//InitQueue(Q);
	for (int v = 0; v < G.vexnum; ++v)
	{
		if (!visit[v])
		{
			visit[v] = TRUE;
			//EnQueue(Q, v);
			/*while(!QueueEmpty(Q)){
				DeQueue(Q, u);
				for (int w = 0; w >= 0; w = Nex)
				{
					if (!visit[v])
					{
						visit[w] = TRUE;
						EnQueue(Q, w);
					}
				}
			}*/
		}
	}
}

int main(int argc, char const *argv[])
{
	return 0;
}