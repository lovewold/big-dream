#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//选择排序
void select(int arr[], int len)
{
    int i, j, min, temp; 
    for (i = 0; i < len - 1; i++) 
    { //外层循环控制选择的轮数
        min = i; //假设当前位置为最小值位置
        for (j = i + 1; j < len; j++)
        { 
            if (arr[j] < arr[min]) 
            { 
                min = j; 
            }
        }
        if (min != i) 
        { 
            temp = arr[i]; //交换当前位置和最小值位置的元素
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
//插入排序
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
//冒泡排序
void bubble(int arr[], int len) {
    int i, j, temp; 
    for (i = 0; i < len - 1; i++) 
    { 
        for (j = 0; j < len - 1 - i; j++) 
        { 
            if (arr[j] > arr[j + 1])
            { //如果前面的元素大于后面的元素
                temp = arr[j]; //交换两个元素的位置
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//打印数组
void print(int arr[], int len) {
    int i; //定义循环变量
    for (i = 0; i < len; i++) { //遍历数组
        printf("%d ", arr[i]); //打印每个元素
    }
    printf("\n"); //换行
}
int main() {
    int arr[10] = { 9, 3, 56, 44, 77, 88, 54, 79, 52, 111 }; //定义一个待排序的数组
    int len = sizeof(arr) / sizeof(arr[0]); //计算数组的长度

    printf("原始数组：\n");
    print(arr, len); //打印原始数组

    printf("选择排序后：\n");
    select(arr, len); //调用选择排序函数
    print(arr, len); //打印排序后的数组

    printf("插入排序后：\n");
    insert(arr, len); //调用插入排序函数
    print(arr, len); //打印排序后的数组

    printf("冒泡排序后：\n");
    bubble(arr, len); //调用冒泡排序函数
    print(arr, len); //打印排序后的数组

    return 0;
}