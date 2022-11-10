#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = {1};//数组的声明
	int i = 0;
	
	for (i = 0; i < 10; i++)//循环输出数组
	{
		printf("  arr[%d]=%d\n",i, arr[i]);
	}
	return 0;
}