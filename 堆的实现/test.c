#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

//
//int main()
//{
//	//int a[] = { 65,100,70,32,50,60 };
//	int a[] = { 2,3,5,7,4,6,8,65,100,70,32,50,60 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	HeapPrint(&hp);
//
//	int k = 5;
//	while (!HeapEmpty(&hp) && k--)
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//
//	return 0;
//}
//
// //这种写法的缺点：
// //1、先有一个堆的数据结构
// //2、空间复杂度复杂度的消耗
//void HeapSort(int* a, int n)
//{
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	
//	int i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		//printf("%d ", HeapTop(&hp));
//		a[i++] = HeapTop(&hp);
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}
//
//// 升序
//void HeapSort(int* a, int n)
//{
//	 /*向上调整建堆 （大堆）or  （小堆）
//	 O(N*logN)*/
//	for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}
//
//	 //向下调整建堆
//	 //O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	/* O(N*logN)*/
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}

//}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	//int a[] = { 65,100,70,32,50,60 };
	//int a[] = { 9,3,4,5,1,2,3,123,143,3,12 };
	////int a[] = { 70, 65, 100, 32, 50, 60 };
 	int a[] = { 2,3,5,7,4,6,8 };
	HeapSort(a, sizeof(a) / sizeof(int));
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return 0;
}
////
////////////////////////////////////////////////////////////////////////////////////////////////////
//void PrintTopK(const char* filename, int k)
//{
//	// 1. 建堆--用a中前k个元素建堆
//	FILE* fout = fopen(filename, "r");
//	if (fout == NULL)
//	{
//		perror("fopen fail");
//		return;
//	}
//
//	int* minheap = (int*)malloc(sizeof(int) * k);
//	if (minheap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fout, "%d", &minheap[i]);
//	}
//
//	// 前k个数建小堆
//	for (int i = (k - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(minheap, k, i);
//	}
//
//
//	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
//	int x = 0;
//	while (fscanf(fout, "%d", &x) != EOF)
//	{
//		if (x > minheap[0])
//		{
//			// 替换你进堆
//			minheap[0] = x;
//			AdjustDown(minheap, k, 0);
//		}
//	}
//
//
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", minheap[i]);
//	}
//	printf("\n");
//
//	free(minheap);
//	fclose(fout);
//}
//
//// fprintf  fscanf
//
//void CreateNDate()
//{
//	// 造数据
//	int n = 10000000;//造了一个千万级别的数据
//	srand(time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");//打开文件
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		int x = (rand() + i) % 10000000;//随机值
//		fprintf(fin, "%d\n", x);//写入文件
//	}
//
//	fclose(fin);//关闭文件
//}
//
//int main()
//{
//	//CreateNDate();
//	PrintTopK("data.txt", 100);//Top-100
//
//	return 0;
//}