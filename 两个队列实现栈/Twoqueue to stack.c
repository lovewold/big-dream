#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<malloc.h>

// 链式结构：表示队列 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;

}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);


// 链式结构：表示队列 



// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
	q->size = 0;

}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;
	if (q->front == NULL)
	{
		q->front = q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QNode* tail = q->front->next;
		free(q->front);
		q->front = tail;
	}

	q->size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);

	if (q->front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}

typedef struct
{
	Queue q1;
	Queue q2;

} MyStack;


MyStack* myStackCreate()
{
	MyStack* new = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&new->q1);
	QueueInit(&new->q2);
	return new;
}

void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj)
{
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))//看那一个队列为空就操作哪一个
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	int top = QueueFront(nonempty);
	QueuePop(nonempty);
	return top;
}
int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}

}

bool myStackEmpty(MyStack* obj)
{

	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);

}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/