#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{

	float a;
	short b, c, d;
	short count = 0;
	scanf("%f", &a);
	for (b = a*20; b >= 1; b--)
	{
		for (c = a*50; c >= 1; c--)
		{
			for (d = a*100; d >= 1; d--)
			{
				if ((b * 0.05 + c * 0.02 + d * 0.01) == a/100.0)
				{
					printf("fen5:%hd, fen2:%hd, fen1:%hd\n", b, c, d);
					count++;
				}
			}
		}
		
	}
	printf("count = %d", count);
	return 0;

}