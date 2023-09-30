#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void TestStack1()
{
	ST st;
	STInit(&st);
	STpush(&st, 1);
	STpush(&st, 2);
	STpush(&st, 3);
	STpush(&st, 4);
	STpush(&st, 5);

	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
	printf("\n");

	STDestroy(&st);
}

int main()
{
	TestStack1();

	return 0;
}