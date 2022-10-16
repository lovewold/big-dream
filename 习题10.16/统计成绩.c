#define _CRT_SECURE_NO_WARNINGS 1
//输入n科成绩（浮点数表示），统计其中的最高分，最低分以及平均分。
//
//数据范围：1 \le n \le 100 \1≤n≤100  ， 成绩使用百分制且不可能出现负数
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d\n", &n);
    int i = 0;
    float arr[10] = { 0.0 };
    float jieguo = 0;
    float max = 0;
    float min = 200;
    for (i = 0; i < n; i++)//输入成绩并储存
    {
        scanf("%f", &jieguo);
        arr[i] = jieguo;
    }

    for (i = 0; i < n; i++)//枚举比较求MAX
    {
        if (arr[i] > max)
            max = arr[i];
    }
    for (i = 0; i < n; i++)//最小值
    {
        if (arr[i] < min)
            min = arr[i];
    }
    float sum = 0;
    for (i = 0; i < n; i++)//求和后续算平均值
    {
        sum += arr[i];
    }
    printf("%.2f %.2f %.2f", max, min, sum / n);
    return 0;
}