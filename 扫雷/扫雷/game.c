#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//���̳�ʼ��9*9��16*16��16*30��������Ϊ10��40��99
//���̳�ʼ��
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
	printf("------ɨ����Ϸ------\n");
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
//�����׺���
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
//����
void playboard(char mine[ROW1][COL1], char show[ROW1][COL1],int i,int j)
{
		
			if (1 <= i && i <= ROW && 1 <= j && j <= COL)
			{
				if (show[i][j] != '*')
				{
					printf("�õ��Ѿ�ȷ�������������룺\n");
				}
				else
				{
					if (mine[i][j] != '1')
					{
						char ret = mine[i - 1][j] + mine[i + 1][j] + mine[i][j - 1] + mine[i][j + 1] + mine[i - 1][j - 1] + mine[i - 1][j + 1] + mine[i + 1][j - 1] + mine[i + 1][j + 1];
						show[i][j] = ret - 7 * '0';
						
					}
					else
					{
						show[i][j] = '#';
						
						printf("\n�㱻ը����\n");
						key = 1;
					}
				}
			}
			else
			{
				printf("���������������������룺\n");
			}
	
}
//����Ƿ�Ӯ
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
		printf("��Ӯ��\n");
	}
}
//�Զ�����
void pailei(char mine[ROW1][COL1], char show[ROW1][COL1], int x, int y)
{
	if(show[x][y]=='*')
}