#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

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