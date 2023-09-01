#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ������г���
#define MAXSIZE 1000

// ������нṹ��
typedef struct Queue
{
    int data[MAXSIZE]; // �洢�˿ͱ��
    int front; // ����λ��
    int rear; // ��βλ��
} Queue;

// ��ʼ��һ�����У�������׺Ͷ�β����Ϊ0����������ָ��
Queue* initQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue)); // �����ڴ�ռ�
    q->front = q->rear = 0; // ��ʼ�����׺Ͷ�βΪ0
    return q;
}

// �ж�һ�������Ƿ�Ϊ�գ����Ϊ�շ���1�����򷵻�0
int isEmpty(Queue* q)
{
    return q->front == q->rear;
}

// �ж�һ�������Ƿ�Ϊ�������Ϊ������1�����򷵻�0
int isFull(Queue* q)
{
    return (q->rear + 1) % MAXSIZE == q->front;
}

// ��һ��Ԫ����ӵ�һ�������У�����Ϊ����ָ���Ԫ��ֵ
void enqueue(Queue* q, int x)
{
    if (isFull(q)) return; // �������������ֱ�ӷ���
    q->data[q->rear] = x; // ��Ԫ��ֵ�洢����βλ��
    q->rear = (q->rear + 1) % MAXSIZE; // ���¶�βλ�ã�ע��ȡģ��ֹԽ��
}

// ��һ��Ԫ�س��Ӵ�һ�������У���������ֵ������Ϊ����ָ��
int dequeue(Queue* q)
{
    if (isEmpty(q)) return -1; // �������Ϊ�գ�����-1��ʾ����
    int x = q->data[q->front]; // ����Ҫ���ӵ�Ԫ��ֵ
    q->front = (q->front + 1) % MAXSIZE; // ���¶���λ�ã�ע��ȡģ��ֹԽ��
    return x; // ���س��ӵ�Ԫ��ֵ
}

// �ͷ�һ������ռ�õ��ڴ�ռ䣬����Ϊ����ָ��
void freeQueue(Queue* q)
{
    free(q); // �ͷŶ��нṹ��ռ�õ��ڴ�ռ�
}

// ��һ����������������򣬲���Ϊ����ָ������鳤��
void sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    { // ���ѭ������ѡ�������n-1�μ���
        int min = i; // ���赱ǰλ��Ϊ��Сֵλ��
        for (int j = i + 1; j < n; j++)
        { // �ڲ�ѭ���ӵ�ǰλ�ú��濪ʼ�Ҹ�С��ֵ
            if (arr[j] < arr[min])
            { // ����ҵ���С��ֵ��������Сֵλ��
                min = j;
            }
        }
        if (min != i)
        { // �����Сֵλ�÷����仯��������ǰλ�ú���Сֵλ�õ�Ԫ��
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int N; // �˿�����
    int id[MAXSIZE]; // �˿ͱ������

    Queue* A = initQueue(); // ��ʼ��A���ڵĹ˿ͱ�Ŷ���
    Queue* B = initQueue(); // ��ʼ��B���ڵĹ˿ͱ�Ŷ���

    printf("������˿�������\n"); // ������ʾ
    scanf("%d", &N); // ����N

    printf("������ÿ���˿͵ı�ţ�����ȥA���ڣ�ż��ȥB���ڣ���\n"); // ������ʾ
    for (int i = 0; i < N; i++)
    { // ѭ��N�Σ�����ÿ���˿͵ı�ţ����洢��������
        scanf("%d", &id[i]);
    }

    sort(id, N); // �Թ˿ͱ����������������򣬱�֤���յ������е��Ⱥ�˳����

    for (int i = 0; i < N; i++)
    { // ѭ��N�Σ�������ż�Խ������ӵ���Ӧ�Ĵ���
        if (id[i] % 2 == 1)
        { // ������Ϊ��������ӵ�A����
            enqueue(A, id[i]);
        }
        else
        { // ������Ϊż������ӵ�B����
            enqueue(B, id[i]);
        }
    }

    printf("��ҵ������ɵ�˳������˿͵ı�ţ�\n"); // �����ʾ
    int first = 1; // ����һ����־�����������ж��Ƿ��ǵ�һ������ı��
    while (!isEmpty(A) || !isEmpty(B))
    { // ���������ڶ���Ϊ��ʱ��ѭ������˿�
        for (int i = 0; i < 2; i++)
        { // ÿ�δ�A���ڳ��������˿ͣ�����У�����������ǵı��
            int x = dequeue(A);
            if (x != -1)
            {
                if (first)
                { // ����ǵ�һ����ţ�ֱ�����
                    printf("%d", x);
                    first = 0;
                }
                else
                {
                    printf(" %d", x);
                }
            }
        }
        int y = dequeue(B); // ÿ�δ�B���ڳ���һ���˿ͣ�����У�����������ǵı��
        if (y != -1)
        {
            if (first)
            { // ����ǵ�һ����ţ�ֱ�����
                printf("%d", y);
                first = 0; // ����־������Ϊ0
            }
            else
            { // ������ǵ�һ����ţ������һ���ո������
                printf(" %d", y);
            }
        }
    }
    printf("\n"); // ������з�

    freeQueue(A); // �ͷ�A���ڵĹ˿ͱ�Ŷ���ռ�õ��ڴ�ռ�
    freeQueue(B); // �ͷ�B���ڵĹ˿ͱ�Ŷ���ռ�õ��ڴ�ռ�

    return 0;
}