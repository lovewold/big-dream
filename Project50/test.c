#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char i = 0;
	scanf("%c", &i);
	if (i == ' ')
	{
		printf("���ַ�\n");
	}
	else if ('a' <= i && i <= 'z')
	{
		printf("Сд�ַ�\n");
	}
	else if (i >= 'A' && i <= 'Z')
	{
		printf("��д�ַ�\n");
	}
	return 0;
}