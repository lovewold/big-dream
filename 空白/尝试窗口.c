#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			if (i = 5)
//				printf("%d ", i);
//		}
//	return 0;
//}
#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 2;
//    if (a == 1)
//    {
//        if (b == 2)
//            printf("hehe\n");
//    }
//    else
//    {
//        printf("haha\n");
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 2;
//    if (a == 1)
//        if (b == 2)
//            printf("hehe\n");
//    else
//            printf("haha\n");
//
//    return 0;
//}
#include <stdio.h>
int main()
{
    int n = 1;
    int m = 2;
    switch (n)
    {
    case 1: m++;
    case 2: n++;
    case 3:
        switch (n)
        {//switch‘ –Ì«∂Ã◊ π”√
        case 1: n++;
        case 2:
            m++; n++;
            break;
        }
    case 4:
        m++;
        break;
    default:
        break;
    }
    printf("m = %d, n = %d\n", m, n);
    return 0;
}