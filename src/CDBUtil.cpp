#include "CDBUtil.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include "logutil.h"
static std::unique_ptr<SQLite::Database> g_db;
UserInfoBean CDBUtil::QueryUserInfoFromDomainAndName(const std::string& strDomain, const std::string& strName)
{
	UserInfoBean result;
	SQLite::Statement   query(*g_db, "SELECT F_USER_ID,F_PASSWORD,F_PATH,F_TYPE FROM T_USER WHERE F_DOMAIN=:domain AND F_USER_NAME=:username;");
	query.bind(":domain", strDomain);
	query.bind(":username", strName);
	if (query.executeStep())
	{
		result.m_userId = query.getColumn(0).getInt();
		result.m_strPassword = query.getColumn(1).getString();
		result.m_strPath = query.getColumn(2).getString();
		result.m_strType = query.getColumn(3).getString();
		result.m_strDomain = strDomain;
		result.m_strUserName = strName;
	}
	return result;
}

bool CDBUtil::InitTables()
{
	if (g_db && g_db->tableExists("T_USER"))
	{
		XMAIL_DEBUG("Table T_USER exists");
	}
	else
	{
		//CREATE T_USER
		

	}
	return false;
}

bool CDBUtil::CreateTable_T_USER()
{
	if (g_db)
	{
		int nResult = g_db->exec("CREATE TABLE T_USER (F_INDEX INTEGER PRIMARY KEY,F_USER_ID INTEGER,F_DOMAIN TEXT,F_USER_NAME TEXT,F_PASSWORD TEXT,F_PATH TEXT,F_TYPE TEXT)");
		XMAIL_DEBUG("Create Table Result: {}", nResult);
		return true;
	}
	else
	{
		return false;
	}
}

bool CDBUtil::InitTest()
{
	if (g_db)
	{
		if (g_db->tableExists("T_USER"))
		{
		
		}
		else
		{
			CreateTable_T_USER();
		}
		int nResult = g_db->exec(R"(INSERT INTO T_USER(F_INDEX,F_USER_ID,F_DOMAIN,F_USER_NAME,F_PASSWORD,F_PATH,F_TYPE) VALUES(NULL,1,"test.test","test","test","C:\Dennis\XMail\test\","U");)");
		XMAIL_DEBUG("Insert Table Result: {}", nResult);
		return true;
	}
	return false;
}
CDBUtil::CDBUtil(const std::string& strDbFile)
{
	g_db = std::make_unique<SQLite::Database>(strDbFile, SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE);
}