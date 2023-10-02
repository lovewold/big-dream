#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<malloc.h>

// ��ʽ�ṹ����ʾ���� 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;

}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);


// ��ʽ�ṹ����ʾ���� 



// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
	q->size = 0;

}
// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
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
// ���ٶ��� 
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
	if (!QueueEmpty(&obj->q1))//����һ������Ϊ�վͲ�����һ��
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