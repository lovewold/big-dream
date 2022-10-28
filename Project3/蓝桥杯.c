#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


int main()
{
    // 请在此输入您的代码
    char arr[1000] = {0};
    int c = 0;
    char j = 0;
    int z = 0;
    int count = 0;
    int i = 0;
    int len[26] = {0};
    scanf("%s", arr);
    for (z = 0; z <= 1000; z++)
    {
        if (arr[z] == 0)
        {
            i = z + 1;
            break;
        }
    }
   

    for (j = 'a', z = 0; j < 'z'; j++, z++)
    {
            for (c = 0; c < i-1; c++)
            {
                if (j == arr[c])
                {
                    count++;
                }
            }
            len[z] = count;
            count = 0;
    }
    int temp = 0;

    for (temp = i; temp > 0; temp--)
    {
        for (z = 0; z <= 25; z++)
        {
            if (temp == len[z])
            {
                printf("%c\n", z + 97);
                printf("%d\n", temp);
                goto feileisheng;
            }

        }
    }feileisheng:

    return 0;
}