#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[] = { 43,82,76,22,15,16,2,-1,-72,100 };
	int i = 0;
	int j = 0;
	int a = 0;



	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				a = arr[j + 1];

				arr[j + 1] = arr[j];
				arr[j] = a;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}