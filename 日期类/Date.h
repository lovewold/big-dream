#pragma once
#include<iostream>
using namespace std;
class Date
{
public:

	//获取某年某月的天数
	int GetMonthDay(int year, int month);

	//全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	Date(const Date& d);
};