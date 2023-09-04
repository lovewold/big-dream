//#define _CRT_SECURE_NO_WARNINGS 1
////void qsort(void* base, //指向了需要排序的数组的第一个元素
////           size_t num, //排序的元素个数
////           size_t size,//一个元素的大小，单位是字节
////           int (*cmp)(const void*, const void*)//函数指针类型 - 这个函数指针指向的函数，能够比较base指向数组中的两个元素
////          );
////
//#include <stdlib.h>
//#include<stdio.h>
//int cmp_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
////
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
////
//////测试qsort排序整型数据
//test1()
//{
//	int arr[10] = { 3,1,5,2,4,7,9,6,8,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//默认是升序的
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print(arr, sz);
//}
////
//////测试qsort排序结构体数据
////struct Stu
////{
////	char name[20];
////	int age;
////};
////
////int cmp_stu_by_age(const void* p1, const void* p2)
////{
////	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
////}
////
////void test2()
////{
////	struct Stu arr[] = { {"zhangsan", 20}, {"lisi", 50},{"wangwu", 15} };
////	int sz = sizeof(arr) / sizeof(arr[0]); 
////	qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
////}
////
////int cmp_stu_by_name(const void* p1, const void* p2)
////{
////	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
////}
////
////void test3()
////{
////	struct Stu arr[] = { {"zhangsan", 20}, {"lisi", 50},{"wangwu", 15} };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
////}
////
////int main()
////{
////	test1();
////	////test2();
////	//test3();
////
////	return 0;
////}