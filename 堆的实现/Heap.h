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


//自上而下调整
void AdjustUp(HPDataType* a, int child);
//自下而上调整
void AdjustDown(HPDataType* a, int n, int parent);
//堆的初始化
void HeapInit(Heap* hp);
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
//交换
void Swap(HPDataType* a, HPDataType* b);
//打印
void HeapPrint(Heap* hp);