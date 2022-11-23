#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("*****************************\n");
	printf("****** 猜数字游戏1-100 ******\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*********    1.play   *******\n");
	printf("*********    0.exit   *******\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("\n");


}

void play()
{
	int num = 0;
	int ret = rand()% 100 + 1;
	
	while (1)
	{
		printf("请猜数字：");
		scanf("%d", &num);
		if (num > ret)
		{
			printf("输入值过大\n");
			continue;
		}
		else if (num < ret)
		{
			printf("输入值过小\n");
			continue;
		}
		else if (num = ret)
		{
			printf("输入正确结果为%d，你真棒!!!\n",ret);
			break;
		}
	}
}
int main()
{
	menu();
	int i=0;
	srand((unsigned int)time(NULL));
	do 
	{
		void menu();
		scanf("%d", &i);
		switch(i)
		{
		case 1:
			printf("开始游戏，请输入：\n");
		    play();
		case 0:
			break;
		default :
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (i);
	
	return 0;
}
//