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
                { =
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

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
// 定义树结点结构体
//typedef struct TreeNode {
//    char name[31]; // 树种名称
//    int count; // 树种数量
//    struct TreeNode* left; // 左子树指针
//    struct TreeNode* right; // 右子树指针
//} TreeNode;
//
// 创建一个新的树结点，初始化其名称和数量，并返回其指针
//TreeNode* newNode(char* name) {
//    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // 分配内存空间
//    strcpy(node->name, name); 
//    node->count = 1; // 初始化数量为1
//    node->left = node->right = NULL; // 初始化左右子树为空
//    return node;
//}
//
// 将一个树种名称插入到二叉搜索树中，如果已存在则增加其数量，否则创建新结点
//void insert(TreeNode** root, char* name) {
//    if (*root == NULL) { // 如果根结点为空，说明是空树，直接创建新结点作为根结点
//        *root = newNode(name);
//        return;
//    }
//    int cmp = strcmp(name, (*root)->name); 
//    if (cmp == 0) { // 如果相等，说明找到了相同的树种，增加其数量
//        (*root)->count++;
//    }
//    else if (cmp < 0) { // 如果小于，说明要插入的名称在字典序上在根结点之前，递归插入到左子树中
//        insert(&(*root)->left, name);
//    }
//    else { // 如果大于，说明要插入的名称在字典序上在根结点之后，递归插入到右子树中
//        insert(&(*root)->right, name);
//    }
//}
//
// 中序遍历二叉搜索树，并输出每种树的名称和百分比
//void inorder(TreeNode* root, int total) {
//    if (root == NULL) return; // 如果为空，直接返回
//    inorder(root->left, total); // 先遍历左子树
//    printf("%s %.4f%%\n", root->name, root->count * 100.0 / total); // 输出当前结点的名称和百分比，保留四位小数
//    inorder(root->right, total); // 再遍历右子树
//}
//
// 释放二叉搜索树占用的内存空间
//void freeTree(TreeNode* root) {
//    if (root == NULL) return; // 如果为空，直接返回
//    freeTree(root->left); // 先释放左子树
//    freeTree(root->right); // 再释放右子树
//    free(root); // 最后释放当前结点
//}
//
//int main() {
//    int N; // 树的数量
//    char name[31]; // 树种名称
//    TreeNode* root = NULL; // 二叉搜索树的根结点
//
//    printf("请输入树的数量：\n"); 
//    scanf("%d", &N); 
//
//    printf("请输入每棵树的种类名称：\n"); 
//    for (int i = 0; i < N; i++) { // 循环N次，输入每棵树的种类名称，并插入到二叉搜索树中
//        scanf("%s", name);
//        insert(&root, name);
//    }
//
//    printf("输出每种树的种类名称及其所占总数的百分比：\n"); // 输出提示
//    inorder(root, N); // 中序遍历二叉搜索树，并输出结果
//
//    freeTree(root); // 释放二叉搜索树占用的内存空间
//
//    return 0;
////}
//#include <stdio.h>
//
//#define N 8
//
//// 交换两个整数的值
//void swap(int* a, int* b) 
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// 简单选择排序
//void selectSort(int arr[], int n) 
//{
//    for (int i = 0; i < n - 1; i++) 
//    { // 外层循环控制选择次数，n-1次即可
//        int min = i; // 假设当前位置为最小值位置
//        for (int j = i + 1; j < n; j++) 
//        { // 内层循环从当前位置后面开始找更小的值
//            if (arr[j] < arr[min])
//            { // 如果找到更小的值，更新最小值位置
//                min = j;
//            }
//        }
//        if (min != i) { // 如果最小值位置发生变化，交换当前位置和最小值位置的元素
//            swap(&arr[i], &arr[min]);
//        }
//    }
//}
//
//// 插入排序
//void insertSort(int arr[], int n) 
//{
//    for (int i = 1; i < n; i++)
//    { // 外层循环控制插入次数，从第二个元素开始插入
//        int temp = arr[i]; // 保存当前元素的值
//        int j = i - 1; // 从当前元素前一个元素开始向前寻找插入位置
//        while (j >= 0 && arr[j] > temp) 
//        { // 如果前面的元素比当前元素大，就将其后移一位，直到找到比当前元素小或相等的元素或到达数组头部
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = temp; // 将当前元素插入到找到的位置后面
//    }
//}
//
//// 冒泡排序
//void bubbleSort(int arr[], int n) 
//{
//    for (int i = 0; i < n - 1; i++) 
//    { // 外层循环控制冒泡次数，n-1次即可
//        int flag = 0; // 设置一个标志变量，用来判断是否发生交换
//        for (int j = 0; j < n - 1 - i; j++) 
//        { // 内层循环从头开始比较相邻两个元素，如果前者大于后者，就交换它们，并将标志变量置为1
//            if (arr[j] > arr[j + 1]) 
//            {
//                swap(&arr[j], &arr[j + 1]);
//                flag = 1;
//            }
//        }
//        if (flag == 0) break; // 如果一趟冒泡没有发生交换，说明数组已经有序，可以提前结束循环
//    }
//}
//
//// 打印数组
//void printArray(int arr[], int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() 
//{
//    int arr[N] = { 9, 3, 7, 2, 6, 1, 5, 8 }; // 定义并初始化数组
//
//    printf("原始序列：\n");
//    printArray(arr, N); // 打印原始序列
//
//    printf("简单选择排序后：\n");
//    selectSort(arr, N); // 调用简单选择排序
//    printArray(arr, N); // 打印排序后的序列
//
//    printf("插入排序后：\n");
//    insertSort(arr, N); // 调用插入排序
//    printArray(arr, N); // 打印排序后的序列
//
//    printf("冒泡排序后：\n");
//    bubbleSort(arr, N); // 调用冒泡排序
//    printArray(arr, N); // 打印排序后的序列
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 定义队列结点结构体
//typedef struct Node {
//    int data; // 存储顾客编号
//    struct Node* next; // 指向下一个结点
//} Node;
//
//// 定义队列结构体
//typedef struct Queue {
//    Node* front; // 队首指针
//    Node* rear; // 队尾指针
//} Queue;
//
//// 创建一个新的队列，初始化其队首和队尾为空，并返回其指针
//Queue* newQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue)); // 分配内存空间
//    q->front = q->rear = NULL; // 初始化队首和队尾为空
//    return q;
//}
//
//// 判断一个队列是否为空，如果为空返回1，否则返回0
//int isEmpty(Queue* q) {
//    return q->front == NULL;
//}
//
//// 将一个元素入队到一个队列中，参数为队列指针和元素值
//void enqueue(Queue* q, int x) {
//    Node* node = (Node*)malloc(sizeof(Node)); // 创建一个新的结点，分配内存空间
//    node->data = x; // 存储元素值
//    node->next = NULL; // 初始化下一个指针为空
//    if (isEmpty(q)) { // 如果队列为空，新结点既是队首也是队尾
//        q->front = q->rear = node;
//    }
//    else { // 如果队列不为空，将新结点插入到队尾，并更新队尾指针
//        q->rear->next = node;
//        q->rear = node;
//    }
//}
//
//// 将一个元素出队从一个队列中，并返回其值，参数为队列指针
//int dequeue(Queue* q) {
//    if (isEmpty(q)) return -1; 
//    Node* node = q->front; 
//    int x = node->data; 
//    q->front = node->next; 
//    free(node); 
//    if (q->front == NULL) { 
//
//        q->rear = NULL;
//    }
//    return x; // 返回出队的元素值
//}
//
//// 释放一个队列占用的内存空间，参数为队列指针
//void freeQueue(Queue* q) {
//    while (!isEmpty(q)) { 
//        dequeue(q);
//    }
//    free(q); 
//}
//
//int main() {
//    int N; // 顾客总数
//    int id; // 顾客编号
//
//    Queue* A = newQueue(); // 创建A窗口的顾客编号队列
//    Queue* B = newQueue(); // 创建B窗口的顾客编号队列
//
//    printf("请输入顾客总数：\n"); // 输入提示
//    scanf("%d", &N); // 输入N
//
//    printf("请输入每个顾客的编号（奇数去A窗口，偶数去B窗口）：\n"); // 输入提示
//    for (int i = 0; i < N; i++) { // 循环N次，输入每个顾客的编号，并根据奇偶性入队到相应的窗口
//        scanf("%d", &id);
//        if (id % 2 == 1) { // 如果编号为奇数，入队到A窗口
//            enqueue(A, id);
//        }
//        else { // 如果编号为偶数，入队到B窗口
//            enqueue(B, id);
//        }
//    }
//
//    printf("按业务处理完成的顺序输出顾客的编号：\n"); // 输出提示
//    int count = 0; // 记录处理顾客的次数
//    while (!isEmpty(A) || !isEmpty(B)) { // 当两个窗口都不为空时，循环处理顾客
//        for (int i = 0; i < 2; i++) { // 每次从A窗口出队两个顾客（如果有），并输出他们的编号
//            id = dequeue(A);
//            if (id != -1) {
//                printf("%d", id);
//                count++;
//                if (count < N) printf(" "); // 如果不是最后一个编号，输出一个空格
//            }
//        }
//        id = dequeue(B); // 每次从B窗口出队一个顾客（如果有），并输出他们的编号
//        if (id != -1) {
//            printf("%d", id);
//            count++;
//            if (count < N) printf(" "); // 如果不是最后一个编号，输出一个空格
//        }
//    }
//    printf("\n"); // 输出换行符
//
//    freeQueue(A); // 释放A窗口的顾客编号队列占用的内存空间
//    freeQueue(B); // 释放B窗口的顾客编号队列占用的内存空间
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//// 定义队列长度
//#define MAXSIZE 1002
//
//// 定义队列结构体
//typedef struct Queue {
//    int data[MAXSIZE]; // 存储顾客编号
//    int front; // 队首位置
//    int rear; // 队尾位置
//} Queue;
//
//// 初始化一个队列，将其队首和队尾都置为0，并返回其指针
//Queue* initQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue)); // 分配内存空间
//    q->front = q->rear = 0; // 初始化队首和队尾为0
//    return q;
//}
//
//// 判断一个队列是否为空，如果为空返回1，否则返回0
//int isEmpty(Queue* q) {
//    return q->front == q->rear;
//}
//
//// 判断一个队列是否为满，如果为满返回1，否则返回0
//int isFull(Queue* q) {
//    return (q->rear + 1) % MAXSIZE == q->front;
//}
//
//// 将一个元素入队到一个队列中，参数为队列指针和元素值
//void enqueue(Queue* q, int x) {
//    if (isFull(q)) return; // 如果队列已满，直接返回
//    q->data[q->rear] = x; // 将元素值存储到队尾位置
//    q->rear = (q->rear + 1) % MAXSIZE; // 更新队尾位置，注意取模防止越界
//}
//
//// 将一个元素出队从一个队列中，并返回其值，参数为队列指针
//int dequeue(Queue* q) {
//    if (isEmpty(q)) return -1; // 如果队列为空，返回-1表示错误
//    int x = q->data[q->front]; // 保存要出队的元素值
//    q->front = (q->front + 1) % MAXSIZE; // 更新队首位置，注意取模防止越界
//    return x; // 返回出队的元素值
//}
//
//// 释放一个队列占用的内存空间，参数为队列指针
//void freeQueue(Queue* q) {
//    free(q); // 释放队列结构体占用的内存空间
//}
//
//int main() {
//    int N; // 顾客总数
//    int id; // 顾客编号
//
//    Queue* A = initQueue(); // 初始化A窗口的顾客编号队列
//    Queue* B = initQueue(); // 初始化B窗口的顾客编号队列
//
//    scanf("%d", &N); // 输入N
//
//    for (int i = 0; i < N; i++) { // 循环N次，输入每个顾客的编号，并根据奇偶性入队到相应的窗口
//        scanf("%d", &id);
//        if (id % 2 == 1) { // 如果编号为奇数，入队到A窗口
//            enqueue(A, id);
//        }
//        else { // 如果编号为偶数，入队到B窗口
//            enqueue(B, id);
//        }
//    }
//
//    int first = 1; // 设置一个标志变量，用来判断是否是第一个输出的编号
//    while (!isEmpty(A) || !isEmpty(B)) { // 当两个窗口都不为空时，循环处理顾客
//        for (int i = 0; i < 2; i++) { // 每次从A窗口出队两个顾客（如果有），并输出他们的编号
//            id = dequeue(A);
//            if (id != -1) {
//                if (first) { // 如果是第一个编号，直接输出
//                    printf("%d", id);
//                    first = 0; // 将标志变量置为0
//                }
//                else { // 如果不是第一个编号，先输出一个空格再输出
//                    printf(" %d", id);
//                }
//            }
//        }
//        id = dequeue(B); // 每次从B窗口出队一个顾客（如果有），并输出他们的编号
//        if (id != -1) {
//            if (first) { // 如果是第一个编号，直接输出
//                printf("%d", id);
//                first = 0; // 将标志变量置为0
//            }
//            else { // 如果不是第一个编号，先输出一个空格再输出
//                printf(" %d", id);
//            }
//        }
//    }
//    printf("\n"); // 输出换行符
//
//    freeQueue(A); // 释放A窗口的顾客编号队列占用的内存空间
//    freeQueue(B); // 释放B窗口的顾客编号队列占用的内存空间
//
//    return 0;
//}
