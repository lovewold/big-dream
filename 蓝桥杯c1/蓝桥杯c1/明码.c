#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[32] = { 4, 0, 4, 0, 4, 0, 4, 32, - 1, - 16, 4, 32, 4, 32, 4, 32, 4, 32, 4, 32, 8, 32, 8, 32, 16, 34, 16, 34, 32, 30, - 64, 0 };
	int i = 0;
	int arr1[32] = { 0 };
	for (i = 0; i < 31; i++)
	{
		int j = 0;
		for (j = 0; j < 32; j++)
		{
			arr1[i] = ((arr[i] >> i) & 1);
			/*arr[i+1]= ((arr[i+1] >> i) & 1);*/
		}
		for (j = 31; j >= 0; j--)
		{
			printf("%d", arr1[j]/*,arr[j+1*//*]*/);
		}
	}
	return 0;
}