#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("******************************************\n");
	printf("******  1.添加    *****    2.删除   ******\n");
	printf("******  3.查找    *****    4.更改   ******\n");
	printf("******  5.显示    *****    6.排序   ******\n");
	printf("******  7.清空    *****    0.退出   ******\n");
	printf("******************************************\n");
}
void menu_sort()
{
	printf("******************************************\n");
	printf("******       1.根据名字进行排序     ******\n");
	printf("******       2.根据年龄进行排序     ******\n");
	printf("******       0.停止进行排序         ******\n");
	printf("******************************************\n");
}
int main()
{
	int input;
	//菜单服务
	Contact con;
	//排序服务
	int insort;
	Infocontact(&con);
	do
	{
		menu();
		printf("请选择-》\n");
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
				printf("请选择-》 ");
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
						printf("请重新输入排序方式--》\n");
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
			printf("选择错误，请重选-》\n");
			break;
		}

	} while (input);
	//建立一个通讯录
	
	
	//增，删，查，改，显示，退

}