//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int a = 0;
//	int arr[10] = { 0 };
//	int max = 0;
//	for (i = 0; i < 10; i++)//循环输入数据
//	{
//		scanf("%d", &a);
//		arr[i] = a;
//	}
//	for (i = 0; i < 9; i++)//10个数最多比较9次大小
//	{
//		if (arr[i] > arr[i + 1])//比较相邻两位数据，大值存在max中
//		{
//			if (arr[i] > max)//如果有数据大于max就替换的内容
//			{
//				max = arr[i];
//			}
//		}
//		else if (arr[i] <= arr[i + 1])
//		{
//			if (arr[i + 1] > max)
//				max = arr[i + 1];
//		}
//	}
//	printf("%d", max);
//}