#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    char star[101];
    char copy[101];
    scanf("%s", &star);
    scanf("%s", &copy);
    int j = 0;
    int i = 0;
    int count = 0;
    while (star[i] != '\0')
    {
        if (star[i] != copy[i])
        {
            j = i;
            do
            {
                j++;
                count++;
            } while (star[j] == copy[j] && star[j] != '\0');
            i = j + 1;
        }
        else
        {
            i++;
        }

    }
    printf("%d", count);
    return 0;
}