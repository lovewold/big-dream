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
//}32λ64λ
//char �ַ��� �������%c
//short int long �������ʮ����%d ʮ������%x 8����%o
//"abcde"�ַ���  ��������ַ��� %s
//float double ������� %f
// ��ӡ��ַ %p
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
//sizeof��ȡ�������ڴ�����ռ�ռ䴢��ռ䣬1gb=1024mb=1024kb
        
//1kb=1024byte=8bit
#include<stdio.h>
int age = 2;//ȫ�ֱ���
#define a 3;//����
const b = 3.14;
//int main()
//{
//	int b = 0;
//	scanf("%d,%d", &a,&b);//scanf("���ݸ�ʽ\ռλ��"��&a);
//	int c = 0;
//	c = a + b;
//	printf("%d", c);
//	return 0;
//}
#include <stdio.h> //������룬��ӡ�����ʲô��Ϊʲô����ͻ��'\0'����Ҫ�ԣ� 
int main() 
{ char arr1[] = "bit\0";
char arr2[] = {'b', 'i', 't'};
char arr3[] = {'b', 'i', 't', '\0'}; 
printf("%s\n", arr1);
printf("%s\n", arr2); 
printf("%s\n", arr3);
return 0;
}
