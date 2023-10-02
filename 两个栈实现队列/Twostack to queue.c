#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<malloc.h>

// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// ջ��
	int capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, STDataType data);
// ��ջ 
void StackPop(Stack* ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);


// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;

}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* new = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (new == NULL)
		{
			perror("realoc fail\n");
			exit(-1);
		}
		ps->a = new;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	--ps->top;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return 1;//tureΪ��
	}
	else
	{
		return 0;
	}
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

typedef struct
{
	Stack q1;
	Stack q2;
} MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* new = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&new->q1);
	StackInit(&new->q2);
	return new;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->q1, x);
}

int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->q2))
	{
		while (!StackEmpty(&obj->q1))
		{
			StackPush(&obj->q2, StackTop(&obj->q1));
			StackPop(&obj->q1);
		}

	}
	int top = StackTop(&obj->q2);
	StackPop(&obj->q2);
	return top;
}

int myQueuePeek(MyQueue* obj)
{
	if (StackEmpty(&obj->q2))
	{
		while (!StackEmpty(&obj->q1))
		{
			StackPush(&obj->q2, StackTop(&obj->q1));
			StackPop(&obj->q1);
		}
	}
	return StackTop(&obj->q2);
}

bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->q1) && StackEmpty(&obj->q2);

}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->q1);
	StackDestroy(&obj->q2);
	free(obj);

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/