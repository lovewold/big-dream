#define _CRT_SECURE_NO_WARNINGS 1
//�� 7 �⣨����⣩
//��Ŀ���ƣ�
//������
//��Ŀ���ݣ�
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:

//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//#include<stdio.h>
//int main()
//{
//	char n = 0;
//	for (n = 'a'; n <= 'd'; n++)
//	{
//		if (((n != 'a') + (n == 'c') + (n == 'd') + (n != 'd')) == 3)
//		{
//			printf("%c", n);
//		}
//	}
//
//	return 0;
//}

//����Ļ�ϴ�ӡ������ǡ�
//
//
//
//1
//
//1 1
//
//1 2 1
//
//1 3 3 1
//
//����

#include<stdio.h>
int main()
{
	int arr[20][20] = { 0 };
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;

	for (i = 0; i <= n; i++)
	{
		int count = n-i;
		for (j = 0; j < i; j++)
		{
			arr[i][0] = 1;
			arr[i][i - 1] = 1;//�ı��������ʹ֮Ϊ1
			
			//�м�ֵ�仯
			if (i > 1&&j>0&&j<=i-1)
			{
				arr[i+1][j] = arr[i][j - 1] + arr[i][j];
			}
			while (count-- >0)
			{
				printf(" ");

			}
			printf("%2d ", arr[i][j]);

		}
		printf("\n");
	}
	return 0;
}
