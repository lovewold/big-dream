#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	assert(a);
	
	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hp->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	hp->capacity = n;
	hp->size = n;
	memcpy(hp->a, a, sizeof(HPDataType) * n);

	for (int i = 0; i < n; i++)
	{
		AdjustUp(hp->a, i);
	}
}
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	int child = (parent) * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity==0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	return hp->a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

void HeapPrint(Heap* hp)
{
	assert(hp);

	for (size_t i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}