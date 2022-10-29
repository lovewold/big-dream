#define _CRT_SECURE_NO_WARNINGS 1
//菜单
//选择开始游戏还是结束游戏；输入错误重新输入
//开始游戏（猜大小）电脑创建一个1-100数据；输入答案——比对；正确的-成功；错误的话—继续猜
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("********************************\n");
	printf("**********  1.玩游戏   *********\n");
	printf("**********  0.退  出   *********\n");
	printf("********************************\n");

}//


void play()
{
	printf("请输入1-100内数字:>\n");
	int num = rand() % 100 + 1;
	int x = 0;
	while (1)
	{
		scanf("%d", &x);
		if (x == num)
		{
			printf("成功了,你真牛逼\n");
			break;
		}
		else if (x > num)
		{
			printf("输入值过大，请再次输入：\n");
		}
		else if (x < num)
		{
			printf("输入值过小，请再次输入：\n");
		}
	}
	
}
int main()
{
	menu();
	int i = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("开始游戏：》\n");
			play();
			break;
		case 0:
			break;
		default:
			printf("请重新输入：\n");
			break;
		}
	} while (i);
		
	
	return 0;
}
