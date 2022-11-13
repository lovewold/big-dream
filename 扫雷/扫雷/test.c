#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"
//菜单函数：

extern key;
void menu()
{
	printf("       -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("      |*************-- 扫雷游戏 --************|\n");
	printf("      |***************************************|\n");
	printf("      |************** 1.开始游戏 *************|\n");
	printf("      |************** 0.结束游戏 *************|\n");
	printf("      |***************************************|\n");
	printf("      |***************************************|\n");

}
void game()
{
	int input = 0;
	
	char mine[ROW1][COL1];
	char show[ROW1][COL1];
	do 
	{
		
			
			initboard(mine,ROW1,COL1,'0');
			srand((unsigned int)time(NULL));
			lei(mine);
			printboard(mine, ROW, COL);
			initboard(show, ROW1, COL1, '*');
			system("cls");
			printboard(show, ROW, COL);
			
			do
			{
				int i = 0;
				int j = 0;
				printf("请输入坐标 x x：\n");
				scanf("%d %d", &i, &j);
			
				int k = 0;
				
				playboard(mine, show,i,j,&k);
				system("cls");
				printboard(show, ROW, COL);
				if (key == 1)
				{
					goto feileishen;
				}
				findboard(show);
			} while (1);
			break;
	} while (1); 
feileishen:;
}
int main()
{
	int input = 0;
	
	do
	{
		menu();
		printf("请输入菜单选择命令：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入有误，请重新输入：\n");
			break;
		}
	} while (input);
	
	return 0;
}