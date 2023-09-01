#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 邻接表节点
typedef struct Node 
{
    int vertex;          // 顶点
    struct Node* next;   // 指向下一个节点的指针
} Node;

// 图
typedef struct Graph 
{
    int numVertices;     // 顶点数量
    Node** adjacencyList; // 邻接表
} Graph;

// 创建图
Graph* createGraph(int numVertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) 
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// 添加边
void addEdge(Graph* graph, int src, int dest) 
{
    // 添加从src到dest的边
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // 添加从dest到src的边
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// 图的BFS遍历
void BFS(Graph* graph, int startVertex) 
{
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) 
    {
        visited[i] = 0;
    }

    // 创建队列
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS遍历结果: ");

    while (front < rear) 
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph->adjacencyList[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) 
            {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    printf("\n");

    free(visited);
    free(queue);
}

// Prim算法
void primMST(Graph* graph)
{
    int numVertices = graph->numVertices;
    int* parent = (int*)malloc(numVertices * sizeof(int));  // 保存最小生成树的父节点
    int* key = (int*)malloc(numVertices * sizeof(int));     // 保存顶点的权值
    int* mstSet = (int*)malloc(numVertices * sizeof(int));  // 标记顶点是否包含在最小生成树中

    // 初始化key和mstSet
    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;    // 将第一个顶点作为起始顶点
    parent[0] = -1; // 第一个顶点没有父节点

    for (int count = 0; count < numVertices - 1; count++) {
        // 选择权值最小的顶点
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < numVertices; v++)
        {
            if (!mstSet[v] && key[v] < minKey) 
            {
                minKey = key[v];
                minIndex = v;
            }
        }

        mstSet[minIndex] = 1; // 将顶点加入最小生成树

        // 更新相邻顶点的权值和父节点
        Node* temp = graph->adjacencyList[minIndex];
        while (temp) 
        {
            int adjVertex = temp->vertex;
            int weight = 1;  // 这里假设边的权值都为1

            if (!mstSet[adjVertex] && weight < key[adjVertex]) 
            {
                parent[adjVertex] = minIndex;
                key[adjVertex] = weight;
            }

            temp = temp->next;
        }
    }

    printf("Prim最小生成树结果:\n");
    for (int i = 1; i < numVertices; i++) 
    {
        printf("%d - %d\n", parent[i], i);
    }

    free(parent);
    free(key);
    free(mstSet);
}

// Dijkstra算法
void dijkstra(Graph* graph, int startVertex) 
{
    int numVertices = graph->numVertices;
    int* shortestDist = (int*)malloc(numVertices * sizeof(int)); // 保存起始顶点到其他顶点的最短距离
    int* visited = (int*)malloc(numVertices * sizeof(int));     // 标记顶点是否被访问过

    for (int i = 0; i < numVertices; i++) 
    {
        shortestDist[i] = INT_MAX;
        visited[i] = 0;
    }

    shortestDist[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) 
    {
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && shortestDist[v] < minDist) 
            {
                minDist = shortestDist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        Node* temp = graph->adjacencyList[minIndex];
        while (temp) 
        {
            int adjVertex = temp->vertex;
            int weight = 1;  // 这里假设边的权值都为1

            if (!visited[adjVertex] && shortestDist[minIndex] != INT_MAX &&
                shortestDist[minIndex] + weight < shortestDist[adjVertex]) 
            {
                shortestDist[adjVertex] = shortestDist[minIndex] + weight;
            }

            temp = temp->next;
        }
    }

    printf("Dijkstra最短距离结果(起点为 %d):\n", startVertex);
    for (int i = 0; i < numVertices; i++) 
    {
        printf("顶点 %d: %d\n", i, shortestDist[i]);
    }

    free(shortestDist);
    free(visited);
}

int main() 
{
    int numVertices = 6;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    BFS(graph, 0);

    primMST(graph);

    dijkstra(graph, 0);

    return 0;
}
