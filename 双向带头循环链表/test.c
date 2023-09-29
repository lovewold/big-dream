#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void menu()
{
	printf("*********************************************\n");
	printf("***********    1.头插       *****************\n");
	printf("***********    2.尾插       *****************\n");
	printf("***********    3.头删       *****************\n");
	printf("***********    4.尾删       *****************\n");
	printf("***********    5.查找       *****************\n");
	printf("***********    6.删除pos位  *****************\n");
	printf("***********    7.销毁链表   *****************\n");
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
		printf("请选择你要执行的操作->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入你要头插的值\n");
			scanf("%d", &x);
			ListPushFront(List,x);
			ListPrint(List);
			break;
		case 2:
			printf("请输入你要尾插的值\n");
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
			printf("请输入你要查找的值\n");
			scanf("%d", &x);
			ListNode* Node = ListFind(List, x);
			if (Node != NULL)
			{
				printf("这个值在内存中的地址是->%p", &Node);
			}
			break;
		case 6:
			printf("请输入你要删除的值\n");
			scanf("%d", &x);
			ListNode* Node1 = ListFind(List, x);
			if (Node1 != NULL)
			{
				ListErase(Node1);
				ListPrint(List);
			}
			else
			{
				printf("链表没有'%d'这个值\n",x);
			}
			break;
		case 7:
			ListDestory(List);
			ListPrint(List);
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	}
	return 0;
}