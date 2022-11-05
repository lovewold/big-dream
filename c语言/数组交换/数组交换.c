#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr1[10] = { 0 };
	int arr2[10] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0;
	printf("数组1输入：》\n");
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr1[i]);
	}
	printf("数组2输入：》\n");

	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr2[i]);
	}
	int temp = 0;
	for (i = 0; i < sz; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
		
	}
	printf("arr2数组内容：\n");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	printf("arr1数组内容：\n");

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}

	return 0;
}