/**
 *编写拓扑排序算法；
 *采用邻接表存储方式；
 */
#include <stdio.h>
#include <stdlib.h>

//-------------图的邻接表表示-------
#define MAX_VERTEX_NUM 20
typedef int Status;
typedef char VertexType;
typedef char InfoType;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;
typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct 
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int indegree[MAX_VERTEX_NUM] = {0}; //记录下标节点的入度

//------------栈的结构-------------
typedef struct StackNode
{
	int data;
	StackNode *next;
}StackNode, *StackList;

//------------栈的操作-------------
StackList Push(StackList &S, int e){
	StackList p;
	p = (StackList)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S;
	S = p;
	return S;
}

StackList Pop(StackList &S, int &e){
	StackList p;
	p = S;
	if (!p)
	{
		return NULL;
	}
	e = p->data;
	S = S->next;
	free(p);
	return S;
}

//-------------创建有向图----------
Status LocateVex(ALGraph *G, VertexType v){
	for (int i = 0; i < G->vexnum; ++i)
	{
		if (v == G->vertices[i].data)
		{
			return i;
		}
	}
	return 0;
}

void CreateUDG(ALGraph *G){
	VertexType v1, v2;
	int m, n;
	ArcNode *p1;
	printf("vexnum, arcnum: \n");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	fflush(stdin);
	printf("vex_data: \n");
	for (int i = 0; i < G->vexnum; ++i)
	{
		scanf("%c", &G->vertices[i].data);
		G->vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G->arcnum; ++i)
	{
		fflush(stdin);
		printf("v1->v2: ");
		scanf("%c %c", &v1, &v2);
		m = LocateVex(G, v1);
		n = LocateVex(G, v2);
		p1 = (ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex = n;
		p1->nextarc = G->vertices[m].firstarc;
		G->vertices[m].firstarc = p1;
		indegree[n]++;//记录入度
	}
}

Status TopologicalSort(ALGraph G, int *topo){
	StackList S;
	int count, i = 0, k;
	ArcNode *p;
	S = NULL;
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (!indegree[i])
		{
			S = Push(S, i);
		}
	}
	count = 0; //对输出点计数
	while(S){
		S = Pop(S, i);
		topo[count] = i;
		++count;
		p = G.vertices[i].firstarc;
		while(p != NULL){
			k = p->adjvex;
			--indegree[k];
			if (indegree[k] == 0)
			{
				S = Push(S, k);
			}
			p = p->nextarc;
		}
	}
	topo[count] = -1;
	if (count < G.vexnum)
	{
		return 0;
	}
	else return 1;
}

int main(int argc, char const *argv[])
{
	ALGraph G;
	int topo[99] = {0};
	CreateUDG(&G);
	if (TopologicalSort(G, topo))
	{
		for (int i = 0; topo[i] != -1; ++i)
		{
			printf("%c ", G.vertices[topo[i]].data);
		}
	}
	else printf("wrong\n");
	return 0;
}