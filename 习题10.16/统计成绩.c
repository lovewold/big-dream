#define _CRT_SECURE_NO_WARNINGS 1
//����n�Ƴɼ�����������ʾ����ͳ�����е���߷֣���ͷ��Լ�ƽ���֡�
//
//���ݷ�Χ��1 \le n \le 100 \1��n��100  �� �ɼ�ʹ�ðٷ����Ҳ����ܳ��ָ���
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d\n", &n);
    int i = 0;
    float arr[10] = { 0.0 };
    float jieguo = 0;
    float max = 0;
    float min = 200;
    for (i = 0; i < n; i++)//����ɼ�������
    {
        scanf("%f", &jieguo);
        arr[i] = jieguo;
    }

    for (i = 0; i < n; i++)//ö�ٱȽ���MAX
    {
        if (arr[i] > max)
            max = arr[i];
    }
    for (i = 0; i < n; i++)//��Сֵ
    {
        if (arr[i] < min)
            min = arr[i];
    }
    float sum = 0;
    for (i = 0; i < n; i++)//��ͺ�����ƽ��ֵ
    {
        sum += arr[i];
    }
    printf("%.2f %.2f %.2f", max, min, sum / n);
    return 0;
}