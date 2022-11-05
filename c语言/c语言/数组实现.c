#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//始化数组为全0
void init(int* str,int sz)
{
	
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		str[i] = 0;
	}
}
void print(int* str,int sz)
{
	
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",str[i]);
	}
}
//实现reverse()  函数完成数组元素的逆置
void reverse(int* str,int sz)
{
	
	int i = 0;
	int temp = 0;
	while (i <(sz-1-i))
	{
		temp = str[(sz-1)- i];
		str[(sz-1) - i] = str[i];
		str[i] = temp;
		i++;
		
	}
}
int main()
{
	
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	init(arr1,sz);
	print(arr1,sz);
	printf("\n");

	int arr2[5] = { 1,2,3,4,5 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	reverse(arr2, sz2);
	print(arr2, sz2);


	return 0;
}