#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char i = 0;
	scanf("%c", &i);
	if (i == ' ')
	{
		printf("¿Õ×Ö·û\n");
	}
	else if ('a' <= i && i <= 'z')
	{
		printf("Ð¡Ð´×Ö·û\n");
	}
	else if (i >= 'A' && i <= 'Z')
	{
		printf("´óÐ´×Ö·û\n");
	}
	return 0;
}