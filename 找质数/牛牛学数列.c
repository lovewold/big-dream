#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int a;
    int b = 0;
    double sum = 0;
    scanf("%d", &a);
    for (b = 1; b <= a; b++)
    {
        sum += 1.0 / b;
    }
    printf("%.6lf", sum);
    return 0;
}