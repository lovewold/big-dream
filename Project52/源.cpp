#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	int arr[10000] = { 0 };
//	int max = 0;
//	while (i < n)
//	{
//		scanf("%d", &arr[i]);
//		i++;
//	}
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			sum += arr[j];
//			if (sum > max)
//			{
//				max = sum;
//			}
//		}
//		sum = 0;
//	}
//	printf("%d", max);
//	return 0;
//}
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool is_num(char num)
    {
        if (num <= '0' && num >= '9')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int StrToInt(string str)
    {
        int end = str.size();
        int begin = 0;
        int flog = 1;
        int num = 0;
        int j = 0;
        if (str[begin] == '+' || is_num(str[begin]))
        {
            ;
        }
        else if (str[begin] == '-')
        {
            flog *= -1;
        }
        while (end-- >= begin)
        {

            printf("%c ", str[end]);
            if (is_num(str[end]))
            {
                if (j == 0)
                {
                    num += ((str[end] - '0'));
                }
                else
                {
                    num += (str[end] - '0') * (10 * j);
                }
                j++;
            }

        }
        num *= flog;
        return num;
    }
};

int main()
{
    string a = "+54421";
   
}