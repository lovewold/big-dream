#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = {1};//���������
	int i = 0;
	
	for (i = 0; i < 10; i++)//ѭ���������
	{
		printf("  arr[%d]=%d\n",i, arr[i]);
	}
	return 0;
}