#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
////class Date
////{
////public:
////	Date(int year, int month, int day,const int N)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////
////	const int _N;//
////};
//
////class Date
////{
////public:
////	Date(int year, int month, int day)
////	{
////		_N = 1;
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////
////	const int _N;//
////};
//
////class Date
////{
////public:
////	Date(int year, int month, int day)
////		:_year(year),
////		_month(month),
////		_day(day),
////		_month(month),
////		_N(1)
////	{};
////private:
////	int _year;
////	int _month;
////	int _day;
////
////	const int _N;//
////};
//
////class Date
////{
////public:
////	Date(int year, int month, int day)
////		:_N(1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	};
////private:
////	int _year;
////	int _month;
////	int _day;
////
////	const int _N;//
////};
//
////class Time
////{
////public:
////	Time(int hour = 0)
////		:_hour(hour)   //初始化列表
////	{
////		cout << "Time()" << endl;
////	}
////private:
////	int _hour;
////};
////class Date
////{
////public:
////	Date(int day)  //Date构造并未对Time类进行操作
////	{}
////private:
////	int _day;
////	Time _t;  //自定义成员变量;
////};
////int main()
////{
////	Date d(1);
////	return 0;
////}
//
////class A {
////public:
////	A(int a)
////		:_a1(a)
////		,_a2(_a1)  // 先执行它
////	{}
////
////	void Print() 
////	{
////		cout << "_a1 = " << _a1  << "  " << "_a2 = " << _a2 << endl;
////	}
////private:
////	int _a2;   // _a2 先声明
////	int _a1;
////};
////
////int main() {
////	A aa(1);
////	aa.Print();
////}
////
//class Date {
//public:
//	/*Date(int year)
//		: _year(year)
//	{
//		;
//	}*/
//	explicit Date(int year)
//		: _year(year)
//	{
//		;
//	}
//	void Printf()
//	{
//		cout << _year << endl;
//	}
//
//private:
//	int _year;
//};
//
//int main(void)
//{
//	Date d1(2022);
//	cout << "d1-> ";
//	d1.Printf();
//	Date d2 = 2022;    // 隐式类型转换
//	cout << "d2-> ";
//	d2.Printf();
//
//	return 0;
//}

//int N = 0;  // 全局变量计数器
//class A {
//public:
//	A(int a = 0)
//		: _a(a) 
//	{
//		N++;
//	}
//	A(const A& aa)
//		: _a(aa._a) 
//	{
//		N++;
//	}
//private:
//	int _a;
//};
//void f(A a)
//{
//	;
//}
//int main(void)
//{
//	A a1;
//	A a2 = 1;
//	f(a1);
//	cout << N << endl;
//	return 0;
//}
//int N = 0;  // 全局变量计数器
//class A {
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		N++;
//	}
//	A(const A& aa)
//		: _a(aa._a)
//	{
//		N++;
//	}
//private:
//	int _a;
//};
//void f(A a)
//{
//	;
//}
//int main(void)
//{
//	A a1;
//	A a2 = 1;
//	f(a1);
//	N--;
//	cout << N << endl;
//	return 0;
//}
//class A {
//public:
//	A(int a = 0)
//		: _a(a) {
//		_N++;
//	}
//	A(const A& aa)
//		: _a(aa._a) {
//		_N++;
//	}
//
//private:
//	int _a;
//	static int _N;  
//};
//int _N = 0;
//int main(void)
//{
//	A a1;
//	A a2 = 1;
//	f(a1);
//	cout << N << endl;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{};
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2023, 4, 22);
//	/*cout << d1;*/
//	d1.operator<<(cout);
//	d1 << cout;
//	return 0;
//}
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin,Date& d);
//public:
//	Date(int year= 1970, int month = 1, int day = 1 )
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)//要修改，别加const
//{
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d;
//	return 0;
//}
class A {
private:
	static int _s_a1;
	int _a2;
public:
	class B 
	{
		// B天生就是A的友元
	public:
		void foo(const A& a) 
		{
			cout << _s_a1 << endl;  
			cout << a._a2 << endl;  
		}
	private:
		int _b1;
	};
};