#define _CRT_SECURE_NO_WARNINGS 1
//3*N
//n个队伍
//水平值为第二大
//排序
//排序。1 2 3 4 5 6 7 8 9 
//
//n     
//             size=arr n*2       (size - 1) >= 1; size -= 2;


#include <stdio.h>

int flog_arr(int a, int b)
{

    int flog = 0;
    if (b - a > 0)
    {
        flog = 1;
    }
    else if (b - a < 0)
    {
        flog = -1;
    }
    else
    {
        flog = 0;
    }
    return flog;
}
int main()
{
    int arr[10086];
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int pos = 1;
    if (n > 2)
    {
        for (i = 1; i < n - 1; i++)
        {
            if (flog_arr(arr[i - 1], arr[i]) != flog_arr(arr[i], arr[i+1]))
            {
                if (flog_arr(arr[i - 1], arr[i]) && flog_arr(arr[i], arr[i + 1]))
                {
                    pos++;
                    
                    if (i == n - 1 && flog_arr(arr[i - 1], arr[i]) != flog_arr(arr[i], arr[i + 1]))
                    {
                        pos++;
                    }
                    i++;
                    
                }
            }
        }
    }
    printf("%d",pos);
    return 0;
}