#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义边的结构体
struct Edge {
    int src;    // 边的起点
    int dest;   // 边的终点
    int cost;   // 边的成本
};

// 定义并查集的结构体
struct DisjointSet {
    int* parent;    // 存储父节点
    int* rank;      // 存储秩
};

// 初始化并查集
struct DisjointSet* createDisjointSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->parent = (int*)malloc((n + 1) * sizeof(int));
    set->rank = (int*)malloc((n + 1) * sizeof(int));

    // 初始化每个节点的父节点为自身
    for (int i = 0; i <= n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

// 查找根节点
int find(struct DisjointSet* set, int x) {
    if (set->parent[x] != x) {
        set->parent[x] = find(set, set->parent[x]);
    }
    return set->parent[x];
}

// 合并两个集合
void unionSets(struct DisjointSet* set, int x, int y) {
    int rootX = find(set, x);
    int rootY = find(set, y);

    if (set->rank[rootX] < set->rank[rootY]) {
        set->parent[rootX] = rootY;
    }
    else if (set->rank[rootX] > set->rank[rootY]) {
        set->parent[rootY] = rootX;
    }
    else {
        set->parent[rootY] = rootX;
        set->rank[rootX]++;
    }
}

// 按成本升序对边进行排序
void sortEdges(struct Edge* edges, int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].cost > edges[j + 1].cost) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// 计算最小生成树的最低成本
int calculateMinCost(struct Edge* edges, int numEdges, int numVertices) {
    // 对边按成本升序排序
    sortEdges(edges, numEdges);

    int minCost = 0;    // 最小成本
    int numSelectedEdges = 0;   // 已选择的边的数量
    struct DisjointSet* set = createDisjointSet(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        // 判断是否形成环路
        if (find(set, src) != find(set, dest)) {
            minCost += edges[i].cost;
            unionSets(set, src, dest);
            numSelectedEdges++;

            // 如果已选择的边数等于节点数减1，则已形成最小生成树
            if (numSelectedEdges == numVertices - 1) {
                break;
            }
        }
    }

    // 如果已选择的边数不等于节点数减1，则无法连通
    if (numSelectedEdges != numVertices - 1) {
        minCost = -1;
    }

    free(set->parent);
    free(set->rank);
    free(set);

    return minCost;
}

int main() {
    int N, M;   // 城镇数目和候选道路数目
    scanf("%d %d", &N, &M);

    struct Edge* edges = (struct Edge*)malloc(M * sizeof(struct Edge));

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].cost);
    }

    int minCost = calculateMinCost(edges, M, N);
    printf("%d\n", minCost);

    free(edges);

    return 0;
}
