#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int DigitSum(int x)
{
	if (x > 9)
	{
		return x % 10 + DigitSum(x / 10);
	}
	else if (x < 9)
	{
		return x;
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = DigitSum(n);
	printf("%d", ret);
	return 0;
}