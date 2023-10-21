#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//#include <string>
//#include <map>
//int main()
//{
//	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "orange", "橙子" },
//	{"pear","梨"} };
//	std::map<std::string, std::string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		//....
//	}
//	return 0;
//}
//#include <string>
//#include <map>
//typedef std::map<std::string, std::string> Map;
//int main()
//{
//	Map m{ { "apple", "苹果" },{ "orange", "橙子" }, {"pear","梨"} };
//	Map::iterator it = m.begin();
//	while (it != m.end())
//	{
//		//....
//	}
//	return 0;
//}
//typedef char* pstring;
//int main()
//{
//	const pstring p1; // 编译成功还是失败？
//	const pstring* p2; // 编译成功还是失败？
//	return 0;
////}
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl;//typeid用来确定变量类型
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}
//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << endl;
//}
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : array)
//	{
//		e *= 2;
//		cout << e << " ";
//
//	}
//}
//int main()
//{
//	TestFor();
//
//	return 0;
////}
//
//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	return 0;
//}
//
//class person
//{
//public:
//	void showInfo()
//		{
//			cout << _name << "-" << _sex << "-" << _age << endl;
//		}
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//};
//
//int main()
//{
//	char arr[] = "llll";
//	char sex[] = "nan";
//	person L;
//	L._age = 18;
//	L._name = arr;
//	L._sex = sex;
//	L.showInfo();
////}
//
//class person
//{
//public:
//	void PrintPersonInfo();
//public:
//	char _name[20];
//	char _gender[3];
//	int _age[];
//};
////定义函数方法先指明此函数是属于哪一个类的
//void person::PrintPersonInfo()
////{
////	cout << _name << " " << _gender << " " << _age << endl;
////}
//
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	char _a;
//};

//class A1//既有成员变量又有成员函数
//{
//public:
//	void f1() {};
//private:
//	int _a;
//};
//class A2//仅有成员函数
//{
//public:
//	void f2() {};
//};
//class A3//类中什么都没有
//{};
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//}

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	int a;
};

int main()
{
	Date d1, d2;
	d1.Init(2022, 1, 11);
	d2.Init(2023, 12, 10);
	d1.print();
	d2.print();
}