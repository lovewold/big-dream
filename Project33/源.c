#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000 //��󶥵���
#define MAXM 3000 //������
#define INF 0x7fffffff //�����

//����ߵĽṹ��
typedef struct {
    int u, v; //�ߵ���������
    int w; //�ߵ�Ȩֵ
} Edge;

//���������
Edge edges[MAXM];

//���帨�����飬��¼ÿ��������������ͨ����
int parent[MAXN];

//�ȽϺ��������ձߵ�Ȩֵ��������
int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

//����x��������ͨ�����������ڵ�
int find(int x) {
    if (parent[x] == x) return x; //���x�Ǹ��ڵ㣬ֱ�ӷ���
    return parent[x] = find(parent[x]); //���򣬵ݹ���ң���·��ѹ��
}

//�ϲ�x��y��������ͨ����
void join(int x, int y) {
    int px = find(x); //�ҵ�x�ĸ��ڵ�
    int py = find(y); //�ҵ�y�ĸ��ڵ�
    if (px != py) { //�������ͬ��˵������ͬһ����ͨ������
        parent[px] = py; //��x�ĸ��ڵ���Ϊy�ĸ��ڵ���ӽڵ�
    }
}

//�����С����������Ȩֵ���������ͨ�򷵻�-1
int kruskal(int n, int m) {
    int i, ans = 0, cnt = 0;
    qsort(edges, m, sizeof(Edge), cmp); //�Ա����鰴��Ȩֵ��������
    for (i = 0; i < n; i++) {
        parent[i] = i; //��ʼ��ÿ�������Գ�һ����ͨ����
    }
    for (i = 0; i < m; i++) {
        int u = edges[i].u; //ȡ��һ���ߵ����
        int v = edges[i].v; //ȡ��һ���ߵ��յ�
        if (find(u) != find(v)) { //����������㲻��ͬһ����ͨ������
            ans += edges[i].w; //�ۼӸñߵ�Ȩֵ������
            cnt++; //��¼��ѡ��ı�����һ
            join(u, v); //�ϲ������������ڵ���ͨ����
        }
    }
    if (cnt < n - 1) return -1; //���ѡ��ı���С��n-1��˵������ͨ
    return ans; //������С����������Ȩֵ
}
int main() {
    int n, m, i;
    printf("�����������Ŀ�ͺ�ѡ��·��Ŀ��\n"); //�����ʾ��Ϣ
    scanf("%d%d", &n, &m); //���붥�����ͱ���
    printf("������ÿ����ѡ��·�����������ź�Ԥ��ɱ���\n"); //�����ʾ��Ϣ
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w); //����ÿ���ߵ���㣬�յ��Ȩֵ
    }
    printf("��ͳɱ�Ϊ��\n"); //�����ʾ��Ϣ
    printf("%d\n", kruskal(n, m)); //�����С����������Ȩֵ��-1
    return 0;
}
