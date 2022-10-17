#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int MAX(x, y)
{
	int max;
	max=(x > y ? x:y);
	return max;
}
int main()
{
	int a = 0;
	int b = 0;
	int max;
	scanf("%d %d", &a, &b);
	max=MAX(a, b);
	printf("%d",max);
	return 0;
}