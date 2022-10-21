#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int max = 0;
	scanf("%d %d", &a, &b);
	int i = 0;
	if (a >= b)
		i = b;
	else
		i = a;
	int c = 0;
	for (c = 1; c <= i; c++)
	{
		if (a % c == 0 && b % c == 0)
		{
			max = c;
		}
	}
	printf("%d", max);
	return 0;
}