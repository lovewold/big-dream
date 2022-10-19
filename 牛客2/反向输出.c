#define _CRT_SECURE_NO_WARNINGS 1
/*#include <stdio.h>
#include<math.h>

int main() {

    int a = 0;
    int i = 0;
    int v, b, n, m;
    while (scanf("%d", &a) != EOF)
    {
        v = a % 10;
        b = a % 100 / 10;
        n = a % 1000 / 100;
        m = a / 1000;
        printf("%d%d%d%d", v, b, n, m);
    }


    return 0;
}*///我的代码实现
//别人的代码实现
//牛逼
#include<stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    while (a)
    {
        printf("%d", a % 10);
        a = a / 10;
    }
    return 0;
}
