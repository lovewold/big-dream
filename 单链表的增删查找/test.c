#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"
void test1()//…Í«Îø’º‰∫Õ¥Ú”°≤‚ ‘
{
	SListNode* SL = NULL;
	SListPushBack(&SL,1);
	SListPushBack(&SL,2);
	SListPushBack(&SL,3);
	SListPushBack(&SL,4);
	SListPushBack(&SL,5);
	SListPushBack(&SL,6);
	SListPushBack(&SL,7);
	SListPrint(SL);
	SListPushFront(&SL, 0);
	SListPushFront(&SL, 1);
	SListPushFront(&SL, 2);
	SListPushFront(&SL, 3);
	SListPushFront(&SL, 4);
	SListPushFront(&SL, 5);
	SListPushFront(&SL, 6);
	SListPrint(SL);


}
void test2()//…Í«Îø’º‰∫Õ¥Ú”°≤‚ ‘
{
	SListNode* SL = NULL;
	SListPushFront(&SL, 0);
	SListPushFront(&SL, 1);
	SListPushFront(&SL, 2);
	SListPushFront(&SL, 3);
	SListPushFront(&SL, 4);
	SListPushFront(&SL, 5);
	SListPushFront(&SL, 6);
	SListPrint(SL);
	SListPopFront(&SL);
	SListPopFront(&SL);
	SListPopFront(&SL);
	SListPrint(SL);

	SListPopBack(&SL);
	SListPopBack(&SL);
	SListPopBack(&SL);
	SListPrint(SL);




}
void test3()
{
	SListNode* SL = NULL;
	SListPushBack(&SL, 1);
	SListPushBack(&SL, 2);
	SListPushBack(&SL, 3);
	SListPushBack(&SL, 4);
	/*SListPrint(SL);
	printf("%p\n", SListFind(SL, 3));

	SListPrint(SL);*/
	SListPrint(SL);
	SListInsertAfter(SListFind(SL, 3), 1);
	SListInsertAfter(SListFind(SL, 4), 2);
	SListInsertAfter(SListFind(SL, 4), 3);
	SListPrint(SL);
	SListPrint(SL);




}void test4()
{
	SListNode* SL = NULL;
	SListPushBack(&SL, 1);
	SListPushBack(&SL, 2);
	SListPushBack(&SL, 3);
	SListPushBack(&SL, 4);
	SListPrint(SL);

	SListDestroy(&SL);
	SListPrint(SL);

}
int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}