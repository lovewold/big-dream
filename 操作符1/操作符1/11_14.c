#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	
//	int arr[10][10] = { 0 };
//	int N = 0;
//	int M = 0;
//	scanf("%d %d", &N, &M);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < M; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int sum = 0;
//	for (i = 0; i < N; i++)
//	{
//		for(j = 0; j < M; j++)
//		{
//			if (arr[i][j] > 0)
//			{
//				sum += arr[i][j];
//			}
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[20] = { 0 };
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 20; i++)
//	{
//		if (n > 0)
//		{
//			arr[i] = n % 6;
//			n /= 6;
//			count++;
//		}
//		if (n == 0)
//		{
//			break;
//		}
//	}
//	for (i = count-1; i >= 0; i--)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int i = 0;
	int n = 0;
	int arr[50] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int sign = 0;
	scanf("%d", &sign);
	for (i = 0; i < n; i++)
	{
		if (arr[i] != sign)
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}