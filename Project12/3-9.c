#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int a = 2;
    int b = a << 1; // 将a的二进制位向左移动1位；
    printf("b = %d\n", b); // 4 （左移操作符有乘2的效果）

    /*
           00000000000000000000000000000010
         0|000000000000000000000000000010+0  (左边丢弃，右边补0)
    */

    return (0);
}