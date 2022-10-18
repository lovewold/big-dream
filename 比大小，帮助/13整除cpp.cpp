#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int i = 1;
    int j = 0;
    int max = 0;
    for (i = 1; i <= 1000; i++)//利用for循环创造1~1000的数
    {
        if (i % 13 == 0)//取模判断是否被13整除
        {
            if (i > j)//若整除i定大于max=0;后使每一个值同max比较，定是后面大于max
            {
                max = i;//再把反复赋值给max
            }
            else
            {
                max = j;
                
            }
            j = i;
            printf("%d ", max);
        } //打印最大的能被13整除的1~1000内的数

    }

    return 0;
}