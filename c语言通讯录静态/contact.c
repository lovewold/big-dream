#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"



//���ڳ����������ڿ��Ա���޸ģ��궨��
//����һ���ṹ�����͵�ͨѶ¼����

//��ʼ��
void Infocontact(Contact* pc)
{
	assert(pc);
	memset(pc->date, 0, sizeof(pc->date));
	pc->sz = 0;
}

static int FindContact_by_name(const Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->date[i].name) == 0)
		{
			return i;
			//�ҵ���Ŀ����ϵ��
		}
	}
	return -1;//�Ҳ���
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼��������\n");
		return;
	}
	printf("��������ϵ������----��  ");
	scanf("%s", &pc->date[pc->sz].name);
	printf("��������ϵ������----��  ");
	scanf("%d", &pc->date[pc->sz].age);
	printf("��������ϵ���Ա�----��  ");
	scanf("%s", &pc->date[pc->sz].sex);
	printf("��������ϵ�˵绰----��  ");
	scanf("%s", &pc->date[pc->sz].tele);
	printf("��������ϵ�˵�ַ----��  ");
	scanf("%s", &pc->date[pc->sz].addr);

	pc->sz++;
	printf("�ɹ���ӵ� %d λ��ϵ��\n",pc->sz);

}
void DelContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼û����ϵ�ˣ��޷�ɾ��\n");
		return;
	}
	char name[MAX_name] = {0};
	printf("������Ҫɾ������ϵ������---��  ");
	scanf("%s", &name);
	int del = FindContact_by_name(pc,name);
	if (del == -1)
	{
		printf("ͨѶ¼û���ҵ�ָ����ϵ����Ϣ\n");
		return ;
	}
	else
	{
		for (i = del; i < pc->sz-1; i++)
		{
			pc->date[i] = pc->date[i + 1];
		}
	}
	pc->sz--;

	printf("�ɹ�ɾ����ϵ��\n");
	

}
void ShowContact(Contact* pc)
{
	printf("%-10s\t%-4s\t%4s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "�绰����", "��ϵ�˵�ַ");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-4d\t%4s\t%-12s\t%-30s\t\n",
			pc->date[i].name,
			pc->date[i].age,
			pc->date[i].sex,
			pc->date[i].tele,
			pc->date[i].addr
		);
	}
	printf("\n");
	printf("\n");
}
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼û����ϵ�ˣ��޷�����\n");
		return;
	}
	char name[MAX_name] = { 0 };
	printf("������Ҫ���ҵ���ϵ������---��  ");
	scanf("%s", &name);
	int s = FindContact_by_name(pc, name);
	if (s == -1)
	{
		printf("ͨѶ¼û���ҵ�ָ����ϵ����Ϣ\n");
		return;
	}
	else
	{
		printf("%-10s\t%-4s\t%4s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "�绰����", "��ϵ�˵�ַ");
		printf("%-10s\t%-4d\t%4s\t%-12s\t%-30s\t\n",
			pc->date[s].name,
			pc->date[s].age,
			pc->date[s].sex,
			pc->date[s].tele,
			pc->date[s].addr
		);
	}
}
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼û����ϵ�ˣ��޷�����\n");
		return;
	}
	char name[MAX_name] = { 0 };
	printf("������Ҫ���ĵ���ϵ������---��  ");
	scanf("%s", &name);
	int s = FindContact_by_name(pc, name);
	if (s == -1)
	{
		printf("ͨѶ¼û���ҵ�ָ����ϵ����Ϣ\n");
		return;
	}
	else
	{
		printf("�������ϵ������----��  ");
		scanf("%s", &pc->date[s].name);
		printf("�������ϵ������----��  ");
		scanf("%d", &pc->date[s].age);
		printf("�������ϵ���Ա�----��  ");
		scanf("%s", &pc->date[s].sex);
		printf("�������ϵ�˵绰----��  ");
		scanf("%s", &pc->date[s].tele);
		printf("�������ϵ�˵�ַ----��  ");
		scanf("%s", &pc->date[s].addr);
	}
}

//void SortContact(Contact* pc)
//{
//	int i = 0;
//	int ret = 0;
//	PenInfo p;
//
//	int flog = 0;
//	for (i = 0; i <pc->sz; i++)
//	{
//		char* name = pc->date[i].name;
//		int j = i;
//		
//		for (j = i; j < pc->sz; j++)
//		{
//			ret = strcmp(name, pc->date[j].name);
//			
//			if (ret > 0)
//			{
//				flog = j;
//				name = pc->date[j].name;
//			}
//			
//			
//		}
//		strcpy(p.name, pc->date[flog].name);
//		p.age = pc->date[flog].age;
//		strcpy(p.sex, pc->date[flog].sex);
//		strcpy(p.tele, pc->date[flog].tele);
//		strcpy(p.addr, pc->date[flog].addr);
//
//		strcpy(pc->date[flog].name,pc->date[i].name);
//		pc->date[flog].age = pc->date[i].age;
//		strcpy(pc->date[flog].sex, pc->date[i].sex);
//		strcpy(pc->date[flog].tele, pc->date[i].tele);
//		strcpy(pc->date[flog].addr, pc->date[i].addr);
//		
//		strcpy(pc->date[i].name, p.name);
//		pc->date[i].age = p.age;
//		strcpy(pc->date[i].sex, p.sex);
//		strcpy(pc->date[i].tele, p.tele);
//		strcpy(pc->date[i].addr, p.addr);
//	}
//	
//}
void SortContact(Contact* pc)
{
	int i = 0;
	int ret = 0;
	PenInfo p;

	for (i = 0; i < pc->sz - 1; i++)
	{
		int flog = i;

		for (int j = i + 1; j < pc->sz; j++)
		{
			ret = strcmp(pc->date[j].name, pc->date[flog].name);

			if (ret < 0)
			{
				flog = j;
			}
		}

		if (flog != i)
		{
			// Swap the elements at positions i and flog
			strcpy(p.name, pc->date[flog].name);
			p.age = pc->date[flog].age;
			strcpy(p.sex, pc->date[flog].sex);
			strcpy(p.tele, pc->date[flog].tele);
			strcpy(p.addr, pc->date[flog].addr);

			strcpy(pc->date[flog].name, pc->date[i].name);
			pc->date[flog].age = pc->date[i].age;
			strcpy(pc->date[flog].sex, pc->date[i].sex);
			strcpy(pc->date[flog].tele, pc->date[i].tele);
			strcpy(pc->date[flog].addr, pc->date[i].addr);

			strcpy(pc->date[i].name, p.name);
			pc->date[i].age = p.age;
			strcpy(pc->date[i].sex, p.sex);
			strcpy(pc->date[i].tele, p.tele);
			strcpy(pc->date[i].addr, p.addr);
		}
	}
}
