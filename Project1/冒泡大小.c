//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int arr[3] = { 0 }; int i = 0;
//	int j = 0;
//	int temp = 0;
//	int a = 0;
//	for (i = 0; i < 3; i++)//循环填入数据进数组
//	{
//		scanf("%d", &a);
//		arr[i] = a;
//	}
//	for (i = 1; i <= 3; i++)//冒泡排序，外部大循环
//	{
//		for (j = 0; j < 3 - i; j++)//内部比较次数循环
//		{
//			if (arr[j] < arr[j + 1])//交换相邻逆序位置
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for(i = 0; i < 3; i++)//打印数组
//	{
//		printf("%d ", arr[i]);
//	}
//
//
//	return 0;
//}