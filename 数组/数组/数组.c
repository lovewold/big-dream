#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr[10] = {1};//数组的声明
//	int i = 0;
//	
//	for (i = 0; i < 10; i++)//循环输出数组
//	{
//		printf("  arr[%d]=%d\n",i, arr[i]);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int arr[3][4] = { 1 };//不完全初始化
	int i = 0;
	int count = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = ++count;//遍历依次存放1-12；
		}
	}
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("  arr[%d][%d]=%-2d %p ",i,j, arr[i][j],&arr[i][j]);//循环打印，-2d对齐便于观察；
		}
		printf("\n");
	}
	
	return 0;
}