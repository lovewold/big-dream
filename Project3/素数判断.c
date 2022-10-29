#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int sushu(int x)
{
	int c = 2;
	for (c = 2; c < sqrt(x); c++)
	{
		if (x % c == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}
}
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (sushu(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}