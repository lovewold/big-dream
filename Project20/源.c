#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int z = 0;
//	int x = 15;
//	int y = 2;
//	z = 0.5 + (float)(x / y);
//
//	printf("%d", z);
//	return 0;
//}

// int mian(void)
//{
// printf("Hello SWUPL\n");
// return 0;
//
//}
// #include <stdio.h>
// int main(void)
// {
// const int N = 20;
// int a[N];
// int max, i;
// for (i = 0; i <= N; i++)
// scanf("%d", &a[i]);
// for (max = a[0], i = 0; i < N; i++)
// if (max > a[i])
// max = a[i];
//
//	printf("max=%d\n", max);
//return 0;
//
//}
//电费按用电度数多少阶梯计算，分为三档：
//第一档，月用电量为 200 度(含)以内的部分，电价为每度 0.52 元；
//第二档，月用电量是 201 - 400 度(含)的这部分，电价为每度 0.57 元；
//第三档，月用电量 400 度以上部分，电价为每度 0.82 元。
//请填空。
//#include <stdio.h>
//int main(void)
//{
//	int n = 0;
//	double cost = 0.0;
//	printf("请输入用电度数（正整数）：");
//	scanf("%d", &n);
//	if (n > 0)
//	{
//		cost = 0.52 * n;
//		if (n >= 200)
//			cost = cost + 0.57 * (n - 200);
//		if (n >= 400)
//
//			cost = cost + 0.82 * (n - 400);
//	}
//	else
//		printf("错误，用电度数不能是负数！");
//	printf("电费总额是：%.2f\n", cost);
//	return 0;
//}
#include <stdio.h>
int main(void)
{
	const int N = 20;
	int a[N];
	int max, i;
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (i=0;i<N;i++)
		if (max < a[i])
			max=a[i];
	printf("max=%d\n", max);
	return 0;
}