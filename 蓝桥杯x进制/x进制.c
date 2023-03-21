#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{


	int N,Ma = 0;
	int ma[100000] = { 0 };
	int Mb = 0;

	int mb[100000] = { 0 };
	
	scanf("%d", &N);
	scanf("%d", &Ma);
	int i = 0;
	for (i = 0; i < ma; i++)
	{
		scanf("%d ", &ma[i]);
	}
	
	scanf("%d", &Mb);
	for (i = 0; i < Mb; i++)
	{
		scanf("%d ", &mb[i]);
	}


	return 0;
}