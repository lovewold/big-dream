#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day,const int N)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _N;//
//};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_N = 1;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _N;//
//};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year),
//		_month(month),
//		_day(day),
//		_month(month),
//		_N(1)
//	{};
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _N;//
//};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_N(1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	};
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _N;//
//};

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)   //��ʼ���б�
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)  //Date���첢δ��Time����в���
//	{}
//private:
//	int _day;
//	Time _t;  //�Զ����Ա����;
//};
//int main()
//{
//	Date d(1);
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a1(a)
//		,_a2(_a1)  // ��ִ����
//	{}
//
//	void Print() 
//	{
//		cout << "_a1 = " << _a1  << "  " << "_a2 = " << _a2 << endl;
//	}
//private:
//	int _a2;   // _a2 ������
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	aa.Print();
//}
//
class Date {
public:
	/*Date(int year)
		: _year(year)
	{
		;
	}*/
	explicit Date(int year)
		: _year(year)
	{
		;
	}
	void Printf()
	{
		cout << _year << endl;
	}

private:
	int _year;
};

int main(void)
{
	Date d1(2022);
	cout << "d1-> ";
	d1.Printf();
	Date d2 = 2022;    // ��ʽ����ת��
	cout << "d2-> ";
	d2.Printf();

	return 0;
}
