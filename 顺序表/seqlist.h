#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//#define N 1000
////静态顺序表
//typedef int SLDatEType;
//
//struct SeqList
//{
//	SLDatEType a[N];
//	int size;
//};

typedef int SLDatEType;

typedef struct  SeqList
{
	SLDatEType* a;
	int size;
	int capacity;
}SL;

//管理数据，增加删除查找改变
void SLinit(SL *ps);
void SLDestroy(SL* ps);

//尾插尾删
void SLPushback(SL* ps,SLDatEType x);
void SLPopback(SL* ps);

//头插头删
void SLPushFront(SL* ps,SLDatEType x);
void SLPopFront(SL* ps);
void Print(SL* ps);

//检查容量
void SLCheckCapacity(SL* ps);

void test1();
void test2();
// 顺序表查找
int SeqListFind(SL* ps, SLDatEType x);
// 顺序表在pos位置插入x
void SeqListInsert(SL* ps, int pos, SLDatEType x);
// 顺序表删除pos位置的值
void SeqListErase(SL* ps, int pos);
