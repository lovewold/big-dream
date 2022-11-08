#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
//������װ
//���̳�ʼ��
void real(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL;j++)
		{
			arr[i][j] = ' ';
		}
	}
}
//��ӡ����
void Printf_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < COL; j++)
		{
			printf("---");
			if(j<COL-1)
				printf("|");
		}
		printf("\n");
	}
	printf("\n");
}
void playergame(char board[ROW][COL])
{
	printf("�������\n");
	while (1)
	{
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (0 < col && col <= COL && row > 0 && row <= ROW)
		{
			if (board[row - 1][col - 1] == ' ')
			{
				board[row - 1][col - 1] = '*';
				break;
			}
			else
				printf("��λ���Ѿ���ռ�ã����������룺\n");

		}
		else
			printf("���������������������룺\n");
	}
		
}
//��������
void computer(char board[ROW][COL])
{
	printf("��������\n");
	while (1)
	{
		int row = rand() % 3;
		int col = rand() % 3;
		if (board[row][col] == ' ')
		{
			board[row][col] = '#';
			break;
		}
	}
		
}
//�ж������Ƿ�����
char full_board(char board[ROW][COL])
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char is_win(char board[ROW][COL])
{
	int i = 0;
	int j = 0;
	
	char row = 0;
	char col = 0;
	
	int a = 0;//�Խ����жϼ�����
	int b = 0;
	for (i = 0,j=0; i < ROW; i++,j++)
	{
		int count = 0;
		//�����ж�
		row = board[i][j];
		for (j = 0; j < COL; j++)
		{
			if ((board[i][j] == row)&&row!=' ')
			{
				count++;
				if (count == 3)
				{
					return row;//������һ����ȷ�����һ����Ԫ��
				}

			}
			
		}
		count = 0;
		//�����ж�
		col = board[i][0];
		for (j = 0; j < COL; j++)
		{
			if ((board[j][i] == col)&&col!=' ')
			{
				count++;
				if (count == COL)
				{
					return col;
				}
			}
		}
		char temp = board[1][1];
		//�Խ����жϣ�
		for (i = 0, j = 0; i < ROW; i++, j++)
		{
			if ((board[i][j] == temp) && temp != ' ')
			{
				a++;
				if (a == COL)
				{
					return temp;
				}
			}
			if (board[ROW - i - 1][COL - j - 1] == temp && temp != ' ')
			{
				b++;
				if (b == ROW)
				{
					return temp;
				}
			}
		}
		
		
		
	}
	if (full_board(board) == 0)
	{
		return 'c';
	}
	return 'o';
}

