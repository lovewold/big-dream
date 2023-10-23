#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int Date::GetMonthDay(int year, int month)
{
	int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//闰年判断
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 29;
	}
	return Month[month];
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (month < 1 || month > 12
		|| day < 1 || day > GetMonthDay(year, month))
	{
		cout << "非法日期" << endl;
		// exit(-1);
	}
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
void Date::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}


Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date& Date::operator+=(int day)
{
	if (_day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp(*this);
	tmp += 1;
	return tmp;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	tmp -= 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if(_year==d._year&&_month>d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d)
{
	return !(*this > d);
}
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}
bool Date::operator!= (const Date & d)
{
	return !(*this == d);
}
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flog = 1;
	int day = 0;
	if (*this < d)
	{
		max = d;
		min = *this;
		flog = -1;
	}
	while (min != max)
	{
		++min;
		++day;
	}
	return day * flog;
	
}




