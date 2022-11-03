#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


void swap(int* x, int* y);//声明函数

int main()
{
    /* 局部变量定义 */
    int a = 100;
    int b = 200;

    printf("交换前，a 的值： %d\n", a);
    printf("交换前，b 的值： %d\n", b);

    /* 调用函数来交换值 */
    swap(&a, &b);//传递参数地址

    printf("交换后，a 的值： %d\n", a);
    printf("交换后，b 的值： %d\n", b);

    return 0;
}
void swap(int* x, int* y)//参数定义应该规定传递的是地址
{
    int temp;//中间量

    temp = *x;//交换改变地址下元素值
    *x = *y;
    *y =temp;

}