#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capcity;
}ST;
//ջ�ĳ�ʼ��
void STInit(ST* ps);

//��ջ
void STpush(ST* ps, STDataType x);
//ջ��ɾ��
void STPop(ST* ps);
//��ջ
STDataType STTop(ST* ps);
//����ջ�ռ�
void STDestroy(ST* ps);
//��ȡջԪ�ظ���
int STsize(ST* ps);
//�п�
bool STEmpty(ST* ps);