#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 添加布尔类型的头文件

#define MaxVertexNum 1000
typedef int Vertex;
typedef int WeightType;

typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode* PtrToGENode;
struct GNode {
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGENode LGraph;

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();

typedef Vertex ElementType;
typedef Vertex SetName;
typedef ElementType SetType[MaxVertexNum];

void InitializeVSet(SetType S, int N);
void Union(SetType S, SetName Root1, SetName Root2);
SetName Find(SetType S, ElementType X);

bool CheckCycle(SetType VSet, Vertex V1, Vertex V2);
int Kruskal(LGraph Graph);

int main() {
	LGraph G = BuildGraph();
	printf("%d\n", Kruskal(G));
	return 0;
}

LGraph CreateGraph(int VertexNum) {
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E) {
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;

	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;

	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph() {
	// 实现构建图的逻辑
	// 你的代码...
}

void InitializeVSet(SetType S, int N) {
	int i;
	for (i = 0; i < N; i++)
		S[i] = -1;
}

void Union(SetType S, SetName Root1, SetName Root2) {
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

SetName Find(SetType S, ElementType X) {
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}

bool CheckCycle(SetType VSet, Vertex V1, Vertex V2) {
	Vertex Root1 = Find(VSet, V1);
	Vertex Root2 = Find(VSet, V2);
	if (Root1 == Root2)
		return true;
	else
		return false;
}

int Kruskal(LGraph Graph) {
	SetType VSet;
	Edge E;
	int totalWeight = 0;
	int ECount = 0;
	int NextEdgeIndex = 0;
	int i;

	InitializeVSet(VSet, Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode) * Graph->Ne);
	InitializeESet(Graph, E);

	while (ECount < Graph->Nv - 1) {
		NextEdgeIndex = GetEdge(E, NextEdgeIndex);
		if (NextEdgeIndex == -1)
			break;

		if (!CheckCycle(VSet, E[NextEdgeIndex].V1, E[NextEdgeIndex].V2)) {
			totalWeight += E[NextEdgeIndex].Weight;
			ECount++;
			Union(VSet, E[NextEdgeIndex].V1, E[NextEdgeIndex].V2);
		}

		NextEdgeIndex++;
	}

	if (ECount < Graph->Nv - 1)
		totalWeight = -1;

	free(E);
	return totalWeight;
}
