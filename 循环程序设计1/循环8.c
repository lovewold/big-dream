#define _CRT_SECURE_NO_WARNINGS 1
//¥Ú”°≥À∑®±Ì
#include<stdio.h>
int main()
{
	int i = 1;
	int j = 1;
	int n = 1;
	int cheng = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1,n=i; j <= 9; j++,n++)
		{
			if (n > 9)
			{
				break;
			}
		    printf("%d*%d=%-2d  ", j, n, j * n);
			
			
		}
		printf("\n");
	}
	return 0;
}