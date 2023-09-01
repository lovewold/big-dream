#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// �ڽӱ�ڵ�
typedef struct Node 
{
    int vertex;          // ����
    struct Node* next;   // ָ����һ���ڵ��ָ��
} Node;

// ͼ
typedef struct Graph 
{
    int numVertices;     // ��������
    Node** adjacencyList; // �ڽӱ�
} Graph;

// ����ͼ
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

// ��ӱ�
void addEdge(Graph* graph, int src, int dest) 
{
    // ��Ӵ�src��dest�ı�
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // ��Ӵ�dest��src�ı�
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// ͼ��BFS����
void BFS(Graph* graph, int startVertex) 
{
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) 
    {
        visited[i] = 0;
    }

    // ��������
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS�������: ");

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

// Prim�㷨
void primMST(Graph* graph)
{
    int numVertices = graph->numVertices;
    int* parent = (int*)malloc(numVertices * sizeof(int));  // ������С�������ĸ��ڵ�
    int* key = (int*)malloc(numVertices * sizeof(int));     // ���涥���Ȩֵ
    int* mstSet = (int*)malloc(numVertices * sizeof(int));  // ��Ƕ����Ƿ��������С��������

    // ��ʼ��key��mstSet
    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;    // ����һ��������Ϊ��ʼ����
    parent[0] = -1; // ��һ������û�и��ڵ�

    for (int count = 0; count < numVertices - 1; count++) {
        // ѡ��Ȩֵ��С�Ķ���
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < numVertices; v++)
        {
            if (!mstSet[v] && key[v] < minKey) 
            {
                minKey = key[v];
                minIndex = v;
            }
        }

        mstSet[minIndex] = 1; // �����������С������

        // �������ڶ����Ȩֵ�͸��ڵ�
        Node* temp = graph->adjacencyList[minIndex];
        while (temp) 
        {
            int adjVertex = temp->vertex;
            int weight = 1;  // �������ߵ�Ȩֵ��Ϊ1

            if (!mstSet[adjVertex] && weight < key[adjVertex]) 
            {
                parent[adjVertex] = minIndex;
                key[adjVertex] = weight;
            }

            temp = temp->next;
        }
    }

    printf("Prim��С���������:\n");
    for (int i = 1; i < numVertices; i++) 
    {
        printf("%d - %d\n", parent[i], i);
    }

    free(parent);
    free(key);
    free(mstSet);
}

// Dijkstra�㷨
void dijkstra(Graph* graph, int startVertex) 
{
    int numVertices = graph->numVertices;
    int* shortestDist = (int*)malloc(numVertices * sizeof(int)); // ������ʼ���㵽�����������̾���
    int* visited = (int*)malloc(numVertices * sizeof(int));     // ��Ƕ����Ƿ񱻷��ʹ�

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
            int weight = 1;  // �������ߵ�Ȩֵ��Ϊ1

            if (!visited[adjVertex] && shortestDist[minIndex] != INT_MAX &&
                shortestDist[minIndex] + weight < shortestDist[adjVertex]) 
            {
                shortestDist[adjVertex] = shortestDist[minIndex] + weight;
            }

            temp = temp->next;
        }
    }

    printf("Dijkstra��̾�����(���Ϊ %d):\n", startVertex);
    for (int i = 0; i < numVertices; i++) 
    {
        printf("���� %d: %d\n", i, shortestDist[i]);
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
