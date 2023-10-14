#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
using namespace std;
////int main()
////{
////	cout << "Hello World!";
////	return 0;
////}
//
////#include<stdio.h>
////namespace lxw 
////{
////	int rand = 10;
////	namespace lxw1
////	{
////		int rand = 5;
////	}
////}
////namespace lxw
////{
////	int r = 0;
////}
////using namespace lxw;
////int main()
////{
////	
////	printf("%d\n", lxw::rand);
////	printf("%d\n", lxw::rand);
////	printf("%d\n", lxw::rand);
////	printf("%d\n", lxw::rand);
////	printf("%d\n", lxw::lxw1::rand);
////	printf("%d\n", lxw1::rand);
////	printf("%d\n", r);
////	printf("%d\n", lxw::rand);
////	return 0;
//////}
////int sum(int a, int b)
////{
////	return a + b;
////}
////int main()
////{
////	int a = 0;
////	int b = 0;
////	cout << "请输入a b：" << endl;
////	cin >> a >> b;
////	int c = sum(a, b);
////	cout << "输出sum:" << c;
////
////}
//
//
//
//////////////////////////////////
/////////////////////////////////
//#include<iostream>
//using namespace std;
//
//void func(int a = 4)
//{
//
//	cout << a << endl;
//}
////void Func(int a = 10, int b = 100, int c = 1000)
////{
////	cout << a << endl;
////	cout << b << endl;
////	cout << c << endl;
////	cout <<endl;
////}
////
////int main()
////{
////
////	Func();
////	Func(1);
////	Func(1, 2);
////	Func(1, 2, 3);
////
////	return 0;
////}
////
////void Func(int a, int b = 100, int c = 1000)
////{
////	cout << a << endl;
////	cout << b << endl;
////	cout << c << endl;
////	cout << endl;
////}
////
////int main()
////{
////
////	Func(1);
////	Func(1, 2);
////	Func(1, 2, 3);
////
////	return 0;
////}
//
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
////int main()
////{
////	Add(10, 20);
////	Add(10.0, 20);
////	return 0;
////}
//
//
//
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}


//int main()
//{
//	f();
//	f(10);
//	return 0;
//}


//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//int main()
//{
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}



void TestRef()
{
	int a = 10;
	int& ra = a;//定义引用类型

	printf("%p\n", &a);
	printf("%p\n", &ra);
}
int main()
{
	TestRef();
	return 0;
}