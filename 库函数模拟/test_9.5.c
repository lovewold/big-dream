#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现strlen函数
//#include<stdio.h>
//size_t my_strlen(char* p)
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
//模拟实现strcpy
#include<stdio.h>
#include<string.h>
char* my_strcpy(char* copy,const char* source)
{
	//用下标访问，不改变首元素地址
	int i = 0;
	while (source[i++] != '\0')//遍历查找
	{
		copy[i-1] = source[i - 1];//拷贝
	}
	copy[i] = source[i];//最后一位\0也拷贝过来，否则字符数组没有终止符号
	return copy;
}
int main()
{
	char arr[] = "ILOVEYOU";
	char cpy[20] = { 0 };
	my_strcpy(cpy, arr);
	printf("原字符数组%s —》拷贝字符数组%s", arr, cpy);
	return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "ILOVEYOU";
//	char cpy[20] = { 0 };
//	strcpy(cpy, arr);
//	printf("原字符数组%s  —》 拷贝字符数组%s", arr, cpy);
//	return 0;
//}
////
//比较str1和str2大小的函数
////模拟实现strcmp
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1);
//	assert(s2);
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//		{
//			return 0;
//		}
//		s1++;
//		s2++;
//	}
//		return  (*s1 - *s2);
//}
//int main()
//{
//	char str1[] = "abcd";
//	char str2[] = "abc";
//	int i = my_strcmp(str1, str2);
//	if (my_strcmp(str1, str2) < 0)
//	{
//		printf("%s 比 %s 小", str1, str2);
//	}
//	else if(my_strcmp(str1, str2) == 0)
//	{
//		printf("%s 和 %s 相等", str1, str2);
//		
//	}
//	else
//	{
//		printf("%s 比 %s 大", str1, str2);
//	}
//	return 0;
//}
//// 
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
////	return dest-1;
//////}
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcat(char* dest, const char* source)
//{
//		assert(dest);
//		assert(source);
//		char* dest_end = dest;
//		while (*dest_end != '\0')
//		{
//			dest_end++;
//		}
//		while (*source != '\0')
//		{
//			*dest_end = *source;
//			dest_end++;
//			source++;
//			
//		}
//		*dest_end = *source;
//		return dest_end;
//}
//
//int main()
//{
//	char arr[100] = {0};
//	my_strcat(arr, "I ");
//	my_strcat(arr, "love ");
//	my_strcat(arr, "you ");
//	my_strcat(arr, "forever");
//	my_strcat(arr, "!");
//	printf("%s", arr);
//	return 0;
//}
//
//#include<stdio.h>
////模拟实现strlen
//size_t my_strlen(const char* s)
//{
//	int count = 0;
//	while (*s++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char str1[] = "abde";
//	char str2[] = "sadndd";
//
//	printf("str1 %d str2 %d ", my_strlen(str1),my_strlen(str2));
//	printf("str1 %s str2 %s", str1, str2);
//
//
//
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	if (strlen("abc")> strlen("abcdef") > 0)
//	{
//		printf("大于\n");
//	}
//	else
//	{
//		printf("小于等于\n");
//	}
//	return 0;
//}
//
//
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(char* str1, char* str2)
//{
//	assert(str1);
//	assert(str2);
//	while(*str1)
//	{
//		char* s1 = str1;
//		char* s2 = str2;
//		while (*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return str1 ;
//		str1++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char str1[] = "iloveyou";
//	char str2[] = "ove";
//	printf("%s",my_strstr(str1, str2));
//	return 0;
////}
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str1[] = "abbcd";
//    char str2[] = "abbdd";
//    if (strcmp(str1, str2) < 0)
//    {
//        printf("%s 比 %s 小", str1, str2);
//    }
//    else if(strcmp(str1, str2) == 0)
//    {
//        printf("%s 和 %s 相等", str1, str2);
//
//    }
//    else
//    {
//        printf("%s 比 %s 大", str1, str2);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[80];
//	strcpy(str, "I ");
//	strcat(str, "LOVE ");
//	strcat(str, "YOU ");
//	strcat(str, "FOREVER!");
//	puts(str);
//	return 0;
////}
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcat(char* dest, const char* source)
//{
//	assert(dest);
//	assert(source);
//	char* dest_end = dest;//额外指针指向目标字符数组首元素位置，保证移动指针不丢失原先字符串位置
//	while (*dest_end != '\0')//循环遍历找到目标数组的'\0'位置
//	{
//		dest_end++;//目标位置指针移步
//	}
//	while (*source != '\0')//来源字符串循环便利，终止位置为'\0'
//	{
//		*dest_end = *source;//覆盖
//		dest_end++;
//		source++;//并行指针移步添加
//
//	}
//	*dest_end = *source;//因为最后的终止位置为'\0',所以直接赋值为source的最后一位即可
//	return dest_end;//返回终止位置
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	my_strcat(arr, "I ");
//	my_strcat(arr, "love ");
//	my_strcat(arr, "you ");
//	my_strcat(arr, "forever");
//	my_strcat(arr, "!");
//	printf("%s", arr);
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str1[] = "iloveyou";
//	char str2[] = "ove";
//	printf("%s",strstr(str1, str2));
//	return 0;
//}
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(char* str1, char* str2)
//{
//	assert(str1);
//	assert(str2);//判断传递参照指针是否为空
//	while(*str1)//终止条件为str1遍历到'\0'
//	{
//		char* s1 = str1;
//		char* s2 = str2;//地址拷贝
//		while (*s1 == *s2)//查找str1字符串中str2首元素相同的位置
//		{
//			s1++;
//			s2++;//同步移位比较
//		}
//		if (*s2 == '\0')//成功标志，str2遍历完全
//			return str1 ;//返回str1中查找到的子字符串起始位置
//		str1++;//一次查找没有找到，继续找下一次首元素相同位置
//	}
//	return NULL;
//}
//
//int main()
//{
//	char str1[] = "iloveyou";
//	char str2[] = "ove";
//	printf("%s",my_strstr(str1, str2));
//	return 0;
//}