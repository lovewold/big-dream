#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void menu()
{
	printf("*********************************************\n");
	printf("***********    1.ͷ��       *****************\n");
	printf("***********    2.β��       *****************\n");
	printf("***********    3.ͷɾ       *****************\n");
	printf("***********    4.βɾ       *****************\n");
	printf("***********    5.����       *****************\n");
	printf("***********    6.ɾ��posλ  *****************\n");
	printf("***********    7.��������   *****************\n");
	printf("***********    0.exit       *****************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
}
int main()
{
	ListNode* List = ListCreate();
	int x = 0;
	int input = 1;
	menu();
	while (input)
	{
		printf("��ѡ����Ҫִ�еĲ���->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ҫͷ���ֵ\n");
			scanf("%d", &x);
			ListPushFront(List,x);
			ListPrint(List);
			break;
		case 2:
			printf("��������Ҫβ���ֵ\n");
			scanf("%d", &x);
			ListPushBack(List, x);
			ListPrint(List);
			break;
		case 3:
			ListPopFront(List);
			ListPrint(List);
			break;
		case 4:
			ListPopBack(List);
			ListPrint(List);
			break;
		case 5:
			printf("��������Ҫ���ҵ�ֵ\n");
			scanf("%d", &x);
			ListNode* Node = ListFind(List, x);
			if (Node != NULL)
			{
				printf("���ֵ���ڴ��еĵ�ַ��->%p", &Node);
			}
			break;
		case 6:
			printf("��������Ҫɾ����ֵ\n");
			scanf("%d", &x);
			ListNode* Node1 = ListFind(List, x);
			if (Node1 != NULL)
			{
				ListErase(Node1);
				ListPrint(List);
			}
			else
			{
				printf("����û��'%d'���ֵ\n",x);
			}
			break;
		case 7:
			ListDestory(List);
			ListPrint(List);
			break;
		default:
			printf("���������������\n");
			break;
		}
	}
	return 0;
}