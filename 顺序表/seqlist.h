#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//#define N 1000
////��̬˳���
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

//�������ݣ�����ɾ�����Ҹı�
void SLinit(SL *ps);
void SLDestroy(SL* ps);

//β��βɾ
void SLPushback(SL* ps,SLDatEType x);
void SLPopback(SL* ps);

//ͷ��ͷɾ
void SLPushFront(SL* ps,SLDatEType x);
void SLPopFront(SL* ps);
void Print(SL* ps);

//�������
void SLCheckCapacity(SL* ps);

void test1();
void test2();
// ˳������
int SeqListFind(SL* ps, SLDatEType x);
// ˳�����posλ�ò���x
void SeqListInsert(SL* ps, int pos, SLDatEType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL* ps, int pos);
