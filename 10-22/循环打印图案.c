#define _CRT_SECURE_NO_WARNINGS 1
//
// ������ͼ��
// #include<stdio.h>
//int main()
//{
//	int i = 0;
//	int a = 0;
//	int b = 0;
//
//	scanf("%d", &i);
//	for (a = 0; a < i; a++)
//	{
//		for (b = 0; b < i; b++)
//		{
//			printf("* ");
//		}printf("\n");
//	}
//	return 0;
//}
////�������룬ֱ��������ͼ��
//#include <stdio.h>
//
//int main() {
//    int a, b, c;
//    while (scanf("%d", &a) != EOF) {
//        for (b = 1; b <= a; b++)
//        {
//            for (c = 1; c <= b; c++)
//            {
//                printf("* ");
//            }printf("\n");
//        }
//
//
//    }
//    return 0;
//}
//��ת������
//#include <stdio.h>
//
//int main() {
//    int a = 0;
//    int i = 0;
//    int b = 0;
//    while (scanf("%d", &a) != EOF)
//    {
//        for (i = 1; i <= a; i++)
//        {
//            for (b = 0; b < a - (i - 1); b++)
//            {
//                printf("* ");
//            }printf("\n");
//        }
//    }
