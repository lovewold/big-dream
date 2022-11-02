#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//½×³ËÊµÏÖ
//int jiecheng1(int x)
//{
//	if (x <= 1)
//	{
//		return 1;
//	}
//	else if (x > 1)
//	{
//		return x * jiecheng1(x - 1);
//	}
//}
//
//int jiecheng2(int y)
//{
//	int i = 1;
//	int sum = 1;
//	for (i = 1; i <= y; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret1 = jiecheng1(a);
//	int ret2 = jiecheng2(a);
//	printf("%d\n%d", ret1, ret2);
//	return 0;
//}