#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"

void menu()
{
	printf("*********************************************\n");
	printf("***********    1.ͷ��       *****************\n");
	printf("***********    2.ͷɾ       *****************\n");
	printf("***********    3.β��       *****************\n");
	printf("***********    4.βɾ       *****************\n");
	printf("***********    5.����       *****************\n");
	printf("***********    6.ɾ��pos��  *****************\n");
	printf("***********    7.ɾ��posλ  *****************\n");
	printf("***********    8.���ٵ����� *****************\n");
	printf("***********    0.exit       *****************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
}
int main()
{
	SListNode* SL = NULL;
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
			printf("��������Ҫ������ͷ�����������-> ");
			scanf("%d", &x);
			SListPushFront(&SL, x);
			SListPrint(SL);
			break;
		case 2:
			SListPopFront(&SL);
			SListPrint(SL);
			break;
		case 3:
			printf("��������Ҫ������β�����������-> ");
			scanf("%d", &x);
			SListPushBack(&SL, x);
			SListPrint(SL);
			break;
		case 4:
			SListPopBack(&SL);
			SListPrint(SL);
			break;
		case 5:
			printf("��������Ҫ���ҵ�����-> ");
			scanf("%d", &x);
			SListNode* tem= SListFind(SL, x);
			if (tem == NULL)
			{
				printf("û���ҵ�\n");
			}
			else
			{
				printf("������ֵ��ڴ�ռ��ַ�� %p\n", tem);
			}
			SListPrint(SL);
			break;
		case 6:
			printf("��������Ҫɾ�������ֵ�ǰһ��ֵ-> ");
			scanf("%d", &x);
			SListNode* tem1 = NULL;
			tem1 = SListFind(SL, x);
			if (tem1 == NULL)
			{
				printf("û���ҵ�\n");
			}
			else
			{
				SListEraseAfter(tem1);
			}
			SListPrint(SL);
			break;
		case 7:
			printf("��������Ҫɾ��������-> ");
			scanf("%d", &x);
			SListNode* tem2 = NULL;
			tem2 = SListFind(SL, x);
			if (tem2 == NULL)
			{
				printf("û���ҵ�\n");
			}
			else
			{
				SListErase(tem2);
			}
			SListPrint(SL);
			break;
		case 8:
			SListDestroy(&SL);
			SListPrint(SL);
			break;
		default:
			printf("���������������\n");
			break;
		}
	}





}