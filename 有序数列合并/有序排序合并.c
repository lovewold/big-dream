#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>
//#include<memory.h>
////输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a,&b);
//	int* const arr1 = (a * (sizeof(int)));
//	int* const arr2 = (b * (sizeof(int)));
//	int* const arr3 = ((a + b) * (sizeof(int)));
//	int i = 0;
//	
//	for (i = 0; i < a; a++)
//	{
//		scanf("%d ", &a);
//		arr1[i] = a;
//		arr3[i] = arr1[i];
//	}
//	for (i = 0; i < b; i++)
//	{
//		arr3[i + a] = arr2[i];
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int ret = 1;
	int sum = 0;

	for (j = 1; j <=10; j++)
	{
		for (i = 0; i <= j; i++)
		{
			ret *= i;

		}
		sum += ret;
	}
	printf("%d", sum);
	return 0;
	
}