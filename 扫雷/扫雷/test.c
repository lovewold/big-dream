#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"
//�˵�������

extern key;
void menu()
{
	printf("       -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("      |*************-- ɨ����Ϸ --************|\n");
	printf("      |***************************************|\n");
	printf("      |************** 1.��ʼ��Ϸ *************|\n");
	printf("      |************** 0.������Ϸ *************|\n");
	printf("      |***************************************|\n");
	printf("      |***************************************|\n");

}
//�Ѷ�ѡ��
void menunandu()
{
	printf("      *************-- ɨ����Ϸ --************\n");
	printf("      ***************************************\n");
	printf("      *************--  1.��  --************\n");
	printf("      *************--  2.��ͨ  --************\n");
	printf("      *************--  3.����  --************\n");
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
		printf("��ѡ����Ϸ�Ѷ�\n");
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
			printf("һ��\n");
			break;
		case 3:
			printf("����\n");
			break;
		default:
			printf("�����������������룺\n");
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
		printf("������˵�ѡ�����\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�����������������룺\n");
			break;
		}
	} while (input);
	
	return 0;
}