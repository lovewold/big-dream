#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void fun(int* p, int n, int* max, int* min)
//{
//	int i;
//	*max = p[0];
//	*min = p[0];
//	for (i = 1; i < n; i++)
//	{
//		if (*max < p[i])
//			*max = p[i];
//		if (*min > p[i])
//			*min = p[i];
//	}
//}
//void main()
//{
//	int a[] = { 8,2,5,-3,7,-9,0,-4,10,15 };
//	int max = 0;
//	int min = 0;
//	fun(&a, 10, &max, &min);
//	printf("max=%d  min=%d\n", max, min);
//}

//#include <stdio.h>
//void fun(char* s)
//{
//    int i, j, n;
//    for (i = 0; s[i] != '\0'; i++)
//        if (s[i] >= 'a' && s[i] <= 'z')
//        {
//            n = 0;
//            while (s[i + 1 + n] != 0)
//            {
//                n++;
//            }    
//            for (j = i + n + 1; j >= i; j--)
//                s[j + 1] = s[j];
//           s[i+1]='$';
//        }
//}
//void main()
//{
//    char s[80] = "cq2013cct1c";
//    printf("\nThe original string is : %s\n", s);
//    fun(s);
//    printf("\nThe result is : %s\n", s);
//}
//
//#include<stdio.h>
//int main()
//{
//    int i, j, a;
//    void del(char* str, char c);
//    char str[100], c;
//    printf("ÇëÊäÈë×Ö·û´®:\n");
//    gets(str);
//    printf("ÇëÊäÈëÐèÒªÉ¾³ýµÄ×Ö·û:\n");
//    scanf("%c", &c);
//    for (a = 0; str[a] != '\0'; a++)
//        for (i = a; i >= 0; i--)
//        {
//            if (str[i] == c)
//            {
//                for (j = i; j <= a + 1; j++)
//                    str[j] = str[j + 1];
//            }
//        }
//    printf("É¾³ýºóµÄ×Ö·û´®:");
//    puts(str);
//    return 0;
//}

//#include <stdio.h>
//int chrn(char* s, char c)
//{
//    int i = 0, j = 0;
//    while (s[i] != '\0')
//    {
//
//        if (s[i] == c)
//            j++; i++;
//
//    }
//    return j;
//}
//void main()
//{
//    char s[10], c;
//    gets(s);
//    c = getchar();
//    chrn(s, c);
//    printf("%d", chrn(s, c));
//}
//
//#include <stdio.h>
//void fun(char* s)
//{
//    int i, j, n;
//    for (i = 0; s[i] != '\0'; i++)
//        if (s[i] >= 'a' && s[i] <= 'z')
//        {
//            n = 0;
//            while (s[i + 1 + n] != 0)
//            {
//                n++;
//            }
//            for (j = i + n + 1; j >= i; j--)
//                s[j + 1] = s[j];
//            s[i + 1] = '$';
//        }
//}
//void main()
//{
//    char s[80] = "cq2013cct1c";
//    printf("\nThe original string is : %s\n", s);
//    fun(s);
//    printf("\nThe result is : %s\n", s);
//}
//#include <stdio.h>
//int chrn(char* s, char c)
//{
//    int i = 0, j = 0;
//    while (s[i] != '\0')
//    {
//
//        if (s[i] == c)
//            j++; i++;
//
//    }
//    return j;
//}
//void main()
//{
//    char s[10], c;
//    gets(s);
//    c = getchar();
//    chrn(s, c);
//    printf("%d", chrn(s, c));
//}

//#include<stdio.h>
//int length(char* a)
//{
//	int i = 0;
//	while (*a != '\0')
//	{
//		a++;
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	int s;
//	char a[100];
//	scanf("%s", &a);
//	length(a);
//	s = length(a);
//
//	printf("×Ö·û´®µÄ³¤¶È£º%d\n", s);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a[] = "my teacher is sucker.";
//	char b[30];
//	int i;
//	for (i = 0; *(a + i) != '\0'; i++)
//	{
//		*(b + i) = *(a + i);
//	}
//	*(b + i) = '\0';
//	printf("aÊÇ:%s\n", a);
//	printf("b ÊÇ:\n");
//	for (i = 0; b[i] != '\0'; i++)
//	{
//		printf("%c", b[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int i, j, a;
//    void del(char* str, char c);
//    char str[100], c;
//    printf("ÇëÊäÈë×Ö·û´®:\n");
//    gets(str);
//    printf("ÇëÊäÈëÐèÒªÉ¾³ýµÄ×Ö·û:\n");
//    scanf("%c", &c);
//    for (a = 0; str[a] != '\0'; a++)
//        for (i = a; i >= 0; i--)
//        {
//            if (str[i] == c)
//            {
//                for (j = i; j <= a + 1; j++)
//                    str[j] = str[j + 1];
//            }
//        }
//    printf("É¾³ýºóµÄ×Ö·û´®:");
//    puts(str);
//    return 0;
//}
#include<stdio.h>
void cat(char* s, char* t)
{
	while (*s !='\0')
		s++;
	while ((*s++ = *t++) != '\0');
}
void main()
{
	char s1[80] = "world!", s2[80] = "Hello_";
	cat(s2, s1);
	printf("%s\n", s2);
}








