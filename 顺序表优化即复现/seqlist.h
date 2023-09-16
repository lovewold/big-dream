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

//头部插入和头部删除
void SLPushFront(SL* ps, SLDatEType x);
void SLPopFront(SL* ps);

//尾部插入和尾部删除
void SLPushBack(SL* ps, SLDatEType x);
void SLPopBack(SL* ps);

//检查容量
void SLCheckCapacity(SL* ps);

//顺序表查找
int SeqListFind(SL* ps, SLDatEType x);

//顺序表在pos位置插入
void SeqListIsert(SL* ps, int pos, SLDatEType x);
//顺序表在pos位置删除
void SeqListErase(SL* ps, int pos);

void PrintfList(SL* ps);