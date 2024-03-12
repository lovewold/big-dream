#include "Student.h"

Student::Student()
{
}


Student::~Student()
{
}

void Student::ShowMenu()
{
	system("cls");
	cout << "==========================��ӭʹ��ͼ��ݺ�̨����ϵͳ��==========================" << endl;
	cout << "                              1.��ѯͼ��" << endl;
	cout << "                              2.����ͼ��" << endl;
	cout << "                              3.�黹ͼ��" << endl;
	cout << "                              4.���ļ�¼" << endl;
	cout << "                              5.����ͼ��" << endl;
	cout << "                              0.�˳���¼" << endl;
}


//����������ѯ�鼮
bool Student::QueryBook(string strBookName)
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

//����ͼ��ID�����鼮
bool Student::BorrowBook(int nBookId)
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
		if (book.GetLeftNum() == 0)
		{
			cout << "���鼮��ȫ���������ʱ�޷�����!" << endl;
			cin.get();
			cin.get();
			return false;
		}
		//ѯ���Ƿ����
		char chIsBorrow = 'a';
		cout << "�����Ȿ����?n/y" << endl;
		cin.get();
		cin >> chIsBorrow;
		while (true)
		{
			if (chIsBorrow == 'y' || chIsBorrow == 'Y')
			{
				//����
				BorrowRecord borrowRecord;
				borrowRecord.m_nBookId = book.GetBookID();
				borrowRecord.m_nUserId = m_nID;
				time_t tTemp = time(NULL);
				char szTime[16] = {0};
				m_timeUtil.TimeToString(tTemp, szTime);
				borrowRecord.m_tBorrowDate = szTime;
				borrowRecord.m_tShouldReturnDate = m_timeUtil.AddMonth(tTemp);
				borrowRecord.m_tReturnDate = "";
				borrowRecord.m_nContinue = 0;
				m_dbUtil.AddBorrowRecord(borrowRecord);
				break;
			}
			else if (chIsBorrow == 'n' || chIsBorrow == 'N')
			{
				cout << "��ȡ�����ģ�";
				break;
			}
			else
			{
				cout << "��������,����������:";
				cin.get();
				cin >> chIsBorrow;
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

//����ͼ��ID�����鼮
bool Student::ReturnBook()
{
	Book book;
	User user;
	book.SetBookID(-1);
	vector<BorrowRecord> borrowRecords;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	//չʾ��δ�黹��ͼ���¼
	m_dbUtil.SelectBorrowRecordByUserId(borrowRecords, m_nID, 1);
	cout << "������û�й黹��ͼ��" << endl;
	vector<BorrowRecord>::iterator vecIter;
	cout << "ID       ����        ������    ��������       Ӧ������     ��������   �������" << endl;
	for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++)
	{
		user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
		m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
		cout << setiosflags(ios::left) << setw(4) << vecIter->m_nBorrowId << "  " << setw(14) << book.GetBookName() << "  " << setw(6) << user.m_strName << "  " << setw(13) << vecIter->m_tBorrowDate << "  " << setw(13) << vecIter->m_tShouldReturnDate << "  " << setw(13) << vecIter->m_tReturnDate << "  " << setw(3) << vecIter->m_nContinue << endl;
	}
	cout << "��ѡ��Ҫ�黹ͼ��ļ�¼ID" << endl;

	//ѡ��Ҫ���ı���
	int nRecordId;
	cin >> nRecordId;
	bool bIsFind = true;
	while (bIsFind)
	{
		for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++)
		{
			if (nRecordId == vecIter->m_nBorrowId)
			{
				bIsFind = false;
				break;
			}
		}
		if (vecIter == borrowRecords.end())
		{
			cout << "���������ID���ڼ�¼�У�����������:";
			cin >> nRecordId;
		}
	}

	m_dbUtil.FinishBorrowRecord(vecIter->m_nBorrowId, vecIter->m_nBookId);
	cout << "����ɹ�!" << endl;
	cin.get();
	cin.get();
	return true;
}

//չʾ���˽��ļ�¼
bool Student::ShowMyBorrowRecord()
{
	vector<BorrowRecord> borrowRecords;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectBorrowRecordByUserId(borrowRecords, m_nID, 2);
	User user;
	Book book;
	cout << "�������������н��ļ�¼:" << endl;
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

//����ͼ��
bool Student::RenewBook()
{
	Book book;
	User user;
	book.SetBookID(-1);
	vector<BorrowRecord> borrowRecords;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	//չʾ��δ�黹��ͼ���¼
	m_dbUtil.SelectBorrowRecordByUserId(borrowRecords, m_nID, 1);
	cout << "������û�й黹��ͼ��" << endl;
	vector<BorrowRecord>::iterator vecIter;
	cout << "ID       ����        ������    ��������       Ӧ������     ��������   �������" << endl;
	for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++)
	{
		user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
		m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
		cout << setiosflags(ios::left) << setw(4) << vecIter->m_nBorrowId << "  " << setw(14) << book.GetBookName() << "  " << setw(6) << user.m_strName << "  " << setw(13) << vecIter->m_tBorrowDate << "  " << setw(13) << vecIter->m_tShouldReturnDate << "  " << setw(13) << vecIter->m_tReturnDate << "  " << setw(3) << vecIter->m_nContinue << endl;
	}
	cout << "��ѡ��Ҫ�黹ͼ��ļ�¼ID" << endl;

	//ѡ��Ҫ�����ı���
	int nRecordId;
	cin >> nRecordId;
	bool bIsNotFind = true;
	bool bCanContinue = false;
	while (bIsNotFind)
	{
		for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++)
		{
			if (nRecordId == vecIter->m_nBorrowId)
			{
				bIsNotFind = false;
				if (vecIter->m_nContinue > 0)
				{
					bCanContinue = false;
				}
				else
				{
					bCanContinue = true;
				}

				break;
			}
		}
		if (vecIter == borrowRecords.end())
		{
			cout << "���������ID���ڼ�¼�У�����������:";
			cin >> nRecordId;
		}
	}

	if (true == bCanContinue)
	{
		m_dbUtil.ExtendBorrowRecord(nRecordId);
		cout << "����ɹ�!" << endl;
	}
	else
	{
		cout << "���鼮�Ѿ������һ�Σ��޷��ٴ�����" << endl;
	}

	cin.get();
	cin.get();
	return true;

}