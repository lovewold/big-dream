#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main() {
    int n, l, p = 0;
    scanf("%d", &n);
    for (int i = 0; i < 3 * n; i++) {
        l = i / 3 + 1; //��ǰ���ڲ㣬����һ�㣬�ڵڼ���ʹ�ӡ�������ǣ�
        for (int j = 0; j < n - l; j++) { //�ո��� = ���� * 3
            printf("   ");
        }
        for (int k = 0; k < l; k++) {
            p = i % 3; //�������εĵڼ���
            if (!p)
                printf("  *   ");
            else if (p == 1)
                printf(" * *  ");
            else
                printf("* * * ");
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3 * n; j++) {
            if (j == 3 * n - 1)
                printf("*\n");
            else
                printf(" ");
        }
    }
    return 0;
}