#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Queue.h"
void test1()
{
	Stack ST;
	StackInit(&ST);
	StackPush(&ST, 1);
	StackPush(&ST, 2);
	StackPush(&ST, 3);
	StackPush(&ST, 4);
	StackPush(&ST, 5);
	StackPush(&ST, 6);
	while (!StackEmpty(&ST))
	{
		printf("%d  ջ��ЧԪ�ظ���%d\n",StackTop(&ST),StackSize(&ST));
		StackPop(&ST);
	}
	printf("ջ��ЧԪ�ظ���%d\n", StackSize(&ST));
	StackDestroy(&ST);
}
void test2()
{
	QNode qT;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	while (!QueueEmpty(&q))
	{
		printf("%d  ������ЧԪ�ظ���%d\n", QueueFront(&q), QueueSize(&q));
		QueuePop(&q);
	}
	printf("������ЧԪ�ظ���%d\n",QueueSize(&q));
	QueueDestroy(&q);
}
int main()
{
	test1();
	test2();
	return 0;
}