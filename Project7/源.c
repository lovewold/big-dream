
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void cat(char* s, char* t)
{
	while (*s != '\0')
		s++;
	while ((*s++ = *t++) != '\0');
}
void main()
{
	char s1[80] = "world!", s2[80] = "Hello_";
	cat(s2, s1);
	printf("%s\n", s2);
}

