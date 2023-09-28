#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"

void menu()
{
	printf("*********************************************\n");
	printf("***********    1.头插       *****************\n");
	printf("***********    2.头删       *****************\n");
	printf("***********    3.尾插       *****************\n");
	printf("***********    4.尾删       *****************\n");
	printf("***********    5.查找       *****************\n");
	printf("***********    6.删除pos后  *****************\n");
	printf("***********    7.删除pos位  *****************\n");
	printf("***********    8.销毁单链表 *****************\n");
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
		printf("请选择你要执行的操作->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入你要在链表头部插入的数字-> ");
			scanf("%d", &x);
			SListPushFront(&SL, x);
			SListPrint(SL);
			break;
		case 2:
			SListPopFront(&SL);
			SListPrint(SL);
			break;
		case 3:
			printf("请输入你要在链表尾部插入的数字-> ");
			scanf("%d", &x);
			SListPushBack(&SL, x);
			SListPrint(SL);
			break;
		case 4:
			SListPopBack(&SL);
			SListPrint(SL);
			break;
		case 5:
			printf("请输入你要查找的数字-> ");
			scanf("%d", &x);
			SListNode* tem= SListFind(SL, x);
			if (tem == NULL)
			{
				printf("没有找到\n");
			}
			else
			{
				printf("这个数字的内存空间地址是 %p\n", tem);
			}
			SListPrint(SL);
			break;
		case 6:
			printf("请输入你要删除的数字的前一个值-> ");
			scanf("%d", &x);
			SListNode* tem1 = NULL;
			tem1 = SListFind(SL, x);
			if (tem1 == NULL)
			{
				printf("没有找到\n");
			}
			else
			{
				SListEraseAfter(tem1);
			}
			SListPrint(SL);
			break;
		case 7:
			printf("请输入你要删除的数字-> ");
			scanf("%d", &x);
			SListNode* tem2 = NULL;
			tem2 = SListFind(SL, x);
			if (tem2 == NULL)
			{
				printf("没有找到\n");
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
			printf("输入错误，重新输入\n");
			break;
		}
	}





}