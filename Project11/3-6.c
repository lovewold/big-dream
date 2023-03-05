#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>;
//#include <assert.h> 
//void my_strcpy(char* dest, const char* str)
//{
//	assert(dest != NULL && str != NULL);
//	while (*dest++ = *str++)
//	{
//		;
//	}
//
//}
#include <assert.h> 
char* my_strcpy(char* dest, const char* str)
{
	assert(dest != NULL && str != NULL);
	char* s = dest;
	while (*dest++ = *str++)
	{
		;
	}
	return s;
}
int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "hello";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}

//#include<stdio.h>
//#include<assert.h>
////unsigned int my_strlen(char* a)
////{
////	assert(a != NULL);
////	int count = 0;
////	while ( *a ++ != '\0')
////	{
////		count++;
////	}
////	return count;
////}
//unsigned int my_strlen(char* a)
//{
//	assert(a != NULL);
//	char* p = a;
//	while (*a++);
//	return a-p-1;
//}
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}