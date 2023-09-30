#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capcity;
}ST;
//栈的初始化
void STInit(ST* ps);

//入栈
void STpush(ST* ps, STDataType x);
//栈的删除
void STPop(ST* ps);
//出栈
STDataType STTop(ST* ps);
//销毁栈空间
void STDestroy(ST* ps);
//获取栈元素个数
int STsize(ST* ps);
//判空
bool STEmpty(ST* ps);