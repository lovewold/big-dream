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
				printf("���������� x x��\n");
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