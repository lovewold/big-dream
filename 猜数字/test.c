#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("*****************************\n");
	printf("****** ��������Ϸ1-100 ******\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*********    1.play   *******\n");
	printf("*********    0.exit   *******\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("\n");


}

void play()
{
	int num = 0;
	int ret = rand()% 100 + 1;
	
	while (1)
	{
		printf("������֣�");
		scanf("%d", &num);
		if (num > ret)
		{
			printf("����ֵ����\n");
			continue;
		}
		else if (num < ret)
		{
			printf("����ֵ��С\n");
			continue;
		}
		else if (num = ret)
		{
			printf("������ȷ���Ϊ%d�������!!!\n",ret);
			break;
		}
	}
}
int main()
{
	menu();
	int i=0;
	srand((unsigned int)time(NULL));
	do 
	{
		void menu();
		scanf("%d", &i);
		switch(i)
		{
		case 1:
			printf("��ʼ��Ϸ�������룺\n");
		    play();
		case 0:
			break;
		default :
			printf("����������������룺\n");
			break;
		}
	} while (i);
	
	return 0;
}
//