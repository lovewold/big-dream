#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void InsertSort(int* a, int n)
{
	for (int size = 0; size < n-1; size++)
	{
		int end = size;//从第一位开始，但是不插入
		int tmp = a[end + 1];//保留要插入的序列末尾值
		while (end >= 0)//往前找 9 =8= 7 6 5 4 3 2 1 0-> :  =8= 9 7 6 5 4 3 2 1 0   
		{
			if (tmp < a[end])  
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end+gap] = tmp;

		}
	}

}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[mini] < a[i])
			{
				mini = i;
			}
			if (a[maxi] > a[i])
			{
				maxi = i;
			}
		}
		Swap(&a[mini], &a[begin]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[begin]);
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	assert(a);
	int child = (parent) * 2 + 1;//索引找孩子节点
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])//子节点小于父节点，则交换
		{
			Swap(&a[child], &a[parent]);//用于交换自定义函数
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, n, 0);
		end--;
	}
}

