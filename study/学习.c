#define _CRT_SECURE_NO_WARNINGS 1
//�˵�
//ѡ��ʼ��Ϸ���ǽ�����Ϸ�����������������
//��ʼ��Ϸ���´�С�����Դ���һ��1-100���ݣ�����𰸡����ȶԣ���ȷ��-�ɹ�������Ļ���������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("********************************\n");
	printf("**********  1.����Ϸ   *********\n");
	printf("**********  0.��  ��   *********\n");
	printf("********************************\n");

}//


void play()
{
	printf("������1-100������:>\n");
	int num = rand() % 100 + 1;
	int x = 0;
	while (1)
	{
		scanf("%d", &x);
		if (x == num)
		{
			printf("�ɹ���,����ţ��\n");
			break;
		}
		else if (x > num)
		{
			printf("����ֵ�������ٴ����룺\n");
		}
		else if (x < num)
		{
			printf("����ֵ��С�����ٴ����룺\n");
		}
	}
	
}
int main()
{
	menu();
	int i = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("��ʼ��Ϸ����\n");
			play();
			break;
		case 0:
			break;
		default:
			printf("���������룺\n");
			break;
		}
	} while (i);
		
	
	return 0;
}
