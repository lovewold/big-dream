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
//#include<stdio.h>
//#include<string>
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//    bool is_num(char num)
//    {
//        if (num <= '0' && num >= '9')
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    int StrToInt(string str)
//    {
//        int end = str.size();
//        int begin = 0;
//        int flog = 1;
//        int num = 0;
//        int j = 0;
//        if (str[begin] == '+' || is_num(str[begin]))
//        {
//            ;
//        }
//        else if (str[begin] == '-')
//        {
//            flog *= -1;
//        }
//        while (end-- >= begin)
//        {
//
//            printf("%c ", str[end]);
//            if (is_num(str[end]))
//            {
//                if (j == 0)
//                {
//                    num += ((str[end] - '0'));
//                }
//                else
//                {
//                    num += (str[end] - '0') * (10 * j);
//                }
//                j++;
//            }
//
//        }
//        num *= flog;
//        return num;
//    }
//};
//
//int main()
//{
//    string a = "+54421";
//   
//}
//#include<string>
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    char isAora(char str)
//    {
//        if (str >= 'A' || str <= 'Z')
//        {
//            return str + 32;
//        }
//        return str;
//    }
//    bool isPalindrome(string s)
//    {
//        int begin = 0;
//        int end = s.size() - 1;
//        while (begin <= end)
//        {
//            s[begin] = isAora(s[begin]);
//            s[end] = isAora(s[end]);
//            while (!(s[begin] <= 'z' && s[begin] >= 'a'))
//            {
//                s[begin] = isAora(s[begin]);
//                begin++;
//            }
//            while (!(s[end] <= 'z' && s[end] >= 'a'))
//            {
//                s[end] = isAora(s[end]);
//                end--;
//            }
//            if (s[begin] == s[end])
//            {
//                begin++;
//                end--;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//int main()
//{
//    
//    
//    return 0;
//
//}
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result = "";

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += num1[i--] - '0';
            }
            if (j >= 0)
            {
                sum += num2[j--] - '0';
            }
            carry = sum / 10;
            result += (sum % 10) + '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }
    string multiply(string num1, string num2)
    {
        int next = 0;
        int i = 0;
        int j = num2.size() - 1;
        int end = num2.size() - 1;

        string sum = "0";
        while (j >= 0)
        {
            i = num1.size() - 1;
            string s = "";
            while (i >= 0)
            {
                next = (num1[i] - '0') * (num2[j] - '0');
                s += ((next % 10) + '0');
                next /= 10;
                i--;
            }
            if (next > 0)
                s += ((next % 10) + '0');
            if (j != end)
            {
                s += '0';
            }
            cout << s << endl;
            sum = addStrings(sum, s);
            j--;
        }

        return sum;
    }
};
int main()
{
    string num1 = "123";
    string num2 = "211";
    Solution sol;
    sol.multiply(num1, num2);
    return 0;
}