#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int nums[10] = {0};
    int i = 0;
    int j = 0;
    int n = 0;
    int target = 0;
    
    while (scanf("%d", &j) != EOF)
    {
        for (i = 0; i < 10; i++)
        {
            nums[i] = j;
        }
    }
    scanf("%d", &target);
    for (i = 0; i < 10; i++)
    {
        for (n = i+1; n < 10; n++)
        {
            if (nums[n]=target-nums[i] &&nums[i]!=nums[n])
            {
                printf("[%d,%d]", i, n);
            }
        }
    }

    return 0;
}