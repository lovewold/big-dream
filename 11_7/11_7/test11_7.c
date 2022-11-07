#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	/*int a = 3, b = 5, c = 8;
//	if (a++ < 3 && c-- != 0)  b = b + 1;
//	printf("a=%d\tb=%d\tc=%d\n", a, b, c);*/
//
//	/*int a = 3, b = 5, c = 8;
//	if (c-- != 0 && a++ < 3)  b = b + 1;
//	printf("a=%d\tb=%d\tc=%d\n", a, b, c);*/
//
//	/*int a = 3, b = 5, c = 8;
//	if (a++ < 3 || c-- != 0)  b = b + 1;
//	printf("a=%d\tb=%d\tc=%d\n", a, b, c);*/
//
//	int a = 3, b = 5, c = 8;
//	if (c-- != 0 || a++ < 3)  b = b + 1;
//	printf("a=%d\tb=%d\tc=%d\n", a, b, c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	float x = 0;
//	scanf("%f", &x);
//	if (x < 1)
//	{
//		printf("y=%f", x);
//	}
//	else if (1 <=x && x < 10)
//	{
//		printf("y=%f", 2* x - 1);
//	}
//	else
//	{
//		printf("y=%f", 3.0 * x - 11);
//	}
//	return 0;
//}
//
//#include "stdio.h"
//int main()
//{
//    int a, b, t;
//    t = 0;
//    scanf("%d,%d", &a, &b);
//    if (a > b)
//    {
//        t = a;
//        a = b;
//        b = t;
//    }
//    printf("a=%d,b=%d\n", a, b);
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	int temp = 0;
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		if (b > a)
//		{
//			temp = a;
//			a = b;
//			b = temp;
//		}
//		if (c > b)
//		{
//			temp = c;
//			c = b;
//			b = temp;
//		}
//
//	}
//	printf("%d %d %d", a, b, c);
//	
//	return 0;
//}

/* 不含break的switch */        /* 含break的switch */
  //       #include <stdio.h>
  //                int main()
  //{ int a, m = 0, n = 0, k = 0;
		//         scanf("%d", &a);
		//		         switch (a)

		//{ case 1: m++; break;
		//	          case 2:
		//           case 3: n++; break;
		//		           case 4:
	 //          case 5: k++;

		//						}
  //    	printf("%d,%d,%d\n", m, n, k);
		//						}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int n = a / 10;
//	switch (n)
//	{
//	case 10:printf("A\n"); break;
//	case 9:printf("A\n"); break;
//	case 8:printf("B\n"); break;
//	case 7:printf("C\n"); break;
//	case 6:printf("D\n"); break;
//	case 5:
//	case 4:
//	case 3:
//	case 2:
//	case 1:printf("E\n"); break;
//
//	}
//	return 0;
//}
void Printf(int a)
{
	if (a > 0)
	{
		Printf(a / 10);
		printf("%d ", a % 10);
	}
	
}
#include<stdio.h>
int main()
{
	int a = 0;
	scanf("%d",&a);
	int i = 0;
	Printf(a);//正序打印
	printf("\n");
	while (a != 0)
	{
		i++;//几位数
		printf("%d ", a % 10);//逆序打印
		a /= 10;
	}
	printf("\n");
	printf("这个数字是%d位数",i);
	return 0;
}