#define _CRT_SECURE_NO_WARNINGS 1
//ģ��ʵ��strlen����
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
//	printf("�ַ�������Ϊ %d ", my_strlen(arr));
//	return 0;
//}
//�Լ��Ż�
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
//	printf("�ַ�������Ϊ %d ", my_strlen(arr));
//	return 0;
//}
//ģ��ʵ��strcpy
#include<stdio.h>
#include<string.h>
char* my_strcpy(char* copy,const char* source)
{
	//���±���ʣ����ı���Ԫ�ص�ַ
	int i = 0;
	while (source[i++] != '\0')//��������
	{
		copy[i-1] = source[i - 1];//����
	}
	copy[i] = source[i];//���һλ\0Ҳ���������������ַ�����û����ֹ����
	return copy;
}
int main()
{
	char arr[] = "ILOVEYOU";
	char cpy[20] = { 0 };
	my_strcpy(cpy, arr);
	printf("ԭ�ַ�����%s ���������ַ�����%s", arr, cpy);
	return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "ILOVEYOU";
//	char cpy[20] = { 0 };
//	strcpy(cpy, arr);
//	printf("ԭ�ַ�����%s  ���� �����ַ�����%s", arr, cpy);
//	return 0;
//}
////
//�Ƚ�str1��str2��С�ĺ���
////ģ��ʵ��strcmp
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
//		printf("%s �� %s С", str1, str2);
//	}
//	else if(my_strcmp(str1, str2) == 0)
//	{
//		printf("%s �� %s ���", str1, str2);
//		
//	}
//	else
//	{
//		printf("%s �� %s ��", str1, str2);
//	}
//	return 0;
//}
//// 
// 
// ģ��ʵ�������ַ������������ڽ���Ҫ׷�ӵ��ַ������һ���µ��ַ���������Ŀ�ĵ��ַ���ĩβ����ֹ����
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
////ģ��ʵ��strlen
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
//		printf("����\n");
//	}
//	else
//	{
//		printf("С�ڵ���\n");
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
//        printf("%s �� %s С", str1, str2);
//    }
//    else if(strcmp(str1, str2) == 0)
//    {
//        printf("%s �� %s ���", str1, str2);
//
//    }
//    else
//    {
//        printf("%s �� %s ��", str1, str2);
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
//	char* dest_end = dest;//����ָ��ָ��Ŀ���ַ�������Ԫ��λ�ã���֤�ƶ�ָ�벻��ʧԭ���ַ���λ��
//	while (*dest_end != '\0')//ѭ�������ҵ�Ŀ�������'\0'λ��
//	{
//		dest_end++;//Ŀ��λ��ָ���Ʋ�
//	}
//	while (*source != '\0')//��Դ�ַ���ѭ����������ֹλ��Ϊ'\0'
//	{
//		*dest_end = *source;//����
//		dest_end++;
//		source++;//����ָ���Ʋ����
//
//	}
//	*dest_end = *source;//��Ϊ������ֹλ��Ϊ'\0',����ֱ�Ӹ�ֵΪsource�����һλ����
//	return dest_end;//������ֹλ��
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
//	assert(str2);//�жϴ��ݲ���ָ���Ƿ�Ϊ��
//	while(*str1)//��ֹ����Ϊstr1������'\0'
//	{
//		char* s1 = str1;
//		char* s2 = str2;//��ַ����
//		while (*s1 == *s2)//����str1�ַ�����str2��Ԫ����ͬ��λ��
//		{
//			s1++;
//			s2++;//ͬ����λ�Ƚ�
//		}
//		if (*s2 == '\0')//�ɹ���־��str2������ȫ
//			return str1 ;//����str1�в��ҵ������ַ�����ʼλ��
//		str1++;//һ�β���û���ҵ�����������һ����Ԫ����ͬλ��
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