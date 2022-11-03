#define _CRT_SECURE_NO_WARNINGS 1
//·Çµİ¹é
#include<stdio.h>
int my_strlen(char* x)
{
	int count = 0;
	while(*x != '\0')
	{
		count++;
		x++;

	}
	return count;
}
//µİ¹éÊµÏÖ
int my_strlen1(char* x)
{
	if (*x != '\0')
	{
		return 1 + my_strlen1(x+1);
	}
	else
		return 0;
}
int main()
{
	char arr[]="adbbh";
	int ret = my_strlen(arr);
	int ter = my_strlen1(arr);
	printf("%d %d", ret,ter);
	return 0;
}
