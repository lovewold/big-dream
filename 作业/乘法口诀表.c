#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
#include<stdio.h>
void chengfa(int x)
{
	int i = 0;
	int c = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for(c=1,j=i+1;c<=x-i;c++,j++)
		{ 
			printf("%2d*%-2d=%3d ", c, j, (c * j));
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	scanf("%d",&n);

	chengfa( n );

	return 0;
}