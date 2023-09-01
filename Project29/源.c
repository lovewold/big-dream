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
                { =
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

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
// ���������ṹ��
//typedef struct TreeNode {
//    char name[31]; // ��������
//    int count; // ��������
//    struct TreeNode* left; // ������ָ��
//    struct TreeNode* right; // ������ָ��
//} TreeNode;
//
// ����һ���µ�����㣬��ʼ�������ƺ���������������ָ��
//TreeNode* newNode(char* name) {
//    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // �����ڴ�ռ�
//    strcpy(node->name, name); 
//    node->count = 1; // ��ʼ������Ϊ1
//    node->left = node->right = NULL; // ��ʼ����������Ϊ��
//    return node;
//}
//
// ��һ���������Ʋ��뵽�����������У�����Ѵ��������������������򴴽��½��
//void insert(TreeNode** root, char* name) {
//    if (*root == NULL) { // ��������Ϊ�գ�˵���ǿ�����ֱ�Ӵ����½����Ϊ�����
//        *root = newNode(name);
//        return;
//    }
//    int cmp = strcmp(name, (*root)->name); 
//    if (cmp == 0) { // �����ȣ�˵���ҵ�����ͬ�����֣�����������
//        (*root)->count++;
//    }
//    else if (cmp < 0) { // ���С�ڣ�˵��Ҫ������������ֵ������ڸ����֮ǰ���ݹ���뵽��������
//        insert(&(*root)->left, name);
//    }
//    else { // ������ڣ�˵��Ҫ������������ֵ������ڸ����֮�󣬵ݹ���뵽��������
//        insert(&(*root)->right, name);
//    }
//}
//
// ������������������������ÿ���������ƺͰٷֱ�
//void inorder(TreeNode* root, int total) {
//    if (root == NULL) return; // ���Ϊ�գ�ֱ�ӷ���
//    inorder(root->left, total); // �ȱ���������
//    printf("%s %.4f%%\n", root->name, root->count * 100.0 / total); // �����ǰ�������ƺͰٷֱȣ�������λС��
//    inorder(root->right, total); // �ٱ���������
//}
//
// �ͷŶ���������ռ�õ��ڴ�ռ�
//void freeTree(TreeNode* root) {
//    if (root == NULL) return; // ���Ϊ�գ�ֱ�ӷ���
//    freeTree(root->left); // ���ͷ�������
//    freeTree(root->right); // ���ͷ�������
//    free(root); // ����ͷŵ�ǰ���
//}
//
//int main() {
//    int N; // ��������
//    char name[31]; // ��������
//    TreeNode* root = NULL; // �����������ĸ����
//
//    printf("����������������\n"); 
//    scanf("%d", &N); 
//
//    printf("������ÿ�������������ƣ�\n"); 
//    for (int i = 0; i < N; i++) { // ѭ��N�Σ�����ÿ�������������ƣ������뵽������������
//        scanf("%s", name);
//        insert(&root, name);
//    }
//
//    printf("���ÿ�������������Ƽ�����ռ�����İٷֱȣ�\n"); // �����ʾ
//    inorder(root, N); // ���������������������������
//
//    freeTree(root); // �ͷŶ���������ռ�õ��ڴ�ռ�
//
//    return 0;
////}
//#include <stdio.h>
//
//#define N 8
//
//// ��������������ֵ
//void swap(int* a, int* b) 
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// ��ѡ������
//void selectSort(int arr[], int n) 
//{
//    for (int i = 0; i < n - 1; i++) 
//    { // ���ѭ������ѡ�������n-1�μ���
//        int min = i; // ���赱ǰλ��Ϊ��Сֵλ��
//        for (int j = i + 1; j < n; j++) 
//        { // �ڲ�ѭ���ӵ�ǰλ�ú��濪ʼ�Ҹ�С��ֵ
//            if (arr[j] < arr[min])
//            { // ����ҵ���С��ֵ��������Сֵλ��
//                min = j;
//            }
//        }
//        if (min != i) { // �����Сֵλ�÷����仯��������ǰλ�ú���Сֵλ�õ�Ԫ��
//            swap(&arr[i], &arr[min]);
//        }
//    }
//}
//
//// ��������
//void insertSort(int arr[], int n) 
//{
//    for (int i = 1; i < n; i++)
//    { // ���ѭ�����Ʋ���������ӵڶ���Ԫ�ؿ�ʼ����
//        int temp = arr[i]; // ���浱ǰԪ�ص�ֵ
//        int j = i - 1; // �ӵ�ǰԪ��ǰһ��Ԫ�ؿ�ʼ��ǰѰ�Ҳ���λ��
//        while (j >= 0 && arr[j] > temp) 
//        { // ���ǰ���Ԫ�رȵ�ǰԪ�ش󣬾ͽ������һλ��ֱ���ҵ��ȵ�ǰԪ��С����ȵ�Ԫ�ػ򵽴�����ͷ��
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = temp; // ����ǰԪ�ز��뵽�ҵ���λ�ú���
//    }
//}
//
//// ð������
//void bubbleSort(int arr[], int n) 
//{
//    for (int i = 0; i < n - 1; i++) 
//    { // ���ѭ������ð�ݴ�����n-1�μ���
//        int flag = 0; // ����һ����־�����������ж��Ƿ�������
//        for (int j = 0; j < n - 1 - i; j++) 
//        { // �ڲ�ѭ����ͷ��ʼ�Ƚ���������Ԫ�أ����ǰ�ߴ��ں��ߣ��ͽ������ǣ�������־������Ϊ1
//            if (arr[j] > arr[j + 1]) 
//            {
//                swap(&arr[j], &arr[j + 1]);
//                flag = 1;
//            }
//        }
//        if (flag == 0) break; // ���һ��ð��û�з���������˵�������Ѿ����򣬿�����ǰ����ѭ��
//    }
//}
//
//// ��ӡ����
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
//    int arr[N] = { 9, 3, 7, 2, 6, 1, 5, 8 }; // ���岢��ʼ������
//
//    printf("ԭʼ���У�\n");
//    printArray(arr, N); // ��ӡԭʼ����
//
//    printf("��ѡ�������\n");
//    selectSort(arr, N); // ���ü�ѡ������
//    printArray(arr, N); // ��ӡ����������
//
//    printf("���������\n");
//    insertSort(arr, N); // ���ò�������
//    printArray(arr, N); // ��ӡ����������
//
//    printf("ð�������\n");
//    bubbleSort(arr, N); // ����ð������
//    printArray(arr, N); // ��ӡ����������
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// ������н��ṹ��
//typedef struct Node {
//    int data; // �洢�˿ͱ��
//    struct Node* next; // ָ����һ�����
//} Node;
//
//// ������нṹ��
//typedef struct Queue {
//    Node* front; // ����ָ��
//    Node* rear; // ��βָ��
//} Queue;
//
//// ����һ���µĶ��У���ʼ������׺Ͷ�βΪ�գ���������ָ��
//Queue* newQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue)); // �����ڴ�ռ�
//    q->front = q->rear = NULL; // ��ʼ�����׺Ͷ�βΪ��
//    return q;
//}
//
//// �ж�һ�������Ƿ�Ϊ�գ����Ϊ�շ���1�����򷵻�0
//int isEmpty(Queue* q) {
//    return q->front == NULL;
//}
//
//// ��һ��Ԫ����ӵ�һ�������У�����Ϊ����ָ���Ԫ��ֵ
//void enqueue(Queue* q, int x) {
//    Node* node = (Node*)malloc(sizeof(Node)); // ����һ���µĽ�㣬�����ڴ�ռ�
//    node->data = x; // �洢Ԫ��ֵ
//    node->next = NULL; // ��ʼ����һ��ָ��Ϊ��
//    if (isEmpty(q)) { // �������Ϊ�գ��½����Ƕ���Ҳ�Ƕ�β
//        q->front = q->rear = node;
//    }
//    else { // ������в�Ϊ�գ����½����뵽��β�������¶�βָ��
//        q->rear->next = node;
//        q->rear = node;
//    }
//}
//
//// ��һ��Ԫ�س��Ӵ�һ�������У���������ֵ������Ϊ����ָ��
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
//    return x; // ���س��ӵ�Ԫ��ֵ
//}
//
//// �ͷ�һ������ռ�õ��ڴ�ռ䣬����Ϊ����ָ��
//void freeQueue(Queue* q) {
//    while (!isEmpty(q)) { 
//        dequeue(q);
//    }
//    free(q); 
//}
//
//int main() {
//    int N; // �˿�����
//    int id; // �˿ͱ��
//
//    Queue* A = newQueue(); // ����A���ڵĹ˿ͱ�Ŷ���
//    Queue* B = newQueue(); // ����B���ڵĹ˿ͱ�Ŷ���
//
//    printf("������˿�������\n"); // ������ʾ
//    scanf("%d", &N); // ����N
//
//    printf("������ÿ���˿͵ı�ţ�����ȥA���ڣ�ż��ȥB���ڣ���\n"); // ������ʾ
//    for (int i = 0; i < N; i++) { // ѭ��N�Σ�����ÿ���˿͵ı�ţ���������ż����ӵ���Ӧ�Ĵ���
//        scanf("%d", &id);
//        if (id % 2 == 1) { // ������Ϊ��������ӵ�A����
//            enqueue(A, id);
//        }
//        else { // ������Ϊż������ӵ�B����
//            enqueue(B, id);
//        }
//    }
//
//    printf("��ҵ������ɵ�˳������˿͵ı�ţ�\n"); // �����ʾ
//    int count = 0; // ��¼����˿͵Ĵ���
//    while (!isEmpty(A) || !isEmpty(B)) { // ���������ڶ���Ϊ��ʱ��ѭ������˿�
//        for (int i = 0; i < 2; i++) { // ÿ�δ�A���ڳ��������˿ͣ�����У�����������ǵı��
//            id = dequeue(A);
//            if (id != -1) {
//                printf("%d", id);
//                count++;
//                if (count < N) printf(" "); // ����������һ����ţ����һ���ո�
//            }
//        }
//        id = dequeue(B); // ÿ�δ�B���ڳ���һ���˿ͣ�����У�����������ǵı��
//        if (id != -1) {
//            printf("%d", id);
//            count++;
//            if (count < N) printf(" "); // ����������һ����ţ����һ���ո�
//        }
//    }
//    printf("\n"); // ������з�
//
//    freeQueue(A); // �ͷ�A���ڵĹ˿ͱ�Ŷ���ռ�õ��ڴ�ռ�
//    freeQueue(B); // �ͷ�B���ڵĹ˿ͱ�Ŷ���ռ�õ��ڴ�ռ�
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//// ������г���
//#define MAXSIZE 1002
//
//// ������нṹ��
//typedef struct Queue {
//    int data[MAXSIZE]; // �洢�˿ͱ��
//    int front; // ����λ��
//    int rear; // ��βλ��
//} Queue;
//
//// ��ʼ��һ�����У�������׺Ͷ�β����Ϊ0����������ָ��
//Queue* initQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue)); // �����ڴ�ռ�
//    q->front = q->rear = 0; // ��ʼ�����׺Ͷ�βΪ0
//    return q;
//}
//
//// �ж�һ�������Ƿ�Ϊ�գ����Ϊ�շ���1�����򷵻�0
//int isEmpty(Queue* q) {
//    return q->front == q->rear;
//}
//
//// �ж�һ�������Ƿ�Ϊ�������Ϊ������1�����򷵻�0
//int isFull(Queue* q) {
//    return (q->rear + 1) % MAXSIZE == q->front;
//}
//
//// ��һ��Ԫ����ӵ�һ�������У�����Ϊ����ָ���Ԫ��ֵ
//void enqueue(Queue* q, int x) {
//    if (isFull(q)) return; // �������������ֱ�ӷ���
//    q->data[q->rear] = x; // ��Ԫ��ֵ�洢����βλ��
//    q->rear = (q->rear + 1) % MAXSIZE; // ���¶�βλ�ã�ע��ȡģ��ֹԽ��
//}
//
//// ��һ��Ԫ�س��Ӵ�һ�������У���������ֵ������Ϊ����ָ��
//int dequeue(Queue* q) {
//    if (isEmpty(q)) return -1; // �������Ϊ�գ�����-1��ʾ����
//    int x = q->data[q->front]; // ����Ҫ���ӵ�Ԫ��ֵ
//    q->front = (q->front + 1) % MAXSIZE; // ���¶���λ�ã�ע��ȡģ��ֹԽ��
//    return x; // ���س��ӵ�Ԫ��ֵ
//}
//
//// �ͷ�һ������ռ�õ��ڴ�ռ䣬����Ϊ����ָ��
//void freeQueue(Queue* q) {
//    free(q); // �ͷŶ��нṹ��ռ�õ��ڴ�ռ�
//}
//
//int main() {
//    int N; // �˿�����
//    int id; // �˿ͱ��
//
//    Queue* A = initQueue(); // ��ʼ��A���ڵĹ˿ͱ�Ŷ���
//    Queue* B = initQueue(); // ��ʼ��B���ڵĹ˿ͱ�Ŷ���
//
//    scanf("%d", &N); // ����N
//
//    for (int i = 0; i < N; i++) { // ѭ��N�Σ�����ÿ���˿͵ı�ţ���������ż����ӵ���Ӧ�Ĵ���
//        scanf("%d", &id);
//        if (id % 2 == 1) { // ������Ϊ��������ӵ�A����
//            enqueue(A, id);
//        }
//        else { // ������Ϊż������ӵ�B����
//            enqueue(B, id);
//        }
//    }
//
//    int first = 1; // ����һ����־�����������ж��Ƿ��ǵ�һ������ı��
//    while (!isEmpty(A) || !isEmpty(B)) { // ���������ڶ���Ϊ��ʱ��ѭ������˿�
//        for (int i = 0; i < 2; i++) { // ÿ�δ�A���ڳ��������˿ͣ�����У�����������ǵı��
//            id = dequeue(A);
//            if (id != -1) {
//                if (first) { // ����ǵ�һ����ţ�ֱ�����
//                    printf("%d", id);
//                    first = 0; // ����־������Ϊ0
//                }
//                else { // ������ǵ�һ����ţ������һ���ո������
//                    printf(" %d", id);
//                }
//            }
//        }
//        id = dequeue(B); // ÿ�δ�B���ڳ���һ���˿ͣ�����У�����������ǵı��
//        if (id != -1) {
//            if (first) { // ����ǵ�һ����ţ�ֱ�����
//                printf("%d", id);
//                first = 0; // ����־������Ϊ0
//            }
//            else { // ������ǵ�һ����ţ������һ���ո������
//                printf(" %d", id);
//            }
//        }
//    }
//    printf("\n"); // ������з�
//
//    freeQueue(A); // �ͷ�A���ڵĹ˿ͱ�Ŷ���ռ�õ��ڴ�ռ�
//    freeQueue(B); // �ͷ�B���ڵĹ˿ͱ�Ŷ���ռ�õ��ڴ�ռ�
//
//    return 0;
//}
