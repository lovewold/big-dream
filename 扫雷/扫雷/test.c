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
//难度选择
void menunandu()
{
	printf("      *************-- 扫雷游戏 --************\n");
	printf("      ***************************************\n");
	printf("      *************--  1.简单  --************\n");
	printf("      *************--  2.普通  --************\n");
	printf("      *************--  3.困难  --************\n");
	printf("      ***************************************\n");


}
void game()
{
	int input = 0;
	
	char mine[ROW1][COL1];
	char show[ROW1][COL1];
	do 
	{
		menunandu();
		printf("请选择游戏难度\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:

			
			initboard(mine,ROW1,COL1,'0');
			srand((unsigned int)time(NULL));
			lei(mine);
			printboard(mine, ROW, COL);
			initboard(show, ROW1, COL1, '*');
			
			printboard(show, ROW, COL);
			do
			{
				int i = 0;
				int j = 0;
				scanf("%d %d", &i, &j);
				playboard(mine, show,i,j);
				printboard(show, ROW, COL);
				if (key == 1)
				{
					goto feileishen;
				}
				findboard(show);
			} while (1);
			break;
		case 2:
			printf("一般\n");
			break;
		case 3:
			printf("困难\n");
			break;
		default:
			printf("输入有误，请重新输入：\n");
			break;
		}

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