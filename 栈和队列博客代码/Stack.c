#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

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
		int newcapacity = ps->capacity == 0 ? 4 :ps->capacity*2;
		STDataType* new = (STDataType*)realloc(ps->a,sizeof(STDataType)*newcapacity);
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
	return ps->a[ps->top-1];
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
