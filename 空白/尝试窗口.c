#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a;
	float b;
	double c;
	char ch;
	printf("«Î ‰»Îa,b,c,chµƒ÷µ£∫");
	scanf("%d %f %lf %c", &a, &b, &c, &ch);
	printf("a = %d,b = %f,c= %lf,ch= %c", a, b, c, ch);
	putchar("\n");
	return 0;
}
