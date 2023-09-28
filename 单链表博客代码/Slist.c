#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
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
	while (plist)
	{
		printf("%d->",plist->data);//������-->��ͷֻ��Ϊ�˱����������ӵ����۹�ϵ
		plist = plist->next;//��������ʵ���Ͼ����ýڵ�ﵽ��һ��λ�ã��ٷ��ʽڵ�����
	}
	printf("NULL\n");//ͬ����������NULL�������������ȫ����������⡣
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	struct SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		struct  SListNode* tail = *pplist;
		while(tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
	
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	struct SListNode* newNode = BuySListNode(x);
	newNode->next = *pplist;
	*pplist = newNode;//����ͷ�ڵ�
}
void SListPopBack(SListNode** pplist)
{
	//û�нڵ�
	assert(pplist);
	assert(*pplist);
	//һ���ڵ�
	if((*pplist)->next==NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//����ڵ�
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next)//��β�ڵ�ǰһ��
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
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
		else
			tail = tail->next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* posNext = pos->next;
	pos = posNext->next;
	free(posNext);
	posNext = NULL;
}
void SListErase(SListNode* pos)
{
	assert(pos);
	if (pos->next != NULL)
	{
		SListNode* posNext = pos->next;
		pos->data = posNext->data;
		pos->next = posNext->next;
		free(posNext);
		posNext = NULL;
	}
	else
	{
		free(pos);
		pos = NULL;
	}
}
void SListDestroy(SListNode** pplist)//����ͷɾ��һ�����̣������һ���ڵ�ռ��ͷż�����
{
	//��������ֻ��Ҫ����ͷɾ����
	while (*pplist)
	{
		SListPopFront(pplist);
		*pplist = (*pplist)->next;
	}
}

