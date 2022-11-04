#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//执行魔法公式
int count = 0;
void mofa(int* x)
{
	int a = 0;
	a = *x / 2;
	*x = (int)sqrt((double)a);
	count++;
}
//计算到底有多长
int my_strlen(long long* arr)
{
	int LONG = 0;
	while (arr!=0)
	{
		LONG++;
		arr + 1;
	}
	return LONG;
}
//找一个数组相同元素,并使用魔法公式；
//找一段数字独一无二（这个值左右两旁没有一样的）最大值，并用魔法，
int find(long long* str)
{
	int i = 0;
	int* max = 0;
	for (i = 0; i < my_strlen(str);i++)
	{
		if (str[i] > str[i + 1])
			max = str[i];
		else if (str[i] < str[i + 1])
			max = str[i + 1];
		else
			continue;
	}
	mofa(max);
}


int main()
{
	
	int n = 0;
	long long h = 0;
	int i = 1;
	scanf("%d", n);
	long long arr[200000];
	while (i <= n)
	{
		scanf("%lld", h);
		arr[i - 1] = h;
		i++;
	}
	
		
}