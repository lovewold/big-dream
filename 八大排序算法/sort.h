#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
//��ӡ
void PrintArray(int* a, int n);
 
//����
void Swap(int* x, int* y);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);


// ������
void AdjustDwon(int* a, int n, int root);
//
void HeapSort(int* a, int n);
