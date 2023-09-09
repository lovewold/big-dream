#define _CRT_SECURE_NO_WARNINGS 1
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 
//的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //简单两数求和，主要是熟悉leetcode在线OJ的代码风格。
//注意事项：要求返回值的需要返回
//          要求需要开辟内存的要自己去开辟
//          只需要确定函数部分的逻辑

//本题逻辑。for循环嵌套查找，时间复杂度为O(N^n);不能查找重复的，依次遍历暴力即可
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
//哈希表实现
















//两数相加，表示两个非负的整数