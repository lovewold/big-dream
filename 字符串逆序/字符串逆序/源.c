#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void lixv(char* left, char* right)
{
	while (left < right)
	{
		char temp = 0;
		temp = *left;
		*left = *right;
		*right = temp;
		left++; 
		right--;
	}
}
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	int sz = strlen(arr);
	lixv(arr, arr + sz - 1);
	char* p = arr;


	while (*p)//ָ��'\0'������
	{
		char* d = p;
		while (*d != ' ' && *d != '\0')
		{
			d++;
		}
		lixv(p, d - 1);//�Խ�������������
		if (*p == ' ')//�������������־
		{
			p = d + 1;
		}
		else
		{
			p = d;
		}
	}
	printf("%s", arr);
	return 0;
}