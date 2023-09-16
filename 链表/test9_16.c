#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize)
{
    int str = 0;
    int end = 1;
    while (end < numsSize)
    {
        if (nums[str++] != nums[end++])
        {
            ;
        }
        else
        {
            while (nums[end++] == nums[str] && end < numsSize)
            {
                ;
            }
            str++;
            nums[str] = nums[end];
        }
    }
    return str;
}
int main()
{
    int arr[10] = { 1,1,2,3,4,5,5,5,6,7 };
    removeDuplicates(&arr, 10);
    return 0;
}