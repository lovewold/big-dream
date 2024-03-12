#include <iostream>
#include "User.h"
#include "Manager.h"
#include "DBUtil.h"
#include "Student.h"
#include "Book.h"
using namespace std;

int main()
{
	string strUserName = "";
	string strUserPWD = "";
	bool bIsLogin = false;
	User user;
	cout << "                          �������û�����";
	cin >> strUserName;
	cout << endl;
	cout << "                          ���������룺";
	cin >> strUserPWD;
	cout << endl;
	DBUtil dbUtil;
	dbUtil.OpenDB();
	user = dbUtil.ReadUser(strUserName, strUserPWD);
	while (user.m_nID == -1)
	{
		cout << "�û������������������������,�����������..." << endl;
		cin.get();
		cin.get();
		system("cls");
		cout << "                          �������û�����";
		cin >> strUserName;
		cout << endl;
		cout << "                          ���������룺";
		cin >> strUserPWD;
		cout << endl;
		user = dbUtil.ReadUser(strUserName, strUserPWD);
	}
	if (user.m_nRole == 1)
	{
		Manager manager;
		manager.m_nID = user.m_nRole;
		manager.m_strName = user.m_strName;
		manager.m_nRole = user.m_nRole;
		int command = -1;		//ѡ������
		bIsLogin = true;
		string strBookName = "";
		int nBookId = 0;
		while (bIsLogin)
		{
			system("cls");
			manager.ShowMenu();
			cout << "��ѡ�����";
			cin >> command;
			switch (command)
			{
			case 1:
				//ѡ������ͼ��
				manager.AddBook();			
				break;
			case 2:
				cout << "������������";
				cin >> strBookName;
				manager.QueryBook(strBookName);
				break;
			case 3:
				cout << "������Ҫɾ��ͼ���ID" << endl;
				cin >> nBookId;
				manager.DeleteBook(nBookId);
				break;
			case 4:
				manager.DisplayAllBook();
				break;
			case 5:
				manager.DiaplayAllBorrowRecord();
				break;
			case 6:
				manager.AddUser();
				break;
			case 7:
				manager.DisplayAllUser();
				break;
			case 0:
				//ѡ���˳���¼
				bIsLogin = false;
				break;
			default:
				break;
			}
		}
		cout << "�����˳���¼����������˳�..." << endl;
	}
	else
	{
		Student student;
		student.m_nID = user.m_nRole;
		student.m_strName = user.m_strName;
		student.m_nRole = user.m_nRole;
		int command = -1;		//ѡ������
		bIsLogin = true;
		string strBookName = "";
		int nBookId;
		while (bIsLogin)
		{
			system("cls");
			student.ShowMenu();
			cout << "��ѡ�����";
			cin >> command;
			switch (command)
			{
			case 1:
				//ѡ���ѯͼ��
				cout << "������������";
				cin >> strBookName;
				student.QueryBook(strBookName);
				break;
			case 2:
				//ѡ�����
				cout << "������ͼ��ID��";
				cin >> nBookId;
				student.BorrowBook(nBookId);
				break;
			case 3:
				//�黹ͼ��
				student.ReturnBook();
				break;
			case 4:
				student.ShowMyBorrowRecord();
				break;
			case 5:
				student.RenewBook();
				break;
			case 0:
				//ѡ���˳���¼
				bIsLogin = false;
				break;
			default:
				break;
			}
		}
		cout << "�����˳���¼����������˳�..." << endl;
	}
	cin.get();
	cin.get();
	return 0;
}