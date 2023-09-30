#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void STInit(ST* ps)
{
	assert(ps);
	ps->top = 0;
	ps->a = NULL;
	ps->capcity = 0;
}
void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capcity = 0;
}
void STpush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capcity)
	{
		int newCapacity = ps->capcity == 0 ? 4 : ps->capcity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capcity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void STPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	--ps->top;
}
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}
int STsize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
