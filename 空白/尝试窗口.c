#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b;
	int c = scanf("%d %d", &a, &b);
	printf("%d", c);
	while (scanf("%d %d", &a, &b))
	{
		if (a > b)
		{
			printf("%d %d", b, a);
		}
	     
	}
	return 0;
}
