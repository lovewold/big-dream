#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int maxSatisfaction(int* satisfaction, int satisfactionSize)
{
    int* tmp = (int*)malloc(satisfactionSize * 4);
    memcpy(&tmp, &satisfaction, sizeof(int));
    qsort(tmp, satisfactionSize, 4, cmp);
    int i = 0;
    int flog = 0;
    int sum = 0;
    int like_time = 0;
    int max = 0;
    for (i = 0; i < satisfactionSize; i++)
    {
        if (satisfaction[i] < 0)
        {
            flog++;
        }
        else
        {
            break;
        }
    }
    for (int j = 1; j <= satisfactionSize - flog; j++)
    {
        sum += satisfaction[j + flog - 1] * j;
    }
    if (max < sum)
    {
        max = sum;
    }
    while (flog > 0)
    {
        flog--;
        for (int j = 1; j <= satisfactionSize - flog; j++)
        {
            like_time += satisfaction[j + flog - 1] * j;
        }
        if (like_time < max)
        {
            like_time = max;
            break;
        }
        else
        {
            max = like_time;
            like_time = 0;
        }
    }

    return max;
}
