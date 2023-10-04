#pragma once
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;


//���϶��µ���
void AdjustUp(HPDataType* a, int child);
//���¶��ϵ���
void AdjustDown(HPDataType* a, int n, int parent);
//�ѵĳ�ʼ��
void HeapInit(Heap* hp);
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
//����
void Swap(HPDataType* a, HPDataType* b);
//��ӡ
void HeapPrint(Heap* hp);