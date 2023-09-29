#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

ListNode* BuyLTnewNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}
ListNode* ListCreate()
{
	ListNode* phead = BuyLTnewNode(-1);
	phead->prev = phead;
	phead->next = phead;

	return phead;
}
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	printf("pHead<=>");
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d<=>",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newNode = BuyLTnewNode(x);
	ListNode* tail = pos->prev;
	newNode->next = pos;
	pos->prev=newNode;
	
	tail->next = newNode;
	newNode->prev = tail;
}
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead->next);
	ListInsert(pHead->next, x);
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->next);
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->prev);
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* first = pos->prev;
	ListNode* seconed = pos->next;
	first->next = seconed;
	seconed->prev = first;
	free(pos);

}
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	while (pHead->next != pHead)
	{
		ListPopBack(pHead);
	}
}
