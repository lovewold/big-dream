#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void PRINTF(int x)
{
	if (x > 9)
	{
		PRINTF(x/10);	
	}
	printf("%d ", x%10);
	
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	PRINTF(n);
	return 0;
}