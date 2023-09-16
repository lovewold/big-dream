#pragma once
#include"seqlist.h"

void SLinit(SL* ps)
{
	ps->a = (SLDatEType*)malloc(sizeof(SLDatEType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;

}
void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SLPushback(SL* ps, SLDatEType x)
{
	//检查是否满。满了需要扩容
	SLCheckCapacity(ps);
}
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDatEType* tem = (SLDatEType*)realloc(ps->a, ps->capacity * 2 * (sizeof(SLDatEType)));
		if (tem == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		ps->a = tem;
		ps->capacity *= 2;
	}
}
void SLPushFront(SL* ps, SLDatEType x)
{
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
void SLPopFront(SL* ps)
{
	assert(ps->size > 0);
	int i = 0;
	while (i < ps->size)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}
void SLPushBack(SL* ps,SLDatEType x)
{
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SLPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}
int SeqListFind(SL* ps, SLDatEType x)
{
	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

void SeqListIsert(SL* ps, int pos, SLDatEType x)
{
	SLCheckCapacity(ps);
	assert(pos >= 0 && pos <= ps->size - 1);
	int i = ps->size-1;
	for (i=ps->size-1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos <= ps->size - 1);
	int i = 0;
	for (i = pos; i <= ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void PrintfList(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d->", ps->a[i]);
	}
}