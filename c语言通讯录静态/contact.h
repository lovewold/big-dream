#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>

#define MAX 100
#define MAX_name 20
#define MAX_sex 5
#define MAX_tele 12
#define MAX_addr 30


enum OPTION
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

typedef struct PenInfo
{
	char name[MAX_name];
	int age;
	char sex[MAX_sex];
	char tele[MAX_tele];
	char addr[MAX_addr];

}PenInfo;

typedef struct Contact
{
	PenInfo date[MAX];
	int sz;
}Contact;
//中间量

//初始化
void Infocontact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//寻找指定联系人
void SearchContact(const Contact* pc);

//更改联系人信息
void ModifyContact(Contact* pc);

//显示联系人信息
void ShowContact(const Contact* pc);

//排序通讯录联系人信息by_name
void SortContact(Contact* pc);

