#define _CRT_SECURE_NO_WARNINGS 1
//����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target 
//���� ���� ���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
//����԰�����˳�򷵻ش𰸡�

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //��������ͣ���Ҫ����Ϥleetcode����OJ�Ĵ�����
//ע�����Ҫ�󷵻�ֵ����Ҫ����
//          Ҫ����Ҫ�����ڴ��Ҫ�Լ�ȥ����
//          ֻ��Ҫȷ���������ֵ��߼�

//�����߼���forѭ��Ƕ�ײ��ң�ʱ�临�Ӷ�ΪO(N^n);���ܲ����ظ��ģ����α�����������
#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        int j = 0;
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == (target - nums[j]))
            {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
//��ϣ��ʵ��
















//������ӣ���ʾ�����Ǹ�������