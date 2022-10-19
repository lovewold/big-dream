#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void main()
//{
//	int i, j;
//	for (i = 0; i < 100; i++)
//	{
//		j = i * 10 + 6;
//		if (j % 3 == 0&&j<100)
//		{
//			printf("%d ", j);
//		}
//	}
//}
#include<stdio.h>
void main()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		j = i * 10 + 6;
		if (j % 3 == 0 && j <100)
			continue;
		printf("%d  ", j);
	}
}
