#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//������
void menu()
{
	printf("***************************\n");
	printf("******* 1.��ʼ��Ϸ  *******\n");
	printf("******* 0.�˳���Ϸ  *******\n");
	printf("***************************\n");

}

void game()
{

	char board[ROW][COL];
	real(board, ROW, COL);
	char ret = 0;
	Printf_board(board, ROW, COL);
	//����Ԫ�س�ʼ����
	while (1)
	{

		
		//��ӡ����
		//�������
		playergame(board);
		ret = is_win(board);
		if (ret != 'c')
		{
			Printf_board(board, ROW, COL);
			break;
		}
		//��������
		computer(board);
		Printf_board(board, ROW, COL);
		if (ret != 'c')
		{
			Printf_board(board, ROW, COL);
			break;
		}

		//��Ӯ�ж�
		//����*��Ӯ
		//����#����Ӯ
		//����c����
		//����oƽ��


	}
	if (ret == '*')
	{
		printf("��ϲ��Ӯ��\n"); 
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else if (ret == 'o')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	menu();//�˵�
	int input= 0;
	printf("�����룺\n");
	
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������룺\n");
			break;
		}
	}while(input);
	return 0;
}