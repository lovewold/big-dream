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
//realloc 扩容（原地扩容和异地扩容） 
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
//    //动态申请一个int类型的空间
//    int* ptr1 = new int;
//    //动态申请一个int类型的空间并初始化为10
//    int* ptr2 = new int(10);
//    //动态申请10个int类型的空间
//    int* ptr3 = new int[10];
//
//    delete ptr1;//释放单个对象的空间
//    delete ptr2;
//    delete[] ptr3;//释放数组空间
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
//    std::cout << "自定义new分配了 " << size << " 字节的内存，其地址空间为 " << ptr << std::endl;
//    return ptr;
//}
//
//void operator delete(void* ptr) noexcept {
//    std::cout << "自定义 delete：释放了地址为 " << ptr << " 的内存" << std::endl;
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
//// 定位new/replacement new
//int main()
//{
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;  // 注意：如果A类的构造函数有参数时，此处需要传参
//	
//	p1->~A();
//	free(p1);
//
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();//可以显示的调用析构函数，构造函数不可以。
//	operator delete(p2);
//	return 0;
//}

