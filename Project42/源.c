#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1


#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* ps);
void STDestroy(ST* ps);
void STPush(ST* ps, STDataType x);
void STPop(ST* ps);
STDataType STTop(ST* ps);

int STSize(ST* ps);
bool STEmpty(ST* ps);


void STInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void STPush(ST* ps, STDataType x)
{
	assert(ps);
	// 11:40
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)
{
	assert(ps);

	// 
	assert(ps->top > 0);

	--ps->top;
}

STDataType STTop(ST* ps)
{
	assert(ps);

	// 
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

bool isValid(char* s)
{
	ST L;
	STInit(&L);
	char val;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			STPush(&L, *s);
		}
		else
		{
			//数量不匹配，左括号没有的话
			if (STEmpty(&L))
			{
				STDestroy(&L);
				return false;
			}
			val = STTop(&L);
			STPop(&L);
			if ((*s == ')' && val != '(') || (*s == '}' && val != '{') || (*s == ']' && val != '['))
			{
				STDestroy(&L);
				printf("%c", val);
				printf("1%d\n", (*s == ')' && val != '('));
				printf("2%d\n", (*s == '}' && val != '{'));
				printf("3%d\n", (*s == ']' && val != '['));

				return false;
				//括号不匹配
			}
			break;
		}
		++s;

	}
	
	//栈不为空返回false，括号数量不匹配
	bool ret = STEmpty(&L);
	STDestroy(&L);
	return ret;


}
void TestStack1()
{
	ST st;
	char* s = "{()}";
	isValid(s);
}

int main()
{
	TestStack1();

	return 0;
}