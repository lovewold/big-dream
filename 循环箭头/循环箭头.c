#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int a = 0;
    int i = 1;
    int j = 0;
    int n = 0;
    while (scanf("%d", &a) != EOF)
    {
        for (i = 1; i <= a; i++)
        {
            for (j = 0; j < a * 2 - (i - 1) * 2; j++)
            {
                printf(" ");

            }
            for (n = 0; n < i; n++)
            {
                printf("*");
            }
            printf("\n");
        }
        for (i = 1; i <= a + 1; i++)
        {
            printf("*");
        }printf("\n");
        for (i = 1; i <= a; i++)
        {
            for (j = 1; j <= 2 * i; j++)
            {
                printf(" ");
            }
            for (n = 0; n <= a - i; n++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}