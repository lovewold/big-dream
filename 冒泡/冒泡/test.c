#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10];
	int i = 0;
	int temp = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int j = 0;
	
	for (i = 0; i < 9; i++)
	{
		int count = 1;
		for (j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				count = 0;
			}
			
		}
		if (count == 1)//当没有交换元素可以直接跳出排序
		{
			break;
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}