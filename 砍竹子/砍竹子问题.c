#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//ִ��ħ����ʽ
int count = 0;
void mofa(int* x)
{
	int a = 0;
	a = *x / 2;
	*x = (int)sqrt((double)a);
	count++;
}
//���㵽���ж೤
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
//��һ��������ͬԪ��,��ʹ��ħ����ʽ��
//��һ�����ֶ�һ�޶������ֵ��������û��һ���ģ����ֵ������ħ����
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