#define _CRT_SECURE_NO_WARNINGS 1

  
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//#include<stdio.h>
//#include<malloc.h>
//int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize)
//{
//    int* pairs = (int*)malloc(spellsSize * 4);
//    int i = spellsSize;
//    *returnSize = i;
//    while (i-- > 0)
//    {
//        int size = 0;
//        for (int j = 0; j < potionsSize; j++)
//        {
//            if ((spells[i] * potions[j]) >= success)
//            {
//                size++;
//            }
//        }
//        printf("%d", size);
//        pairs[i] = size;
//    }
//    return pairs;
//
//
//}

//calloc ==malloc+memset
//realloc ���ݣ�ԭ�����ݺ�������ݣ� 
//
#include<iostream>
using namespace std;


class A
{
public:
	A(int date = 0)
	{
		_date = date;
		printf("a()  ");
		printf("_date=%d\n", _date);

	}
	~A()
	{
		printf("~a()\n");
	}
private:
	int _date;
};
int main()
{
	printf("____________a__________________\n");
	A* a = new A;
	delete a;

	printf("____________b__________________\n");
	A* b = new A(10);
	delete b;

	printf("____________c__________________\n");
	A* c = new A[10];
	delete[] c;
	printf("____________d__________________\n");
	A* d = new A[5]{ 1,2,3,4 };
	delete[] d;
	return 0;
}
//
////void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	if (p1 == NULL)
//	{
//		perror("malloc");
//		exit(EXIT_FAILURE);
//	}
//	free(p1);
//}
//#include<stdlib.h>
//void Test()
//{
//	int* p1 = (int*)calloc(4,sizeof(int));
//	if (p1 == NULL)
//	{
//		perror("calloc");
//		exit(EXIT_FAILURE);
//	}
//	int* p2 = (int*)calloc(p1, sizeof(int)*10);
//	if (p1 == NULL)
//	{
//		perror("malloc");
//		exit(EXIT_FAILURE);
//	}
//	free(p3);
//}

//void Test()
//{
//    //��̬����һ��int���͵Ŀռ�
//    int* ptr1 = new int;
//    //��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//    int* ptr2 = new int(10);
//    //��̬����10��int���͵Ŀռ�
//    int* ptr3 = new int[10];
//
//    delete ptr1;//�ͷŵ�������Ŀռ�
//    delete ptr2;
//    delete[] ptr3;//�ͷ�����ռ�
//
////}
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//    char* p2 = nullptr;
//    try 
//    {
//        char* p2 = new char[1024u * 1024u * 1024u * 2u - 1];
//    }
//    catch (const exception& e) 
//    {
//        cout << e.what() << endl;
//    }
//    printf("%p\n", p2);
//
//    return 0;
//}

//#include <iostream>
//#include <new>
//
//void* operator new(std::size_t size) {
//    void* ptr = std::malloc(size);
//    std::cout << "�Զ���new������ " << size << " �ֽڵ��ڴ棬���ַ�ռ�Ϊ " << ptr << std::endl;
//    return ptr;
//}
//
//void operator delete(void* ptr) noexcept {
//    std::cout << "�Զ��� delete���ͷ��˵�ַΪ " << ptr << " ���ڴ�" << std::endl;
//    std::free(ptr);
//}
//
//int main() {
//    int* p = new int;
//    delete p;
//
//    int* arr = new int[5];
//    delete[] arr;
//
//    return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//// ��λnew/replacement new
//int main()
//{
//	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;  // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
//	
//	p1->~A();
//	free(p1);
//
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();//������ʾ�ĵ����������������캯�������ԡ�
//	operator delete(p2);
//	return 0;
//}

