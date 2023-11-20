#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num[100] = { 0 };
	int i;
	while (1)
	{
		for (i = 0; i < 100; i++)
		{
			if (num[i] > 10)
			{
				printf("%s", num[i] % 2 ? "张永豪" : "生日快乐，天天开心！！！！");
			}
			else
				printf(" ");
			if (num[i]-- < 0)
				num[i] = rand() % 20;
		}
		system("color  3");
		printf("\n");
	}
}