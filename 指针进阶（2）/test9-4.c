//#define _CRT_SECURE_NO_WARNINGS 1
////void qsort(void* base, //ָ������Ҫ���������ĵ�һ��Ԫ��
////           size_t num, //�����Ԫ�ظ���
////           size_t size,//һ��Ԫ�صĴ�С����λ���ֽ�
////           int (*cmp)(const void*, const void*)//����ָ������ - �������ָ��ָ��ĺ������ܹ��Ƚ�baseָ�������е�����Ԫ��
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
//////����qsort������������
//test1()
//{
//	int arr[10] = { 3,1,5,2,4,7,9,6,8,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//Ĭ���������
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print(arr, sz);
//}
////
//////����qsort����ṹ������
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