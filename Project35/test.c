#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(double*));
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 112;
//	int b = -1;
//	float c = 3.14;
//	int *d = &a;
//	float* e = &c;
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int a = 0x11223344;
//    int* pa = &a;
//    char* pc = &a;
//    printf("%p\n", pa);
//    printf("%p\n", pc);
//
//    return 0;
//}
#include<stdio.h>
int main()
{
    int a = 0x11223344;
    int* pa = &a; // 44 33 22 11 
    *pa = 0;// 00 00 00 00

    char* pc = &a; // 44 33 22 11
    *pc = 0; // 00 33 22 11
    // ���ڴ��н����ı���һ���ֽ�

    // �����ò���ʱ�Ͳ�һ����
    // ����ָ�������4���ֽڣ����ĸ��ֽڱ�Ϊ0
    // �ַ�ָ���ܰѵ�ַ�����ڴ��У�
    // ���ǽ����ò���ʱ��ֻ�Ҷ�1���ֽ�

    return 0;
}