#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义队列长度
#define MAXSIZE 1000

// 定义队列结构体
typedef struct Queue
{
    int data[MAXSIZE]; // 存储顾客编号
    int front; // 队首位置
    int rear; // 队尾位置
} Queue;

// 初始化一个队列，将其队首和队尾都置为0，并返回其指针
Queue* initQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue)); // 分配内存空间
    q->front = q->rear = 0; // 初始化队首和队尾为0
    return q;
}

// 判断一个队列是否为空，如果为空返回1，否则返回0
int isEmpty(Queue* q)
{
    return q->front == q->rear;
}

// 判断一个队列是否为满，如果为满返回1，否则返回0
int isFull(Queue* q)
{
    return (q->rear + 1) % MAXSIZE == q->front;
}

// 将一个元素入队到一个队列中，参数为队列指针和元素值
void enqueue(Queue* q, int x)
{
    if (isFull(q)) return; // 如果队列已满，直接返回
    q->data[q->rear] = x; // 将元素值存储到队尾位置
    q->rear = (q->rear + 1) % MAXSIZE; // 更新队尾位置，注意取模防止越界
}

// 将一个元素出队从一个队列中，并返回其值，参数为队列指针
int dequeue(Queue* q)
{
    if (isEmpty(q)) return -1; // 如果队列为空，返回-1表示错误
    int x = q->data[q->front]; // 保存要出队的元素值
    q->front = (q->front + 1) % MAXSIZE; // 更新队首位置，注意取模防止越界
    return x; // 返回出队的元素值
}

// 释放一个队列占用的内存空间，参数为队列指针
void freeQueue(Queue* q)
{
    free(q); // 释放队列结构体占用的内存空间
}

// 对一个数组进行升序排序，参数为数组指针和数组长度
void sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    { // 外层循环控制选择次数，n-1次即可
        int min = i; // 假设当前位置为最小值位置
        for (int j = i + 1; j < n; j++)
        { // 内层循环从当前位置后面开始找更小的值
            if (arr[j] < arr[min])
            { // 如果找到更小的值，更新最小值位置
                min = j;
            }
        }
        if (min != i)
        { // 如果最小值位置发生变化，交换当前位置和最小值位置的元素
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int N; // 顾客总数
    int id[MAXSIZE]; // 顾客编号数组

    Queue* A = initQueue(); // 初始化A窗口的顾客编号队列
    Queue* B = initQueue(); // 初始化B窗口的顾客编号队列

    printf("请输入顾客总数：\n"); // 输入提示
    scanf("%d", &N); // 输入N

    printf("请输入每个顾客的编号（奇数去A窗口，偶数去B窗口）：\n"); // 输入提示
    for (int i = 0; i < N; i++)
    { // 循环N次，输入每个顾客的编号，并存储到数组中
        scanf("%d", &id[i]);
    }

    sort(id, N); // 对顾客编号数组进行升序排序，保证按照到达银行的先后顺序处理

    for (int i = 0; i < N; i++)
    { // 循环N次，根据奇偶性将编号入队到相应的窗口
        if (id[i] % 2 == 1)
        { // 如果编号为奇数，入队到A窗口
            enqueue(A, id[i]);
        }
        else
        { // 如果编号为偶数，入队到B窗口
            enqueue(B, id[i]);
        }
    }

    printf("按业务处理完成的顺序输出顾客的编号：\n"); // 输出提示
    int first = 1; // 设置一个标志变量，用来判断是否是第一个输出的编号
    while (!isEmpty(A) || !isEmpty(B))
    { // 当两个窗口都不为空时，循环处理顾客
        for (int i = 0; i < 2; i++)
        { // 每次从A窗口出队两个顾客（如果有），并输出他们的编号
            int x = dequeue(A);
            if (x != -1)
            {
                if (first)
                { // 如果是第一个编号，直接输出
                    printf("%d", x);
                    first = 0;
                }
                else
                {
                    printf(" %d", x);
                }
            }
        }
        int y = dequeue(B); // 每次从B窗口出队一个顾客（如果有），并输出他们的编号
        if (y != -1)
        {
            if (first)
            { // 如果是第一个编号，直接输出
                printf("%d", y);
                first = 0; // 将标志变量置为0
            }
            else
            { // 如果不是第一个编号，先输出一个空格再输出
                printf(" %d", y);
            }
        }
    }
    printf("\n"); // 输出换行符

    freeQueue(A); // 释放A窗口的顾客编号队列占用的内存空间
    freeQueue(B); // 释放B窗口的顾客编号队列占用的内存空间

    return 0;
}