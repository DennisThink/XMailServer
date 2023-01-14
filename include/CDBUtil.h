#ifndef _XMAIL_CDB_UTIL_H_
#define _XMAIL_CDB_UTIL_H_
#include "XMailStruct.h"
class CDBUtil
{
public:
	CDBUtil(const std::string& strDbFile);
	UserInfoBean QueryUserInfoFromDomainAndName(const std::string& strDomain, const std::string& strName);
	bool InitTest();
private:
	bool InitTables();
	bool CreateTable_T_USER();
};
#endif