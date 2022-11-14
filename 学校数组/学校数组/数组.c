#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//    int x[10], i, max, min, a = 0, b = 0;
//    printf("Enter 10 integers:\n");
//    for (i = 0; i < 10; i++)
//        scanf("%d", &x[i]);
//    max = min = x[0];
//    for (i = 1; i < 10; i++)
//    {
//        if (max < x[i])
//        {
//            max = x[i]; a = i;
//        }
//        if (min > x[i])
//        {
//            min = x[i]; b = i;
//        }
//    }
//    printf("Maximum value is %d,最大值下标是%d\n", max, a);
//    printf("Minimum value is %d,最小值下标是%d\n,", min, b);
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i, j, a[4][5], min;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d", &a[i][j]);
//			
//		}
//	}
//	min = a[0][0];
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			if (min > a[i][j])
//			{
//				min = a[i][j];
//
//			}
//
//		}
//	}
//	printf("min=%d\n", min);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[3][3] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int sum = 0;
//	for (i = 0,j=0; i < 3; i++,j++)
//	{
//		sum += arr[i][j];
//	}
//	for (i = 0, j = 2; i < 3; i++, j--)
//	{
//		sum += arr[i][j];
//	}
//	printf("sum = %d", sum);
//	return 0;
//}
//#define n 10 //修改n的值即可改变输入个数
//#include<stdio.h>
//int main()
//{
//	int arr[n] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = n - 1; i >= 0; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[3][4] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int max = arr[0][0];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (max < arr[i][j])
//			{
//				max = arr[i][j];
//			}
//		}
//	}
//	printf("max = %d\n",max);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int arr[10][10];
	int arr1[10][10];
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (i = 0; i < m; i++)
	{
		
		for (j = 0; j < n; j++)
		{
			arr1[i][j] = arr[j][i];
			printf("%d\n ", i, j, arr1[i][j]);
		}
		
	}
	
	return 0;
}