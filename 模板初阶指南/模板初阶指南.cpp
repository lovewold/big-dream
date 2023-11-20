#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//void swap(int& x, int& y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//void swap(double& x, double& y)
//{
//	double temp = x;
//	x = y;
//	y = temp;
//}
//void swap(char& x, char& y)
//{
//	char temp = x;
//	x = y;
//	y = temp;
//}
//
//template<typename T>
//void Swap(T& x,T& y)
//{
//	T temp = x;
//	x = y;
//	y = temp;
//}
////int main()
////{
////	int a = 10;
////	int b = 5;
////	cout << "a=" << a << " " << "b=" << b << endl;
////	Swap(a, b);
////	cout << "swap~" << endl;
////	cout << "a=" << a << " " << "b=" << b << endl;
////	return 0;
////}
//
//int main()
//{
//	int a1 = 10;
//	int a2 = 5;
//	Swap(a1, a2);
//	
//	double b1 = 10.0;
//	double b2 = 5.0;
//	Swap(b1, b2);
//
//	char c1 = '0';
//	char c2 = '8';
//	Swap(c1, c2);
//	return 0;
//}

//template <class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}

//int main()
//{
//	int a1 = 10;
//	int a2 = 5;
//	Add(a1, a2);
//
//	double b1 = 10.0;
//	double b2 = 5.0;
//	Add(b1, b2);
//	Add<int>(a1, b1);
//	return 0;
//}
//专门处理整形类型加法函数
//int Add(int left, int right)
//{
//	cout << "非模板函数" << endl;
//	return left + right;
//}
////通用加法模板
//template<class T>
//T Add(T left, T right)
//{
//	cout << "模板函数" << endl;
//	return left + right;
//}
//void test()
//{
//	Add(1,2);//与非模板函数优先匹配
//	Add(1.0, 2.0);//模板函数
//	Add<int>(1, 2);//调用特定版本的Add版本，走模板函数
//}
//int main()
//{
//	test();
//	return 0;
//}

//int Add(int left, int right)
//{
//	cout << "非模板函数" << endl;
//	return left + right;
//}
////通用加法模板
//template<class T1 , class T2>
//T1 Add(T1 left, T2 right)
//{
//	cout << "模板函数" << endl;
//	return left + right;
//}
//void test()
//{
//	Add(1, 2);//与非模板函数优先匹配
//	Add(1, 2.0);//具备更加匹配的版本而不需要类型转换，编译器优先生成更加匹配的Add函数版本
//}
//int main()
//{
//	test();
//	return 0;
//}

//template<class T1, class T2,class T3>//参数列表可以定义多个模板变量
//class 类模板名
//{
//	//类成员定义
//};
//
//typedef
//
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t  capacity = 10)
//		:_pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//
//	~Vector();
//
//	/*void PushBack(const T& data);
//	void PopBack();*/
//	```
//	size_t Size() { return _size; };
//
//	T& operator[](size_t pos)
//	{
//		assert(pos < _size);
//		return _pData[pos];
//	}
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//类模板函数也可以放在类的外部进行定义，需要模板参数列表
//template<class T>
//Vector<T>::~vector()
//{
//	if (_pData)
//	{
//		delete[] _pData;
//	}
//	_size = _capacity = 0;
//}

#include <cassert>

template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	~Vector();

	// 其他成员函数在这里...

	size_t Size() { return _size; };

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

// 类模板函数定义可以放在类定义外面。
template<class T>
Vector<T>::~Vector()
{
	if (_pData)
	{
		delete[] _pData;
	}
	_size = _capacity = 0;
}

int main()
{
	// 使用 Vector 类模板的示例
	Vector<int> intVector;
	intVector[0] = 42;  // 使用 operator[] 的示例
	// 其他操作...

	return 0;
}




































