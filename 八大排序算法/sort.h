#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
//¥Ú”°
void PrintArray(int* a, int n);
 
//Ωªªª
void Swap(int* x, int* y);

// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n);


// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root);
//
void HeapSort(int* a, int n);
