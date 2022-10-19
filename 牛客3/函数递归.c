#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int compute(int num) {
    int sum = 0;
    while (num) {
        int t = num % 10;
        num /= 10;
        sum += t;
    }
    return sum;
}
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    sum = compute(n); //µÚÒ»ÂÖ
    while (sum > 9) {
        sum = compute(sum);
    }
    printf("%d", sum);
    return 0;
}