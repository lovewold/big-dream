#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"



//对于常数后期由于可以便捷修改，宏定义
//创建一个结构体类型的通讯录表列

//初始化
void Infocontact(Contact* pc)
{
	assert(pc);
	memset(pc->date, 0, sizeof(pc->date));
	pc->sz = 0;
}

//查找联系人by_name
static int FindContact_by_name(const Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->date[i].name) == 0)
		{
			return i;
			//找到了目标联系人
		}
	}
	return -1;//找不到
}

//添加联系人，增加信息。
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录容纳已满\n");
		return;
	}
	printf("请输入联系人姓名----》  ");
	scanf("%s", &pc->date[pc->sz].name);
	printf("请输入联系人年龄----》  ");
	scanf("%d", &pc->date[pc->sz].age);
	printf("请输入联系人性别----》  ");
	scanf("%s", &pc->date[pc->sz].sex);
	printf("请输入联系人电话----》  ");
	scanf("%s", &pc->date[pc->sz].tele);
	printf("请输入联系人地址----》  ");
	scanf("%s", &pc->date[pc->sz].addr);

	pc->sz++;
	printf("成功添加第 %d 位联系人\n",pc->sz);

}
//删减指定联系人by_name
void DelContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->sz == 0)
	{
		printf("通讯录没有联系人，无法删除\n");
		return;
	}
	char name[MAX_name] = {0};
	printf("请输入要删除的联系人名字---》  ");
	scanf("%s", &name);
	int del = FindContact_by_name(pc,name);
	if (del == -1)
	{
		printf("通讯录没有找到指定联系人信息\n");
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

	printf("成功删除联系人\n");
	

}
//显示通讯录
void ShowContact(Contact* pc)
{
	printf("  %-20s\t%-4s\t%-4s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "电话号码", "联系人地址");
	printf("\n");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("  %-20s\t%-4d\t%-4s\t%-12s\t%-30s\t\n",
			pc->date[i].name,
			pc->date[i].age,
			pc->date[i].sex,
			pc->date[i].tele,
			pc->date[i].addr
		);
	}
	printf("\n");
}

//寻找到指定联系人后打印联系人信息
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录没有联系人，无法查找\n");
		return;
	}
	char name[MAX_name] = { 0 };
	printf("请输入要查找的联系人名字---》  ");
	scanf("%s", &name);
	int s = FindContact_by_name(pc, name);
	if (s == -1)
	{
		printf("通讯录没有找到指定联系人信息\n");
		return;
	}
	else
	{
		printf("%-10s\t%-4s\t%4s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "电话号码", "联系人地址");
		printf("%-10s\t%-4d\t%4s\t%-12s\t%-30s\t\n",
			pc->date[s].name,
			pc->date[s].age,
			pc->date[s].sex,
			pc->date[s].tele,
			pc->date[s].addr
		);
	}
}
//
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录没有联系人，无法更改\n");
		return;
	}
	char name[MAX_name] = { 0 };
	printf("请输入要更改的联系人名字---》  ");
	scanf("%s", &name);
	int s = FindContact_by_name(pc, name);
	if (s == -1)
	{
		printf("通讯录没有找到指定联系人信息\n");
		return;
	}
	else
	{
		printf("请更改联系人姓名----》  ");
		scanf("%s", &pc->date[s].name);
		printf("请更改联系人年龄----》  ");
		scanf("%d", &pc->date[s].age);
		printf("请更改联系人性别----》  ");
		scanf("%s", &pc->date[s].sex);
		printf("请更改联系人电话----》  ");
		scanf("%s", &pc->date[s].tele);
		printf("请更改联系人地址----》  ");
		scanf("%s", &pc->date[s].addr);
	}
}

void SortContact_by_name(Contact* pc)
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
	
			p = pc->date[flog];
			pc->date[flog] = pc->date[i];
			pc->date[i] = p;
		}
	}
}
//by_age
void SortContact_by_age(Contact* pc)
{
	int i = 0;
	int ret = 0;
	PenInfo p;

	for (i = 0; i < pc->sz - 1; i++)
	{
		int flog = i;

		for (int j = i + 1; j < pc->sz; j++)
		{
			ret = (pc->date[j].age)-(pc->date[flog].age);

			if (ret < 0)
			{
				flog = j;
			}
		}

		if (flog != i)
		{
			// Swap the elements at positions i and flog
			p = pc->date[flog];
			pc->date[flog] = pc->date[i];
			pc->date[i] = p;
		
		}
	}
}

//清空通讯录
void Infocontact_all(Contact* pc)
{
	Infocontact(pc);
	printf("通讯录已经清空\n");
	ShowContact(pc);
}
