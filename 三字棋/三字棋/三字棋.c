#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//主函数
void menu()
{
	printf("***************************\n");
	printf("******* 1.开始游戏  *******\n");
	printf("******* 0.退出游戏  *******\n");
	printf("***************************\n");

}

void game()
{

	char board[ROW][COL];
	real(board, ROW, COL);
	char ret = 0;
	Printf_board(board, ROW, COL);
	//棋盘元素初始化；
	while (1)
	{

		
		//打印棋盘
		//玩家下棋
		playergame(board);
		ret = is_win(board);
		if (ret != 'c')
		{
			Printf_board(board, ROW, COL);
			break;
		}
		//电脑下棋
		computer(board);
		Printf_board(board, ROW, COL);
		if (ret != 'c')
		{
			Printf_board(board, ROW, COL);
			break;
		}

		//输赢判断
		//返回*人赢
		//返回#电脑赢
		//返回c继续
		//返回o平局


	}
	if (ret == '*')
	{
		printf("恭喜你赢了\n"); 
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'o')
	{
		printf("平局\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	menu();//菜单
	int input= 0;
	printf("请输入：\n");
	
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入：\n");
			break;
		}
	}while(input);
	return 0;
}