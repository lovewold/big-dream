#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<malloc.h>

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// 栈顶
	int capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps);
// 入栈 
void StackPush(Stack* ps, STDataType data);
// 出栈 
void StackPop(Stack* ps);
// 获取栈顶元素 
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数 
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);
// 销毁栈 
void StackDestroy(Stack* ps);


// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;

}
// 入栈 
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
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	--ps->top;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return 1;//ture为空
	}
	else
	{
		return 0;
	}
}
// 销毁栈 
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