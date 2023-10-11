#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello World!";
//	return 0;
//}

//#include<stdio.h>
//namespace lxw 
//{
//	int rand = 10;
//	namespace lxw1
//	{
//		int rand = 5;
//	}
//}
//namespace lxw
//{
//	int r = 0;
//}
//using namespace lxw;
//int main()
//{
//	
//	printf("%d\n", lxw::rand);
//	printf("%d\n", lxw::rand);
//	printf("%d\n", lxw::rand);
//	printf("%d\n", lxw::rand);
//	printf("%d\n", lxw::lxw1::rand);
//	printf("%d\n", lxw1::rand);
//	printf("%d\n", r);
//	printf("%d\n", lxw::rand);
//	return 0;
//}

#include<iostream>
using namespace std;

int sum(int a,int b)
{
	return a + b;
}
int main()
{
	int a = 0;
	int b = 0;
	cout << "ÇëÊäÈëa b£º" << endl;
	cin >> a >> b;
	int c = sum(a, b);
	cout << "Êä³ösum:" << c;

}

