#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int my_len(char arr[])
{
    int len = 0;
    while ((arr[len]-'0') >= 0 && (arr[len]-'0') <= 10)
    {
        len++;
    }
    return len;
}
int main()
{
    int len = 0;

    char arr[10001] = { 0 };
    int i = 0;
    scanf("%s", arr);
    int p = 0;
    while (arr[i] != '\0')
    {
        if (arr[i]-'0' >= 0 && arr[i]-'0'<= 10)
        {

            int ret = my_len(&arr[i]);
            if (len < ret)
            {
                len = ret;
                p = i;
                i += len;
            }
        }
        i++;
    }

    for (i = 0; i < len; i++)
    {
        printf("%c", arr[p]);
        p++;
    }
    return 0;
}