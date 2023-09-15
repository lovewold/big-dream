#define _CRT_SECURE_NO_WARNINGS 1
//#include<malloc.h>
////缺陷：对于numssize<k的案例会出错，没有考虑到翻转情况
//void rotate(int* nums, int numsSize, int k)
//{
//    if (numsSize > k)
//    {
//        int arr[1000] = { 0 };
//        int i = 0;
//        for (i = 0; i < k; i++)
//        {
//            arr[i] = nums[numsSize - k + i];
//        }
//        for (i = 0; i <= numsSize - 1 - k; i++)
//        {
//            nums[numsSize - 1 - i] = nums[numsSize - 1 - k - i];
//        }
//        for (i = 0; i < k; i++)
//        {
//            nums[i] = arr[i];
//        }
//    }
//
//}
//
//////缺陷：对于numssize<k的案例会出错，没有考虑到翻转情况
//void rotate(int* nums, int numsSize, int k)
//{
//    int tem = 0;
//    int i = 0;
//    //第一次交换
//    for (i = 0; i < (numsSize - 1) / 2; i++)
//    {
//        tem = nums[i];
//        nums[i]=nums[numsSize - 1-i];
//        nums[numsSize - 1-i] = tem;
//    }
//    // too
//    for (i = 0; i < (k - 1) / 2; i++)
//    {
//        tem = nums[i];
//        nums[i] = nums[k - 1 - i];
//        nums[k - 1 - i] = tem;
//    }
//    //
//    for (i = 0; i < (numsSize- 1-k) / 2; i++)
//    {
//        tem = nums[k+i];
//        nums[k+i] = nums[numsSize - 1 - i];
//        nums[numsSize - 1 - i] = tem;
//    }
//}

void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		++count;
	}
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
}

