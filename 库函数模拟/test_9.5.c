#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现strlen函数
//#include<stdio.h>
//int my_strlen(char* p)
//{
//	int count = 0;
//	while (*p++ != '\0')
//		count++;
//	
//	return count;
//}
//int main()
//{
//	char arr[] = "abdhsshi";
//	
//	printf("字符串长度为 %d ", my_strlen(arr));
//	return 0;
//}
//自己优化
//#include<stdio.h>
//int my_strlen(char* p)
//{
//	int count = 0;
//	while (p[count++] != '\0');
//	return count-1;
//}
//int main()
//{
//	char arr[] = "abdhsshi";
//
//	printf("字符串长度为 %d ", my_strlen(arr));
//	return 0;
//}
////模拟实现strcpy
//#include<stdio.h>
//#include<string.h>
//char* my_strcpy(char* copy,const char* source)
//{
//	int i = 0;
//	while (source[i++] != '\0')
//	{
//		copy[i-1] = source[i - 1];
//	}
//	copy[i] = '\0';
//	return copy;
//}
//int main()
//{
//	char arr[] = "chen";
//	char cpy[20] = { 0 };
//	my_strcpy(cpy, arr);
//	printf("原字符数组%s  拷贝字符数组%s", arr, cpy);
//	return 0;
//}

//比较str1和str2大小的函数
//模拟实现strcmp
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 != NULL);
//	assert(s2 != NULL);
//	while ( (*s1 == *s2)&& s1!='\0')
//	{
//		s1++;
//		s2++;
//	}
//	return *s1-*s2;
//}
//int main()
//{
//	char str1[] = "asdff";
//	char str2[] = "asdfff";
//	int i = my_strcmp(str1, str2);
//	if (i << 0)
//	{
//		printf("%s str1比str2小", str1);
//	}
//	else if (i == 0)
//	{
//		printf("str1等于str2小");
//	}
//	else
//	{
//		printf("str1等于str2大");
//	}
//	return 0;
//}
// 
// 
// 模拟实现连接字符串函数，用于将需要追加的字符串组成一个新的字符串，并且目的地字符串末尾有终止符号
//char* strcat(char* destination, const char* source);

//char* my_strcat(char* dest, const char* source)
//{
//	assert(dest);
//	assert(source);
//	while (*source != '\0')
//	{
//		while (*dest != 0)
//		{
//			dest++;
//		}
//		*dest = *source;
//		source++;
//	}
//	*++dest= '\0';
//	return dest-1;
//}
#include<stdio.h>
#include<assert.h>

char* my_strcat(char* dest, const char* source)
{
		assert(dest);
		assert(source);
		char* dest_end = dest;
		while (*dest_end != '\0')
		{
			dest_end++;
		}
		while (*source != '\0')
		{
			*dest_end = *source;
			dest_end++;
			source++;
			
		}
		*dest_end = '\0';
		return dest_end;
}

int main()
{
	char arr[100] = {0};
	my_strcat(arr, "I ");
	my_strcat(arr, "love ");
	my_strcat(arr, "you ");
	my_strcat(arr, "forever");
	my_strcat(arr, "!");
	printf("%s", arr);
	return 0;
}