#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void TestRef()
{
	int a = 10;
	 /*int& ra; */// ����������ʱ�����
	int& ra = a;
	int& rra = a;
	printf("%p %p %p\n", &a, &ra, &rra);
}
//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a; // ��������ʱ�����aΪ����
//	const int& ra = a;
//	// int& b = 10; // ��������ʱ�����bΪ����
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
//	const int& rd = d;
//}

void Swap(int x, int y)
{
	int tmp = x;
	x = y; 
	y = tmp;
}
//int main()
//{
//	int a = 100;
//	int b = 1;
//	Swap(a, b);
//	cout << "��ֵ���ý��--" << " a:" << a << " b:" << b << endl;
//	Swap_r(a, b);
//	cout << "�����õ��ý��--" << " a:" << a << " b:" << b << endl;
//
//	return 0;
//}
void Swap_r(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add(1, 2) is :" << ret << endl;
//	cout << "Add(1, 2) is :" << ret << endl;
//	Add(3, 4);
//	cout << "Add(3, 4) is :" << ret << endl;
//	cout << "Add(3, 4) is :" << ret << endl;
//
//	return 0;
//}
//int& Add(int a, int b,int& sum)
//{	
//	sum = a + b;
//	return sum;
//}
//int main()
//{
//	int sum = 0;
//	int& ret = Add(1, 2,sum);
//	cout << "Add(1, 2) is :" << ret << endl;
//	cout << "Add(1, 2) is :" << ret << endl;
//	Add(3, 4,sum);
//	cout << "Add(3, 4) is :" << ret << endl;
//	cout << "Add(3, 4) is :" << ret << endl;
//
//	return 0;
//}




//
//int main()
//{
//	int a = 3;
//	int& ra = a;
//	int* pa = &a;
//	cout << "ra:" << ra << endl;
//	cout << "pa:"<< *pa << endl;
//	return 0;
//}
//
//#include <time.h>
//struct A { int a[100000]; };
//void TestFunc1(A a) {};
//void TestFunc2(A& a) {};
//void TestRefAndValue()
//{
//	A a;
//	
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}
//#include <time.h>
//struct A { int a[1000]; };
//
//void TestFunc1(A aa) {}
//
//void TestFunc2(A& aa) {}
//
//void TestRefAndValue()
//{
//	A a;
//	 ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	 ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	 �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//
//	TestRefAndValue();
//	return 0;
// 
////}
//
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* p = &a;
//	*p = 20;
//
//	return 0;
//}
//inline int Max(int x, int y)//��������
//{
//	return (x > y) ? x : y;
//}
//
//int main()
//{
//
//	cout << "Max (20,10): " << Max(20, 10) << endl;
//	cout << "max(20,20): " << max(0&0,1*20) << endl;
//	return 0;
//}
