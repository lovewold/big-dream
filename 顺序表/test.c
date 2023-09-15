#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void test1()
{
	SL S1;
	SLinit(&S1);
	SLPushback(&S1, 1);
	SLPushback(&S1, 1);
	SLPushback(&S1, 1);
	SLPushback(&S1, 1);
	SLPushback(&S1, 1);
	SLPushback(&S1, 2);
	SLPushback(&S1, 2);
	SLPushback(&S1, 2);
	Print(&S1);
	printf("\n");
	SLPopback(&S1);
	SLPopback(&S1);
	SLPopback(&S1);

	Print(&S1);
	printf("\n");

	SLPushback(&S1, 3);
	SLPushback(&S1, 3);
	SLPushback(&S1, 3);
	Print(&S1);
	printf("\n");
}
void test2()
{
	SL S1;
	SLinit(&S1);

	SLPushFront(&S1, 666);
	SLPushFront(&S1, 666);
	SLPushFront(&S1, 666);
	SLPushFront(&S1, 666);
	SLPushFront(&S1, 666);
	Print(&S1);
}
void test3()
{
	SL S1;
	SLinit(&S1);

	SLPushFront(&S1, 1);
	SLPushFront(&S1, 2);
	SLPushFront(&S1, 3);
	SLPushFront(&S1, 4);
	SLPushFront(&S1, 5);
	Print(&S1);
	printf("\n");
	SeqListInsert(&S1, 3, 0);
	Print(&S1);
	printf("\n");

	SeqListErase(&S1, 1);
	Print(&S1);
	printf("\n");

	int ret = SeqListFind(&S1, 3);
	if (ret != -1)
	{
		printf("查找数字 3 在第 %d位 ",ret);
	}
	else 
	{
		printf("no find");
	}


}
int main()
{
	
	test1();
	test2();
	test3();

	return 0;
}