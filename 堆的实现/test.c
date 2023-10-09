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
// //����д����ȱ�㣺
// //1������һ���ѵ����ݽṹ
// //2���ռ临�Ӷȸ��Ӷȵ�����
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
//// ����
//void HeapSort(int* a, int n)
//{
//	 /*���ϵ������� ����ѣ�or  ��С�ѣ�
//	 O(N*logN)*/
//	for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}
//
//	 //���µ�������
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
//	// 1. ����--��a��ǰk��Ԫ�ؽ���
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
//	// ǰk������С��
//	for (int i = (k - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(minheap, k, i);
//	}
//
//
//	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
//	int x = 0;
//	while (fscanf(fout, "%d", &x) != EOF)
//	{
//		if (x > minheap[0])
//		{
//			// �滻�����
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
//	// ������
//	int n = 10000000;//����һ��ǧ�򼶱������
//	srand(time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");//���ļ�
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		int x = (rand() + i) % 10000000;//���ֵ
//		fprintf(fin, "%d\n", x);//д���ļ�
//	}
//
//	fclose(fin);//�ر��ļ�
//}
//
//int main()
//{
//	//CreateNDate();
//	PrintTopK("data.txt", 100);//Top-100
//
//	return 0;
//}