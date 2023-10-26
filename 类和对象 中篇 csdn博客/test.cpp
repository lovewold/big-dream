#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//	return 0;
//}

//class Date
//{
//public:
//	//无参构造
//	Date()
//	{};
//
//	//带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	};
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	
//	// 如果用户显式定义了构造函数，编译器将不再生成
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//void TestDate()
//{
//	Date d1;
//	d1.Print();
//}
//int main()
//{
//	TestDate();
//
////	return 0;
////}
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
//#include <iostream>
//
//class Date {
//public:
//    Date()
//    {
//        _year = 1970;
//        _month = 1;
//        _day = 1;
//    }
//    Date(int year = 1970, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main(void)
//{
//    Date d1;
//
//    return 0;
//}
//#include <iostream>
//
//class Date {
//public:
//    /* 全缺省 */
//    Date(int year = 0, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    void Print() {
//        printf("%d-%d-%d\n", _year, _month, _day);
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main(void)
//{
//    Date d1; // 如果不传，为给定缺省值
//    Date d2(2023, 10, 21);
//    Date d3(2022);
//    Date d4(2012, 4);
//
//    d1.Print();  
//    d2.Print();  
//    d3.Print();  
//    d4.Print();  
//
//    return 0;
//}

//typedef int DateType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DateType*)malloc(sizeof(DateType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请失败！");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void push(DateType data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//	//~~~
//	~Stack()//构析函数
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DateType* _array;
//	int _capacity;
//	int _size;
//};
//
//void TestStack()
//{
//	Stack s;
//	s.push(1);
//	s.push(2);
//}
//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private: 
//	   int _hour;
//	   int _minute;
//	   int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
////}
//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//private:
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// Date(const Date& d) // 正确写法
//	Date(const Date d) // 错误写法：编译报错，会引发无穷递归
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//		cout << "Time::Time(const Time&)" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//
//	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//	// 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
//	Date d2(d1);
//	return 0;
//}
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int minute, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;
//}
//int main()
//{
//	Date d1(2022, 1, 13);
//
//
//	Test(d1);
//
//
//	return 0;
//}
//
// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 这里会发现运算符重载成全局的就需要成员变量是公有的，那么问题来了，封装性如何保证？
//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// bool operator==(Date* this, const Date& d2)
//	// 这里需要注意的是，左操作数是this，指向调用函数的对象
//	bool operator==(const Date & d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return* this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time& operator=(const Time& t)
//	{
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	 Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1; 
//		return temp;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d;
//	Date d1(2022, 1, 13);
//	d = d1++; // d: 2022,1,13 d1:2022,1,14
//	d = ++d1; // d: 2022,1,15 d1:2022,1,15
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << "Print()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Print() const
	{
		cout << "Print()const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void Test()
{
	Date d1(2022, 1, 13);
	d1.Print();
	const Date d2(2022, 1, 13);
	d2.Print();
}

int main()
{
	Test();
	return 0;
}