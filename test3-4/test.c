#define _CRT_SECURE_NO_WARNINGS 1
////ºÈÆûË®
//#include<stdio.h>
//int main()
//{
//	
//	int money = 0;
//	int kong = 0;
//	scanf("%d", &money);
//	int sum = money;
//	while (money >= 2)
//	{
//		sum += money/2;
//		money = money / 2 + money % 2;
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[10][10];
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 1; i < n; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (arr[i][j] != 0)
//			{
//				printf("NO");
//				goto feileishen;
//				
//			}
//		}
//	}
//	printf("YES");
//	feileishen:
//	return 0;
//}
#include<stdio.h>
int main()
{
	int n = 0;
	int m = 0;
	int i = 0;
	int j = 0;
	scanf("%d %d", &n, &m);
	int arr1[10][10] = {0};
	int arr2[10][10] = {0};
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				printf("No\n");
				goto feileishen;
			}
		}
	}
	printf("Yes\n");
	feileishen:
	
	return 0;
}