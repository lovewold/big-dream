#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

int PartSort2(int* a, int left, int right)
{
	//��ʼ��λ
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//��λ������������С�ڿ�λ��
		while (a[right] >= key && left < right)
		{
			right--;
		}
		a[left] = a[right];
		hole = right;
		//��λ�����������Ҵ��ڿ�λ��
		while (a[left] <= key && left < right)
		{
			left++;
		}
		a[right] = a[left];
		hole = left;

	}
	a[left] = key;

	return hole;

}

int PartSort3(int* a, int left, int right)
{
	int prev = left;
	int cur = left+1;
	int key = left;
	while (cur <right)
	{
		cur++;
		if (a[cur] < a[key]&&++prev!=cur)
		{
			Swap(&a[prev], &a[cur]);
		}

	}
	Swap(&a[key], &a[prev]);
	return prev;
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//InsertSort(arr, sizeof(arr) / sizeof(int));
	//ShellSort(arr, sizeof(arr) / sizeof(int));
	//HeapSort(arr, sizeof(arr) / sizeof(int));
	//SelectSort(arr, sizeof(arr) / sizeof(int));
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	
	PrintArray(arr,sizeof(arr) / sizeof(int));
	return 0;
}