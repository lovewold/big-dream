#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int Print(int* arr, int x)
//{
//	int i = 0;
//	for (i = 0; i < x; ++i)
//	{
//		printf("%d ", (*(arr+i)));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr;
//	Print(p, 10);
//	return 0;
////}
//#include<stdio.h>
//int main()
//{
//	int kong = 0;
//	int xin = 0;
//	//���ô�ӡѭ��13�㣻
//	int count = 0;
//	//�ϲ��ӡ7����߲�ȫ����
//	while (count != 7) 
//	{
//		//��ӡ�հ�7-0��
//		for (kong = 0; kong < 6 - (count - 1); kong++)
//		{
//			printf(" ");
//		}
//		//��ӡ�Ǻ�1 3 5 7 9 11 13
//		for (xin = 0; xin < (2 * count - 1); xin++)
//		{
//			printf("*");
//		}
//		printf("\n");
//		
//		count++;
//	}
//	count = 0;
//	while (count != 6)
//	{
//		//��ӡ�հ�1-7
//		for (kong = 0; kong <count ; kong++)
//		{
//			printf(" ");
//		}
//		//��ӡ�Ǻ�11 9 7 5 3 1
//		for (xin = 0; xin < 11-(2*(count-1)); xin++)
//		{
//			printf("*");
//		}
//		printf("\n");
//
//		count++;
//	}
//	
//	
//	return 0;
//}
 //ģ����дstrlen����
//int my_strlen(char* arr)
//{
//	char* star = arr;
//	char* end = arr;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end-star;
//}
////�⺯���Ż�
//int my_strlen(char* str)
//{
//	const char* end = str;
//	while (*end++);
//	return end - str-1;
//}
//#include<stdio.h>
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr); // �������ǵ�ַ����Ԫ�ص�ַ
//	printf("%p\n", &arr[0]); // ���ͬ��
//	printf("%p\n", &arr); 
//
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0] + 1);
//
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1); // +1��������Ԫ��Ϊ��λ
//
//	return 0;
//}
#include<stdio.h>
#include<string.h>

int find_xuanzhuan(char* p, char* q)
{
	int i = strlen(p);
	int j = strlen(q);
	if (i != j)
		return 0;
	int x = 0;
	int y = 0;
	int count = -1 ;
	for (x = 0; x < i;x++ )
	{
		if (p[0] == q[x])
		{
			count = x;
			break;
		}
	}
	if (count == -1)
	{
		return 0;
	}
	for (y = 0; y < j; y++)
	{
		if (q[(count + y) % i] != p[y])
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	char s3[] = "abcd";
	char s4[] = "ACBD";
	int ret = find_xuanzhuan(s1, s2);
	int ret1 = find_xuanzhuan(s3, s4);
	if (ret == 0)
	{
		printf("������ת�ַ���");
	}
	else if (ret == 1)
	{
		printf("����ת�ַ���");
	}
	printf("\n");
	if (ret1 == 0)
	{
		printf("������ת�ַ���");
	}
	else if (ret1 == 1)
	{
		printf("����ת�ַ���");
	}

	return 0;
}
