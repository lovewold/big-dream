#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("******************************************\n");
	printf("******  1.添加    *****    2.删除   ******\n");
	printf("******  3.查找    *****    4.更改   ******\n");
	printf("******  5.显示    *****    6.排序   ******\n");
	printf("****    0.退出    *****    0.退出   ******\n");
	printf("******************************************\n");
}
int main()
{
	int input;
	//菜单服务
	Contact con;
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
			SortContact(&con);
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