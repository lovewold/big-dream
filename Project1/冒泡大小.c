//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int arr[3] = { 0 }; int i = 0;
//	int j = 0;
//	int temp = 0;
//	int a = 0;
//	for (i = 0; i < 3; i++)//ѭ���������ݽ�����
//	{
//		scanf("%d", &a);
//		arr[i] = a;
//	}
//	for (i = 1; i <= 3; i++)//ð�������ⲿ��ѭ��
//	{
//		for (j = 0; j < 3 - i; j++)//�ڲ��Ƚϴ���ѭ��
//		{
//			if (arr[j] < arr[j + 1])//������������λ��
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for(i = 0; i < 3; i++)//��ӡ����
//	{
//		printf("%d ", arr[i]);
//	}
//
//
//	return 0;
//}