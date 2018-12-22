#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY 65535 //表示∞
#define TRUE 1
#define FALSE 0
typedef char VertexType;
typedef int EdgeType;
typedef int Bool;
Bool visit[MAXVEX];

typedef struct
{
	VertexType vex[MAXVEX];
	EdgeType arcs[MAXVEX][MAXVEX];
	int vexnum, arcnum;
}MGraph;

//广度优先遍历需要的队列
typedef struct 
{
	int data[MAXVEX];
	int front, rear;
}Queue;

void InitQueue(Queue *Q){
	Q->front = Q->rear = 0;
}

void EnQueue(Queue *Q, int e){
	if ((Q->rear + 1)%MAXVEX == Q->front)
	{
		return ;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1)%MAXVEX;
}

Bool QueueEmpty(Queue *Q){
	if (Q->front == Q->rear)
	{
		return TRUE;
	}
	else return FALSE;
}

void DeQueue(Queue *Q, int *e){
	if (Q->front == Q->rear)
	{
		return;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXVEX;
}

//返回点的位置
int LocateVex(MGraph *G, char u){
	for (int i = 0; i < G->vexnum; ++i)
	{
		if (u == G->vex[i])
		{
			return i;
		}
	}
	return -1;
}

//构造图G, 无向图
void CreateGraph(MGraph *G){ 
	int v1, v2, w;
	printf("vexnum, arcnum: \n");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	fflush(stdin);
	for (int i = 0; i < G->vexnum; ++i)
	{
		printf("vex%d: ", i+1);
		scanf("%c", &G->vex[i]);//构造顶点向量
		fflush(stdin);
	}
	for (int i = 0; i < G->vexnum; ++i)//初始化邻接矩阵
	{
		for (int j = 0; j < G->vexnum; ++j) G->arcs[i][j] = INFINITY;
	}
	for (int k = 0; k < G->arcnum; ++k)//构造邻接矩阵
	{
		printf("v1,v2,w: ");
		scanf("%d%d%d", &v1, &v2, &w);
		//int i = LocateVex(G, v1), j = LocateVex(G, v2);
		G->arcs[v1][v2] = w;
		G->arcs[v2][v1] = G->arcs[v1][v2];
		fflush(stdin);
	}
}

void DisMGraph(MGraph *G){
	int k;
	k = G->vexnum;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			printf("%5d ", G->arcs[i][j]);
		}
		putchar('\n');
	}
}

//图的深度遍历
void DFS(MGraph G, int i){
	visit[i] = TRUE;
	printf("%c ", G.vex[i]);
	for (int j = 0; j < G.vexnum; ++j)
	{
		if (G.arcs[i][j] != INFINITY && !visit[j])
		{
			DFS(G, j);
		}
	}
}

void DFSTraverse(MGraph G){
	for (int i = 0; i < G.vexnum; ++i)
	{
		visit[i] = FALSE;
	}
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (!visit[i])
		{
			DFS(G, i);
		}
	}
}

//图的广度优先遍历
void BFSTraverse(MGraph *G){
	Queue Q;
	for (int i = 0; i < G->vexnum; ++i)
	{
		visit[i] = FALSE;
	}
	InitQueue(&Q);
	for (int i = 0; i < G->vexnum; ++i)
	{
		if (!visit[i])
		{
			visit[i] = TRUE;
			printf("%c ", G->vex[i]);
			EnQueue(&Q, i);
			while(!QueueEmpty(&Q)){
				DeQueue(&Q, &i);
				for (int j = 0; j < G->vexnum; ++j)
				{
					if (!visit[j] && G->arcs[i][j] != INFINITY)
					{
						visit[j] = TRUE;
						printf("%c ", G->vex[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	MGraph G;
	CreateGraph(&G);
	printf("\ndepth: \n");
	DFSTraverse(G);
	printf("\nwide: \n");
	BFSTraverse(&G);
	return 0;
}