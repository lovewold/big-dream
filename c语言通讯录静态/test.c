#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("******************************************\n");
	printf("******  1.���    *****    2.ɾ��   ******\n");
	printf("******  3.����    *****    4.����   ******\n");
	printf("******  5.��ʾ    *****    6.����   ******\n");
	printf("******  7.���    *****    0.�˳�   ******\n");
	printf("******************************************\n");
}
void menu_sort()
{
	printf("******************************************\n");
	printf("******       1.�������ֽ�������     ******\n");
	printf("******       2.���������������     ******\n");
	printf("******       0.ֹͣ��������         ******\n");
	printf("******************************************\n");
}
int main()
{
	int input;
	//�˵�����
	Contact con;
	//�������
	int insort;
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
				menu_sort();
				printf("��ѡ��-�� ");
				scanf("%d", &insort);
				do{
					switch (insort)
					{
					case 1:
						SortContact_by_name(&con);
						ShowContact(&con);
						break;
					case 2:
						SortContact_by_age(&con);
						ShowContact(&con);
						break;
					default:
						printf("��������������ʽ--��\n");
						break;
					}
					break;
				} while (insort);
				break;
		case INFO:
			Infocontact_all(&con);
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