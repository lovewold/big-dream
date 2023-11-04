#define _CRT_SECURE_NO_WARNINGS 1
#include <cfloat>
#include <climits>
#include <iostream>
using namespace std;
#include<stdio.h>


class Date
{
public:
    int _year;
    int _month;
    int _day;
    int _d;
    Date(int year = 0, int month = 1, int day = 1, int d = 0)
        :_year(year)
        , _month(month)
        , _day(day)
        , _d(d)
    {}


    void myprintf()
    {
        int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        _day += _d;

        while (_day > arr[_month])
        {
            if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0)
            {
                arr[2] = 29;
            }
            _day -= arr[_month];
            _month++;
            if (_month > 12) {
                _year += 1;
                _month = 1;
                arr[2] = 28;
            }
        }
        printf("%04d-%02d-%02d\n", _year, _month, _day);
    }

};


int main()
{

    int i = 0;
    cin >> i;
    Date arr[i];
    for (int j = 0; j < i; j++)
    {
        cin >> arr[j]._year >> arr[j]._month >> arr[j]._day >> arr[j]._d;
    }

    for (int j = 0; j < i; j++)
    {
        arr[j].myprintf();
    }

    return 0;


}