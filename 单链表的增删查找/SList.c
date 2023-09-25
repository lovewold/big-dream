#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

SListNode* BuySListNode(SLTDateType x)
{
	 SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode==NULL)
	{
		perror("malloc fail\n");
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else//find back
	{
		SListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	assert(*pplist);
	SListNode * newNode = BuySListNode(x);
	newNode->next = *pplist; 
	*pplist = newNode;
}

void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	//û�нڵ�
	assert(*pplist);
	//һ���ڵ�
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//����ڵ�
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next!=NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* tail = *pplist;
	*pplist = tail->next;
	free(tail);
	tail = NULL;
}
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* tail = plist;
	while (tail)
	{
		if (tail->data == x)
		{
			return tail;
		}
		tail = tail->next;
	}
	printf("No find %d\n", x);
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->next = pos->next;
	newNode->data = x;
	pos->next = newNode;
	return 0;
}
//void SListEraseAfter(SListNode* pos)
//{
//	assert(pos);
//	assert(pos->next);
//	SListNode* tail = pos->next->next;
//	free(pos->next);
//	pos->next = tail;
//
//}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* posNext = pos->next;
	pos->next = posNext->next;
	free(posNext);
	posNext = NULL;
}
void SListDestroy(SListNode** pplist)
{
	//���plist�Ƿ�Ϊ��ָ��
	if (pplist == NULL)
	{
		return;
	}
	//���������ͷ�ÿ���ڵ�
	SListNode* tail = *pplist;
	while (tail != NULL)
	{
		SListNode* next = tail->next;
		free(tail);
		tail = next;
	}
	//��plistָ�븳ֵΪNULL����������ָ��
	*pplist = NULL;
}



