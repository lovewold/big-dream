#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//棋盘初始化9*9；16*16；16*30；雷数量为10；40；99
//棋盘初始化
int key = 0;
void initboard(char board[ROW1][COL1], int row1, int col1, char set)
{
	int i = 0;
	for (i = 0; i < ROW1; i++)
	{
		int j = 0;
		for (j = 0; j < COL1; j++)
		{
			board[i][j] = set;
		}
	}
}
void printboard(char board[ROW1][COL1], int row, int col)
{
	printf("\n");
	printf("------扫雷游戏------\n");
	int i = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//生成雷函数
void lei(char board[ROW1][COL1])
{
	int i = 0;
	while (i < lei1)
	{
		int row = rand() % 9 + 1;
		int col = rand() % 9 + 1;
		if (board[row][col] == '0')
		{
			board[row][col] = '1';
			i++;
		}
	}
}
//排雷
void playboard(char mine[ROW1][COL1], char show[ROW1][COL1],int i,int j,int* k)
{
		
			if (1 <= i && i <= ROW && 1 <= j && j <= COL)
			{
				if (show[i][j] != '*')
				{
					printf("该点已经确定，请重新输入：\n");
				}
				else
				{
					if (mine[i][j] != '1')
					{
						char ret = mine[i - 1][j] + mine[i + 1][j] + mine[i][j - 1] + mine[i][j + 1] + mine[i - 1][j - 1] + mine[i - 1][j + 1] + mine[i + 1][j - 1] + mine[i + 1][j + 1];
						show[i][j] = ret - 7 * '0';
	
						int x = i;
						int y = j;

						if (show[x][y] == '0')
						{
							if (x - 1 >= 1 && y - 1 >= 1 && show[x - 1][y - 1] == '*')
							{
								playboard(mine, show, x - 1, y - 1,k=1);
							}
							if (x - 1 >= 1 && show[x - 1][y] == '*')
							{
								playboard(mine, show, x - 1, y,k=1);

							}
							if (x - 1 >= 1 && y + 1 <= COL && show[x - 1][y + 1] == '*')
							{
								playboard(mine, show, x - 1, y + 1,k=1);

							}
							if (1 <= y - 1 && show[x][y - 1] == '*')
							{
								playboard(mine, show, x, y - 1,k=1);

							}
							if (y + 1 <= COL && show[x][y + 1] == '*')
							{
								playboard(mine, show, x, y + 1,k=1);

							}
							if (x + 1 <= ROW && y - 1 >= 1 && show[x + 1][y - 1] == '*')
							{
								playboard(mine, show, x, y - 1,k=1);

							}
							if (x + 1 <= ROW && show[x + 1][y] == '*')
							{
								playboard(mine, show, x + 1, y,k=1);

							}
							if (x + 1 <= ROW && y + 1 <= COL && show[x + 1][y + 1] == '*')
							{
								playboard(mine, show, x + 1, y + 1,k=1);

							}
						}
					}
					else
					{
						show[i][j] = '#';
						
						printf("\n你被炸死了\n");
						key = 1;
					}
				}
			}
			else
			{
				printf("坐标输入有误，请重新输入：\n");
			}
	
}
//检查是否赢
void findboard(char show[ROW1][COL1])
{
	int i = 1;
	int j = 1;
	int count = 0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	if (count == lei1)
	{
		printf("你赢了\n");
	}
}
