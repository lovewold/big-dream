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
//�м���

//��ʼ��
void Infocontact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(Contact* pc);

//Ѱ��ָ����ϵ��
void SearchContact(const Contact* pc);

//������ϵ����Ϣ
void ModifyContact(Contact* pc);

//��ʾ��ϵ����Ϣ
void ShowContact(const Contact* pc);

//����ͨѶ¼��ϵ����Ϣby_name
void SortContact(Contact* pc);

