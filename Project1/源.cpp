#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int j = 0;
    while (j + 1 < n)
    {
        int ret = (arr[j] - arr[j + 1]);
        if (ret < 0)
        {
            ret *= (-1);
        }
        if (ret<1 || ret>(n - 1))
        {
            cout << "Not jolly" << endl;
            break;
        }
        j++;
    }
    if (j + 1 >= n)
    {
        cout << "Jolly" << endl;
    }
    return 0;
}