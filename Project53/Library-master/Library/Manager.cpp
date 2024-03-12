#include "Manager.h"

Manager::Manager()
{
}


Manager::~Manager()
{
}


void Manager::ShowMenu()
{
	system("cls");
	cout << "==========================��ӭʹ��ͼ��ݺ�̨����ϵͳ��==========================" << endl;
	cout << "                              1.����¼��" << endl;
	cout << "                              2.ͼ���ѯ" << endl;
	cout << "                              3.ɾ��ͼ��" << endl;
	cout << "                              4.ͼ���б�" << endl;
	cout << "                              5.���ļ�¼" << endl;
	cout << "                              6.�����û�" << endl;
	cout << "                              7.�û��б�" << endl;
	cout << "                              0.�˳���¼" << endl;
}

bool Manager::AddBook()
{
	string bookName;
	string author;
	string isbn;
	string pub;
	int total;
	char szTime[32] = {0};
	time_t lt;
	lt = time(NULL);
	m_timeUtil.TimeToString(lt, szTime);

	cout << "��ѡ���������ͼ�鹦�ܣ�����������ͼ����Ϣ" << endl;
	cout << "ͼ������ ���� ISBN ������ �ܲ���" << endl;
	cin >> bookName;
	cin >> author;
	cin >> isbn;
	cin >> pub;
	cin >> total;

	Book book;
	book.SetBookName(bookName);
	book.SetAuthor(author);
	book.SetISBN(isbn);
	book.SetPub(pub);
	book.SetTotalNum(total);
	book.SetLeftNum(0);
	book.SetInDate(szTime);

	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	m_dbUtil.AddBook(book);
	cout << "����ͼ��ɹ�" << endl;
	return true;
}

//չʾ�����鼮
bool Manager::DisplayAllBook()
{
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	
	m_dbUtil.SelectAllBook(books);
	vector<Book>::iterator vecIter;
	cout << "ID     ����            ����           ������       �������     �ݲ�����   ����" << endl;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter ++)
	{

		cout << setiosflags(ios::left) << setw(4) << vecIter->GetBookID() << "  " << setw(14) << vecIter->GetBookName() << "  " << setw(10) << vecIter->GetAuthor() << "  " << setw(14) << vecIter->GetPub() << "  " << setw(14) << vecIter->GetInDate() << "  " << setw(8) << vecIter->GetTotalNum() << "  " << setw(3) << vecIter->GetLeftNum() << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//����������ѯ�鼮
bool Manager::QueryBook(string strBookName)
{
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectBookByName(strBookName, books);
	vector<Book>::iterator vecIter;
	cout << "ID     ����            ����           ������       �������     �ݲ�����   ����" << endl;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter++)
	{

		cout << setiosflags(ios::left) << setw(4) << vecIter->GetBookID() << "  " << setw(14) << vecIter->GetBookName() << "  " << setw(10) << vecIter->GetAuthor() << "  " << setw(14) << vecIter->GetPub() << "  " << setw(14) << vecIter->GetInDate() << "  " << setw(8) << vecIter->GetTotalNum() << "  " << setw(3) << vecIter->GetLeftNum() << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//����ͼ��IDɾ��ͼ��
bool Manager::DeleteBook(int nBookId)
{
	Book book;
	book.SetBookID(-1);
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	m_dbUtil.SelectBookById(nBookId, book);
	if (book.GetBookID() != -1)
	{
		cout << "ID     ����            ����           ������       �������     �ݲ�����   ����" << endl;
		cout << setiosflags(ios::left) << setw(4) << book.GetBookID() << "  " << setw(14) << book.GetBookName() << "  " << setw(10) << book.GetAuthor() << "  " << setw(14) << book.GetPub() << "  " << setw(14) << book.GetInDate() << "  " << setw(8) << book.GetTotalNum() << "  " << setw(3) << book.GetLeftNum() << endl;

		//ѯ���Ƿ�ɾ��
		char chIsDelete = 'a';
		cout << "ɾ���Ȿ����?n/y" << endl;
		cin.get();
		cin >> chIsDelete;	
		while (true)
		{
			if (chIsDelete == 'y' || chIsDelete == 'Y')
			{
				m_dbUtil.DeleteBookById(nBookId);
				break;
			}
			else if (chIsDelete == 'n' || chIsDelete == 'N')
			{
				cout << "��ȡ��ɾ����";
				break;
			}
			else
			{
				cout << "��������,����������:";
				cin.get();
				cin >> chIsDelete;
			}
		}
	}
	else
	{
		cout << "û���ҵ�IDΪ" << nBookId << "���鼮" << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//չʾ���н��ļ�¼
bool Manager::DiaplayAllBorrowRecord()
{
	vector<BorrowRecord> borrowRecords;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectAllBorrowRecord(borrowRecords);
	User user;
	Book book;
	vector<BorrowRecord>::iterator vecIter;
	cout << "ID       ����        ������    ��������       Ӧ������     ��������   �������" << endl;
	for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++)
	{
		user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
		m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
		cout << setiosflags(ios::left) << setw(4) << vecIter->m_nBorrowId << "  " << setw(14) << book.GetBookName() << "  " << setw(6) << user.m_strName << "  " << setw(13) << vecIter->m_tBorrowDate << "  " << setw(13) << vecIter->m_tShouldReturnDate << "  " << setw(13) << vecIter->m_tReturnDate << "  " << setw(3) << vecIter->m_nContinue << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//�����û�
bool Manager::AddUser()
{
	cout << "������һ���û���Ϣ:" << endl;
	cout << "�û���   ����   �û�����" << endl;
	User user;

	cin >> user.m_strName;
	cin >> user.m_strPassword;
	cin >> user.m_nRole;

	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.AddUser(user);
	cout << "�����û��ɹ�" << endl;
	cin.get();
	cin.get();
	return true;
}

//չʾ�����û�
bool Manager::DisplayAllUser()
{
	vector<User> users;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectAllUser(users);
	User user;
	Book book;
	vector<User>::iterator vecIter;
	cout << "ID     �û���      ���" << endl;
	for (vecIter = users.begin(); vecIter != users.end(); vecIter++)
	{
		cout << setiosflags(ios::left) << setw(6) << vecIter->m_nID << "  " << setw(8) << vecIter->m_strName << "  " << (vecIter->m_nRole == 1 ? "����Ա" : "ѧ��") << endl;
	}
	cin.get();
	cin.get();
	return true;
}