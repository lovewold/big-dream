#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	scanf("%d", &i);
	printf("%d%d%d",i%10,i/10%10,i/100%10);
	
}


