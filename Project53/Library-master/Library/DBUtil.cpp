#include "DBUtil.h"


DBUtil::DBUtil()
{
	szUsername = "root";
	szPswd = "ROOT";
	szHost = "localhost";
	szDatabase = "library";
	nPort = 3306;
	isOpen = false;
}


DBUtil::~DBUtil()
{
	CloseDB();
}

//�����ݿ�
bool DBUtil::OpenDB()
{
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, szHost.c_str(), szUsername.c_str(), szPswd.c_str(), szDatabase.c_str(), nPort, NULL, 0))
	{
		isOpen = true;
		return true;
	}
	return false;
}

//�ر����ݿ�
bool DBUtil::CloseDB()
{
	mysql_close(&myCont);//�Ͽ�����
	return true;
}



//�����û������������û���Ϣ
User DBUtil::ReadUser(string strUserName, string strUserPWD)
{
	User user;
	char column[32][32];
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from user where name='" + strUserName + "' and password='" + strUserPWD + "'";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result->row_count > 0)
			{
				int i, j;
				//cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;
				for (i = 0; fd = mysql_fetch_field(result); i++)//��ȡ����
				{
					strcpy_s(column[i], fd->name);
				}
				j = mysql_num_fields(result);

				if (j > 0)
				{
					sql_row = mysql_fetch_row(result);
					user.m_nID = atoi(sql_row[0]);
					user.m_strName = sql_row[1];
					user.m_nRole = atoi(sql_row[3]);
				}
			}
			else
			{
				user.m_nID = -1;
				return user;
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return user;
}

//����ͼ��
bool DBUtil::AddBook(Book book)
{
	string sql = "";
	char szTotal[16];
	char szLeftNum[16];
	sprintf(szTotal, "%d", book.GetTotalNum());
	sprintf(szLeftNum, "%d", book.GetTotalNum());

	if (isOpen)
	{
		//���ʱ��
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "insert into book values(null,'" + book.GetBookName() + "','" + book.GetAuthor() + "','" + book.GetISBN() + "','" + book.GetPub() + "','" + book.GetInDate() + "', " + szTotal + ", " + szLeftNum + ")";
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	cin.get();
	cin.get();
	return false;

}

//��������ͼ��
bool DBUtil::SelectAllBook(vector<Book> &books)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from book";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					Book book;
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
					books.push_back(book);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}

	return true;
}

//����������ѯ�鼮
bool DBUtil::SelectBookByName(string strBookName, vector<Book> &books)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from book where bookname like '%" + strBookName + "%'";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					Book book;
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
					books.push_back(book);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return true;
}

