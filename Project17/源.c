#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void PrintN(int N)
{
    int i;
    for (i = 1; i <= N; i++)
        printf("%d\n", i);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    PrintN(n);
    return;
}