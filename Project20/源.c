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
//��Ѱ��õ�������ٽ��ݼ��㣬��Ϊ������
//��һ�������õ���Ϊ 200 ��(��)���ڵĲ��֣����Ϊÿ�� 0.52 Ԫ��
//�ڶ��������õ����� 201 - 400 ��(��)���ⲿ�֣����Ϊÿ�� 0.57 Ԫ��
//�����������õ��� 400 �����ϲ��֣����Ϊÿ�� 0.82 Ԫ��
//����ա�
//#include <stdio.h>
//int main(void)
//{
//	int n = 0;
//	double cost = 0.0;
//	printf("�������õ����������������");
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
//		printf("�����õ���������Ǹ�����");
//	printf("����ܶ��ǣ�%.2f\n", cost);
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