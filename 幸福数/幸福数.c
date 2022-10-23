//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//int arr[10000] = {0};
//int c = 0;
//
//int sum = 0;
//int shu(int x)
//{
//	int i = 0;
//	for (i = 2; i < x / 2; i++)//判断素数函数
//	{
//		if (x % i == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int pow_er(int x)
//{
//	
//	int i = 0;
//	int d,z;
//	int a = 0;
//	for (i = 0; i < 4; i++)
//	{
//		d = x % 10;
//		x /= 10;
//		sum += (d * d);
//		
//	}
//	 arr[c] = sum;//存储每一个平方和数据
//	if(sum == 1)
//	{
//		return x;
//	}
//	else
//	{
//		return pow_er(sum);
//	}
//}
//
//int main()
//{
//	int A = 0;
//	int B = 0;
//	
//	scanf("%d %d", &A, &B);//输入区间
//	
//	int i = 0;
//	int hehe = 0;
//
//	for (i = A; i <= B; i++)
//    {
//		hehe = pow_er(i);
//			printf("%d\n", sum);
//		
//		
//	}
//	return 0;
//}
