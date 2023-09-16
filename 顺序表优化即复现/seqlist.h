#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatEType;

typedef struct SeqList
{
	SLDatEType* a;
	int size;
	int capacity;
}SL;

void SLinit(SL* ps);
void SLDestroy(SL* ps);

//ͷ�������ͷ��ɾ��
void SLPushFront(SL* ps, SLDatEType x);
void SLPopFront(SL* ps);

//β�������β��ɾ��
void SLPushBack(SL* ps, SLDatEType x);
void SLPopBack(SL* ps);

//�������
void SLCheckCapacity(SL* ps);

//˳������
int SeqListFind(SL* ps, SLDatEType x);

//˳�����posλ�ò���
void SeqListIsert(SL* ps, int pos, SLDatEType x);
//˳�����posλ��ɾ��
void SeqListErase(SL* ps, int pos);

void PrintfList(SL* ps);