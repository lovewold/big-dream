#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("******************************************\n");
	printf("******  1.���    *****    2.ɾ��   ******\n");
	printf("******  3.����    *****    4.����   ******\n");
	printf("******  5.��ʾ    *****    6.����   ******\n");
	printf("****    0.�˳�    *****    0.�˳�   ******\n");
	printf("******************************************\n");
}
int main()
{
	int input;
	//�˵�����
	Contact con;
	Infocontact(&con);
	do
	{
		menu();
		printf("��ѡ��-��\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
				break;
		case 0:
			break;
		default:
			printf("ѡ���������ѡ-��\n");
			break;
		}

	} while (input);
	//����һ��ͨѶ¼
	
	
	//����ɾ���飬�ģ���ʾ����

}