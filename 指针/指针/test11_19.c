#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int* pa = arr;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", *pa);
//		++pa;
//	}
//	return 0;
//}
#include<stdio.h>
#include<string.h>

void printt(char* arr)
{
	int left = 0;
	int right = strlen(arr) - 1;
	char temp = 0;
	while (left < right)
	{
		temp = *(arr + left);
		*(arr + left) = *(arr + right);
		*(arr + right) = temp;
		left++;
		right--;
	}
	int i = 0;
	while (i < (strlen(arr) - 1))
	{
		printf("%c", arr[i]);
		i++;
	}
}
int main()
{
	char arr[101] = { 0 };
	int i = 0;
	while (get(arr)!= '\n')
	{
		scanf("%c", &arr[i]);
		i++;
	}
	printt(arr);
	return 0;
}