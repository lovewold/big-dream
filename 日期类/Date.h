#pragma once
#include<iostream>
using namespace std;
class Date
{
public:

	//��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	//ȫȱʡ�Ĺ��캯��
	Date(int year = 1990, int month =1, int day=1);

	//�������캯��
	Date(const Date& d);
	
	void Print() const;

	//��ֵ���������
	Date& operator=(const Date& d);

	//����+=����
	Date& operator+=(int day);

	//����+����
	Date operator+(int day);

	//����-����
	Date operator-(int day);

	//����-=����
	Date& operator-=(int day);

	//ǰ��++
	Date& operator++();

	//����++
	Date operator++(int);

	//ǰ��--
	Date operator--(int);

	//����--
	Date& operator--();
	
	//>���������
	bool operator>(const Date& d);

	//==
	bool operator==(const Date& d);

	bool operator>=(const Date& d);

	bool operator<(const Date& d);

	bool operator<=(const Date& d);

	bool operator!=(const Date& d);

	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};