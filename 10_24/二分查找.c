#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,23,43,54,72,89,99,100,120,250 };
//	int left = 0;
//	int right = 9;
//	int mid = 0;
//	int find = 0;
//	int f = 0;
//	scanf("%d", &find);
//	
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (find < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (find > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是%d", mid);
//			f = 1;
//			break;
//		}
//	}
//	if (f != 1)
//	{
//		printf("没有找到");
//	}
//	
//	
//	return 0;
//}