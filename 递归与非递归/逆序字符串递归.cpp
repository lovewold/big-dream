#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int LONG(char* string)
{
	int n = 0;
	while (*string != '\0')
	{
		string++;
		n++;
	}
	return n;
}

void reverse_string(char* string)
{
	
	int len = LONG(string);
	char temp = *string;
	
	*string = *(string + len-1);
	
	*(string + len - 1) = '\0';
	if (LONG(string + 1) > 1)
	{
		reverse_string(string+1);
		
	}
	*(string + len - 1) = temp;
	
	
}
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s\n",arr);
	return 0;
}
