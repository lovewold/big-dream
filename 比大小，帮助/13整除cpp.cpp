#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int i = 1;
    int j = 0;
    int max = 0;
    for (i = 1; i <= 1000; i++)//����forѭ������1~1000����
    {
        if (i % 13 == 0)//ȡģ�ж��Ƿ�13����
        {
            if (i > j)//������i������max=0;��ʹÿһ��ֵͬmax�Ƚϣ����Ǻ������max
            {
                max = i;//�ٰѷ�����ֵ��max
            }
            else
            {
                max = j;
                
            }
            j = i;
            printf("%d ", max);
        } //��ӡ�����ܱ�13������1~1000�ڵ���

    }

    return 0;
}