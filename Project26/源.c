#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ѡ������
void select(int arr[], int len)
{
    int i, j, min, temp; 
    for (i = 0; i < len - 1; i++) 
    { //���ѭ������ѡ�������
        min = i; //���赱ǰλ��Ϊ��Сֵλ��
        for (j = i + 1; j < len; j++)
        { 
            if (arr[j] < arr[min]) 
            { 
                min = j; 
            }
        }
        if (min != i) 
        { 
            temp = arr[i]; //������ǰλ�ú���Сֵλ�õ�Ԫ��
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
//��������
void insert(int arr[], int len)
{
    int i, j, k;
    for (i = 0; i < len; i++)
    { 
        k = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[i] > k)
        {
            arr[j + 1] = arr[j];
            j--;
            
       }
        arr[j + 1] = k;
    }
}
//ð������
void bubble(int arr[], int len) {
    int i, j, temp; 
    for (i = 0; i < len - 1; i++) 
    { 
        for (j = 0; j < len - 1 - i; j++) 
        { 
            if (arr[j] > arr[j + 1])
            { //���ǰ���Ԫ�ش��ں����Ԫ��
                temp = arr[j]; //��������Ԫ�ص�λ��
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//��ӡ����
void print(int arr[], int len) {
    int i; //����ѭ������
    for (i = 0; i < len; i++) { //��������
        printf("%d ", arr[i]); //��ӡÿ��Ԫ��
    }
    printf("\n"); //����
}
int main() {
    int arr[10] = { 9, 3, 56, 44, 77, 88, 54, 79, 52, 111 }; //����һ�������������
    int len = sizeof(arr) / sizeof(arr[0]); //��������ĳ���

    printf("ԭʼ���飺\n");
    print(arr, len); //��ӡԭʼ����

    printf("ѡ�������\n");
    select(arr, len); //����ѡ��������
    print(arr, len); //��ӡ����������

    printf("���������\n");
    insert(arr, len); //���ò���������
    print(arr, len); //��ӡ����������

    printf("ð�������\n");
    bubble(arr, len); //����ð��������
    print(arr, len); //��ӡ����������

    return 0;
}