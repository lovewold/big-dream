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
//ר�Ŵ����������ͼӷ�����
//int Add(int left, int right)
//{
//	cout << "��ģ�庯��" << endl;
//	return left + right;
//}
////ͨ�üӷ�ģ��
//template<class T>
//T Add(T left, T right)
//{
//	cout << "ģ�庯��" << endl;
//	return left + right;
//}
//void test()
//{
//	Add(1,2);//���ģ�庯������ƥ��
//	Add(1.0, 2.0);//ģ�庯��
//	Add<int>(1, 2);//�����ض��汾��Add�汾����ģ�庯��
//}
//int main()
//{
//	test();
//	return 0;
//}

//int Add(int left, int right)
//{
//	cout << "��ģ�庯��" << endl;
//	return left + right;
//}
////ͨ�üӷ�ģ��
//template<class T1 , class T2>
//T1 Add(T1 left, T2 right)
//{
//	cout << "ģ�庯��" << endl;
//	return left + right;
//}
//void test()
//{
//	Add(1, 2);//���ģ�庯������ƥ��
//	Add(1, 2.0);//�߱�����ƥ��İ汾������Ҫ����ת�����������������ɸ���ƥ���Add�����汾
//}
//int main()
//{
//	test();
//	return 0;
//}

//template<class T1, class T2,class T3>//�����б���Զ�����ģ�����
//class ��ģ����
//{
//	//���Ա����
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
//��ģ�庯��Ҳ���Է�������ⲿ���ж��壬��Ҫģ������б�
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

	// ������Ա����������...

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

// ��ģ�庯��������Է����ඨ�����档
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
	// ʹ�� Vector ��ģ���ʾ��
	Vector<int> intVector;
	intVector[0] = 42;  // ʹ�� operator[] ��ʾ��
	// ��������...

	return 0;
}




































