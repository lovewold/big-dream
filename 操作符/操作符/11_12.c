#define _CRT_SECURE_NO_WARNINGS 1
////#include<stdio.h>
////int main()
////{
////	int a = 3;
////	int b = 4;
////	printf("a=%d b=%d\n", a, b);
////	b = a ^ b;
////	a = b ^ a;
////	b = a ^ b;
////	printf("a=%d b=%d", a, b);
////	return 0;
////}
//#include<stdio.h>
//int return1(int x)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((x >> i) & 1) == 1)
//			count++;
//	}
//	return count;
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	printf("\n");
//	printf("%d", return1(i));
//	return 0;
//}
////#include<stdio.h>
////void jisuan(int x)
////{
////	int i = 0;
////	printf("奇数位");
////	for (i = 32; i >0; i-=2)
////	{
////		
////		if (((x >> i) & 1) == 1)
////		{
////			printf("1 ");
////		}
////		else
////		{
////			printf("0 ");
////		}
////	}
////	printf("偶数数位");
////
////	for (i = 31; i > 0; i -= 2)
////	{
////
////		if (((x >> i) & 1) == 1)
////		{
////			printf("1 ");
////		}
////		else
////		{
////			printf("0 ");
////		}
////	}
////}
////int diffic(int x,int y)
////{
////	int c = x ^ y;
////	int i = 0;
////	int count = 0;
////	for (i = 0; i < 32; i++)
////	{
////		if (((c >> i) & 1) == 1)
////			count++;
////	}
////	return count;
////}
////int main()
////{
////	int i = 0;
////	int j = 0;
////	scanf("%d %d", &i,&j);
////	int ret = diffic(i,j);
////	printf("%d", ret);
////	return 0;
////}
////小乐乐走台阶
////#include<stdio.h>
////int taijie(int x)
////{
////	if (x <= 1)
////	{
////		return 1;
////	}
////	else
////	{
////		return  taijie(x - 1) + taijie(x - 2);
////	}
////}
////int main()
////{
////	int n = 0;
////	scanf("%d", & n);
////	int ret = taijie(n);
////	printf("%d", ret);
////
////}
