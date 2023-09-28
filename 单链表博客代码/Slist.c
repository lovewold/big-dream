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
		printf("%d->",plist->data);//这里用-->箭头只是为了表述这种连接的理论关系
		plist = plist->next;//遍历操作实际上就是让节点达到下一个位置，再访问节点内容
	}
	printf("NULL\n");//同样的这里用NULL表述链表遍历完全，更容易理解。
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
	*pplist = newNode;//更新头节点
}
void SListPopBack(SListNode** pplist)
{
	//没有节点
	assert(pplist);
	assert(*pplist);
	//一个节点
	if((*pplist)->next==NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//多个节点
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next)//找尾节点前一个
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
void SListDestroy(SListNode** pplist)//遍历头删的一个过程，当最后一个节点空间释放即结束
{
	//这里我们只需要复用头删即可
	while (*pplist)
	{
		SListPopFront(pplist);
		*pplist = (*pplist)->next;
	}
}

