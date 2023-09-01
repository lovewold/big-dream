#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000 //最大顶点数
#define MAXM 3000 //最大边数
#define INF 0x7fffffff //无穷大

//定义边的结构体
typedef struct {
    int u, v; //边的两个顶点
    int w; //边的权值
} Edge;

//定义边数组
Edge edges[MAXM];

//定义辅助数组，记录每个顶点所属的连通分量
int parent[MAXN];

//比较函数，按照边的权值升序排序
int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

//查找x所属的连通分量，即根节点
int find(int x) {
    if (parent[x] == x) return x; //如果x是根节点，直接返回
    return parent[x] = find(parent[x]); //否则，递归查找，并路径压缩
}

//合并x和y所属的连通分量
void join(int x, int y) {
    int px = find(x); //找到x的根节点
    int py = find(y); //找到y的根节点
    if (px != py) { //如果不相同，说明不在同一个连通分量中
        parent[px] = py; //把x的根节点作为y的根节点的子节点
    }
}

//求解最小生成树的总权值，如果不连通则返回-1
int kruskal(int n, int m) {
    int i, ans = 0, cnt = 0;
    qsort(edges, m, sizeof(Edge), cmp); //对边数组按照权值升序排序
    for (i = 0; i < n; i++) {
        parent[i] = i; //初始化每个顶点自成一个连通分量
    }
    for (i = 0; i < m; i++) {
        int u = edges[i].u; //取出一条边的起点
        int v = edges[i].v; //取出一条边的终点
        if (find(u) != find(v)) { //如果两个顶点不在同一个连通分量中
            ans += edges[i].w; //累加该边的权值到答案中
            cnt++; //记录已选择的边数加一
            join(u, v); //合并两个顶点所在的连通分量
        }
    }
    if (cnt < n - 1) return -1; //如果选择的边数小于n-1，说明不连通
    return ans; //返回最小生成树的总权值
}
int main() {
    int n, m, i;
    printf("请输入城镇数目和候选道路数目：\n"); //输出提示信息
    scanf("%d%d", &n, &m); //输入顶点数和边数
    printf("请输入每条候选道路的两个城镇编号和预算成本：\n"); //输出提示信息
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w); //输入每条边的起点，终点和权值
    }
    printf("最低成本为：\n"); //输出提示信息
    printf("%d\n", kruskal(n, m)); //输出最小生成树的总权值或-1
    return 0;
}
