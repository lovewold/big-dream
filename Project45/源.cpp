#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <time.h>
struct A { int a[10000]; };
A a;
// ֵ����
A TestFunc1() { return a; }
// ���÷���
A& TestFunc2() { return a; }
void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}
int main()
{
	//TestRefAndValue();
	TestReturnByRefOrValue();
	return 0;
}