//����ͼ��ID��ѯ�鼮
bool DBUtil::SelectBookById(int nBookId, Book &book)
{
	int res;
	string sql;
	char szBookId[5] = {0};
	sprintf(szBookId, "%d", nBookId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from book where id=";
		sql += szBookId;
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return true;
}

//����IDɾ��ͼ��
bool DBUtil::DeleteBookById(int nBookId)
{
	int res;
	string sql;
	char szBookId[5] = {0};
	sprintf(szBookId, "%d", nBookId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "delete from book where id=" ;
		sql += szBookId;
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}

	return true;
}

//�������ļ�¼
bool DBUtil::AddBorrowRecord(BorrowRecord borrowRecord)
{
	string sql = "";
	char szBookId[16];
	char szUserId[16];
	sprintf(szBookId, "%d", borrowRecord.m_nBookId);
	sprintf(szUserId, "%d", borrowRecord.m_nUserId);
	if (isOpen)
	{
		sql = sql + "insert into borrowrecord values(null," + szBookId + "," + szUserId + ",'" + borrowRecord.m_tBorrowDate + "','" + borrowRecord.m_tShouldReturnDate + "',NULL,0)";
		mysql_query(&myCont, sql.c_str());

		sql = "";

		sql = sql + "update book set book.left=book.left-1 where id = " + szBookId;
		mysql_query(&myCont, sql.c_str());
		cout << "���ĳɹ�!" << endl;
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return false;

}


//�����û�ID����û���Ϣ
User DBUtil::SelectUserById(int nUserId)
{
	int res;
	string sql;
	User user;
	char szUserId[5] = { 0 };
	sprintf(szUserId, "%d", nUserId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from user where id=";
		sql += szUserId;
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					user.m_nID = nUserId;
					user.m_strName = sql_row[1];
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return user;
}

//��ѯ���н��ļ�¼
bool DBUtil::SelectAllBorrowRecord(vector<BorrowRecord> &borrowRecords)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from borrowrecord";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					BorrowRecord borrowRecord;
					borrowRecord.m_nBorrowId = atoi(sql_row[0]);
					borrowRecord.m_nBookId = atoi(sql_row[1]);
					borrowRecord.m_nUserId = atoi(sql_row[2]);
					borrowRecord.m_tBorrowDate = sql_row[3];
					borrowRecord.m_tShouldReturnDate = sql_row[4];
					borrowRecord.m_tReturnDate = (sql_row[5] == NULL ? "" : sql_row[5]);
					borrowRecord.m_nContinue = atoi(sql_row[6]);
					borrowRecords.push_back(borrowRecord);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}

	return true;
}

//��ѯĳλ�û��Ľ��ļ�¼ 
bool DBUtil::SelectBorrowRecordByUserId(vector<BorrowRecord> &borrowRecords, int nUserId, int nType)
{
	//nType=1��ʾѡ��δ�黹 nType=2��ʾѡ��ȫ��
	int res;
	string sql;
	char szUserId[8] = {0};
	sprintf(szUserId, "%d", nUserId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql = sql + "select * from borrowrecord where userid=" + szUserId;
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					//�����ڿձ�ʾ�Ѿ��黹
					if (nType == 1)
					{
						if (sql_row[5] != NULL)
						{
							continue;
						}
					}

					BorrowRecord borrowRecord;
					borrowRecord.m_nBorrowId = atoi(sql_row[0]);
					borrowRecord.m_nBookId = atoi(sql_row[1]);
					borrowRecord.m_nUserId = atoi(sql_row[2]);
					borrowRecord.m_tBorrowDate = sql_row[3];
					borrowRecord.m_tShouldReturnDate = sql_row[4];
					borrowRecord.m_tReturnDate = (sql_row[5] == NULL ? "" : sql_row[5]);
					borrowRecord.m_nContinue = atoi(sql_row[6]);
					borrowRecords.push_back(borrowRecord);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}

	return true;
}

//�黹�鼮
bool DBUtil::FinishBorrowRecord(int nRecordId,int nBookId)
{
	string sql = "";
	char szRecordId[16];
	char szBookId[16];
	sprintf(szRecordId, "%d", nRecordId);
	sprintf(szBookId, "%d", nBookId);
	time_t tTemp = time(NULL);
	char szTime[16] = { 0 };
	timeUtil.TimeToString(tTemp, szTime);
	if (isOpen)
	{
		sql = sql + "update borrowrecord set returndate='" + szTime + "' where id=" + szRecordId;
		mysql_query(&myCont, sql.c_str());

		sql = "";

		sql = sql + "update book set book.left=book.left+1 where id = " + szBookId;
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return true;

}

//�����û�
bool DBUtil::AddUser(User user)
{
	string sql = "";
	char szRoleType[16];
	sprintf(szRoleType, "%d", user.m_nRole);

	if (isOpen)
	{
		sql += "insert into user values(null,'" + user.m_strName + "','" + user.m_strPassword + "'," + szRoleType + ")";
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return true;
}

//��ѯ�����û�
bool DBUtil::SelectAllUser(vector<User> &users)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from user";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					User user;
					user.m_nID = atoi(sql_row[0]);
					user.m_strName = sql_row[1];
					user.m_nRole = atoi(sql_row[3]); 
					users.push_back(user);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return true;
}

//����ͼ��
bool DBUtil::ExtendBorrowRecord(int nRecordId)
{
	string sql = "";
	char szRecordId[16];
	char szBookId[16];
	sprintf(szRecordId, "%d", nRecordId);
	time_t tTemp = time(NULL);
	if (isOpen)
	{
		sql = sql + "update borrowrecord set shouldreturndate='" + timeUtil.AddMonth(tTemp) + "',borrowrecord.continue=borrowrecord.continue+1 where id=" + szRecordId;
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return true;
}

//����ID��ѯ���ļ�¼
bool DBUtil::SelectBorrowRecordByRecordId(BorrowRecord &borrowRecord, int nRecordId)
{
	int res;
	string sql;
	char szRecordId[8] = { 0 };
	sprintf(szRecordId, "%d", nRecordId);
	if (isOpen)
	{
		sql = sql + "select * from borrowrecord where id=" + szRecordId;
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				sql_row = mysql_fetch_row(result);
				borrowRecord.m_nBorrowId = atoi(sql_row[0]);
				borrowRecord.m_nBookId = atoi(sql_row[1]);
				borrowRecord.m_nUserId = atoi(sql_row[2]);
				borrowRecord.m_tBorrowDate = sql_row[3];
				borrowRecord.m_tShouldReturnDate = sql_row[4];
				borrowRecord.m_tReturnDate = (sql_row[5] == NULL ? "" : sql_row[5]);
				borrowRecord.m_nContinue = atoi(sql_row[6]);
				
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}

	return true;
}