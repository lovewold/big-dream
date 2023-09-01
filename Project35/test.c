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
    // 在内存中仅仅改变了一个字节

    // 解引用操作时就不一样了
    // 整型指针操作了4个字节，让四个字节变为0
    // 字符指针能把地址交到内存中，
    // 但是解引用操作时，只敢动1个字节

    return 0;
}