#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
#include<stdio.h>
int main()
{
	Date d1(2023, 10, 23);
	d1.Print();
	Date d2(2023,11,24);
	d2.Print();
	Date d3(2023, 11, 24);
	d3.Print();

	if (d1 > d2)
	{
		printf("d1 > d2\n");
	}
	else if(d1 < d2)
	{
		printf("d1 < d2\n");
	}
	else if (d2 == d3)
	{
		printf("d2==d3\n");
	}
	d2++.Print();
	printf("Ïà²î%dÌì", d1 - d2);
	
	return 0;
}
