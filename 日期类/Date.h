#pragma once
#include<iostream>
using namespace std;
class Date
{
public:

	//��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	//ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);

	Date(const Date& d);
};