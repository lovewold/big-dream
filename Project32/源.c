#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ����ߵĽṹ��
struct Edge {
    int src;    // �ߵ����
    int dest;   // �ߵ��յ�
    int cost;   // �ߵĳɱ�
};

// ���岢�鼯�Ľṹ��
struct DisjointSet {
    int* parent;    // �洢���ڵ�
    int* rank;      // �洢��
};

// ��ʼ�����鼯
struct DisjointSet* createDisjointSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->parent = (int*)malloc((n + 1) * sizeof(int));
    set->rank = (int*)malloc((n + 1) * sizeof(int));

    // ��ʼ��ÿ���ڵ�ĸ��ڵ�Ϊ����
    for (int i = 0; i <= n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

// ���Ҹ��ڵ�
int find(struct DisjointSet* set, int x) {
    if (set->parent[x] != x) {
        set->parent[x] = find(set, set->parent[x]);
    }
    return set->parent[x];
}

// �ϲ���������
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

// ���ɱ�����Ա߽�������
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

// ������С����������ͳɱ�
int calculateMinCost(struct Edge* edges, int numEdges, int numVertices) {
    // �Ա߰��ɱ���������
    sortEdges(edges, numEdges);

    int minCost = 0;    // ��С�ɱ�
    int numSelectedEdges = 0;   // ��ѡ��ıߵ�����
    struct DisjointSet* set = createDisjointSet(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        // �ж��Ƿ��γɻ�·
        if (find(set, src) != find(set, dest)) {
            minCost += edges[i].cost;
            unionSets(set, src, dest);
            numSelectedEdges++;

            // �����ѡ��ı������ڽڵ�����1�������γ���С������
            if (numSelectedEdges == numVertices - 1) {
                break;
            }
        }
    }

    // �����ѡ��ı��������ڽڵ�����1�����޷���ͨ
    if (numSelectedEdges != numVertices - 1) {
        minCost = -1;
    }

    free(set->parent);
    free(set->rank);
    free(set);

    return minCost;
}

int main() {
    int N, M;   // ������Ŀ�ͺ�ѡ��·��Ŀ
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
