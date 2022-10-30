#define _CRT_SECURE_NO_WARNINGS 1


/*#include<stdio.h>
int main()
{
	printf("hello world\n");
	return 0;
}*///crtl +F5
//char short int long 
//float double

//int main()
//{
//	char ch = 'a';
//	int age = 20;
//	float weight = 55.8;
//	double d = 0.0;
//	return 0;
//}32位64位
//char 字符型 输出输入%c
//short int long 输入输出十进制%d 十六进制%x 8进制%o
//"abcde"字符串  输入输出字符串 %s
//float double 输入输出 %f
// 打印地址 %p
//
//#include<stdio.h>
//int main()
//{
//	printf("%d\n", 100);
//	printf("%c\n", 'c');
//
//	float a = 5.0;
//	printf("%f\n", a);
//
//	double p = 3.14;
//	printf("%.2f\n", p);
//	char str1[] = "hello";
//	printf("%s\n", str1);
//	return 0;
//}
//
//sizeof获取数据在内存中所占空间储存空间，1gb=1024mb=1024kb
        
//1kb=1024byte=8bit
#include<stdio.h>
int age = 2;//全局变量
#define a 3;//常量
const b = 3.14;
//int main()
//{
//	int b = 0;
//	scanf("%d,%d", &a,&b);//scanf("数据格式\占位符"，&a);
//	int c = 0;
//	c = a + b;
//	printf("%d", c);
//	return 0;
//}
#include <stdio.h> //下面代码，打印结果是什么？为什么？（突出'\0'的重要性） 
int main() 
{ char arr1[] = "bit\0";
char arr2[] = {'b', 'i', 't'};
char arr3[] = {'b', 'i', 't', '\0'}; 
printf("%s\n", arr1);
printf("%s\n", arr2); 
printf("%s\n", arr3);
return 0;
}
