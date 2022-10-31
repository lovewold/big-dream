#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int n = 0;
	scanf("%d %d %d", &a, &b, &n);
	int xingqi = 5 * a + 2 * b;
	int c = 0;
	int d = 0;
	d = n / xingqi;
	c = n % xingqi;
	int i = 0;
	int j = 0;
	for (i = 1; i <= 5; i++)
	{
		if (i * a >= c)
		{
			printf("%d", d * 7 + i);
			goto feileisheng;
		}
		if (i == 5 && i * 5 < c)
		{
			for (j = 1; j <= 2; j++)
			{
				if ((5 * a + j * b) >= c)
				{
					printf("%d", d * 7 + 5 + j);
					goto feileisheng;
				}
			}
		}
	}feileisheng:
	
	return 0;
}