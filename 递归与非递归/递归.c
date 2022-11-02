//#define _CRT_SECURE_NO_WARNINGS 1
////递归
//#include<stdio.h>
////递归实现
//int feibo(int x)
//{
//	if (x <= 2)
//	{
//		return 1;
//	}
//	else if (x > 2)
//	{
//		return feibo(x - 1) + feibo(x - 2);
//	}
//}
////非递归实现
//int feibo1(int x)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	int n = x;
//	if (n <= 2)
//	{
//		return 1;
//	}
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = feibo(n);
//	int ret1= feibo1(n);
//	printf("%d\n%d", ret,ret1);
//	return 0;
//}