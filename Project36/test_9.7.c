#define _CRT_SECURE_NO_WARNINGS 1
//杨氏矩阵
//#include<stdio.h>
//void yh_find_numbei(int arr[3][3],int num, int* px, int* py)
//{
//	int x = 0;
//	int y = (*py) - 1;
//	while (x < *px - 1 && y >= 0 )
//	{
//		if (arr[x][y] < num)
//			x++;
//		else if (arr[x][y] > num)
//			y--;
//		else
//		{
//			*px = x;
//			*py = y;
//			return;
//		}
//	}
//	*px = -1;
//	*py = -1;
//
//	return ;
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	int num = 0;
//	scanf("%d", &num);
//	int* x = &i;
//	int* y = &j;
//   	yh_find_numbei(arr,num, x, y);
//	
//	if (*x == -1 && *y == -1)
//	{
//		printf("没有找到");
//	}
//	else
//	{
//		printf("找到了下标是 %d %d", *x, *y);
//	}
//	
//	return 0;
//}
//实验memcpy函数
//
//#include<stdio.h>
//#include<assert.h>
//void* my_memcpy(void* dest, const void* source, size_t num)
//{
//	void* ret = dest;
//	assert(source&&dest);
//	while (num--)
//	{
//		*(char*)dest = *(char*)source;
//		dest = (char*)dest + 1;
//		source = (char*)source + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[40] = { 0 };
//	my_memcpy(arr2, arr1, 20);
//	int i = 0;
//	for (i = 0; i < 20;i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
//模拟实现memmove
//针对有重叠的部分
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest, const void* source, size_t num)
{
	void* ret = dest;
	assert(dest && source);
	if (dest < source)
	{
		while (num--)
		{
			*(char*)dest = *(char*)source;
			dest = (char*)dest + 1;
			source = (char*)source + 1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)source + num);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//             1 2 1 2 3 4 5 8 9 10
	my_memmove(arr1+2, arr1, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
 }
//模拟实现memmove
//针对有重叠的部分