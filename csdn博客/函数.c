#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


void swap(int* x, int* y);//��������

int main()
{
    /* �ֲ��������� */
    int a = 100;
    int b = 200;

    printf("����ǰ��a ��ֵ�� %d\n", a);
    printf("����ǰ��b ��ֵ�� %d\n", b);

    /* ���ú���������ֵ */
    swap(&a, &b);//���ݲ�����ַ

    printf("������a ��ֵ�� %d\n", a);
    printf("������b ��ֵ�� %d\n", b);

    return 0;
}
void swap(int* x, int* y)//��������Ӧ�ù涨���ݵ��ǵ�ַ
{
    int temp;//�м���

    temp = *x;//�����ı��ַ��Ԫ��ֵ
    *x = *y;
    *y =temp;

}