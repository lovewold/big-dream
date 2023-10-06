#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int trap(int* height, int heightSize)
{
    if (height == NULL || heightSize <= 2)
    {
        return 0; // �߶�����Ϊ�ջ򳤶�С�ڵ���2ʱ�޷���ˮ
    }
    int count = 0;
    int tmp = 0;

    int left = 0;
    int right = (heightSize - 1);
    int i = 1;
    while (left < right)
    {

        while (left < right && (height[left]<i || i>height[right]))
        {
            if (height[left] < i)
            {
                left++;
            }
            if (height[right] < i)
            {
                right--;
            }
        }
        tmp = left;

        while (tmp < right)
        {
            if (height[tmp++] < i)
            {

                count++;
            }
        }
        i++;
    }
    return count;
}