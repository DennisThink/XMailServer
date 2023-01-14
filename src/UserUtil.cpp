#include "UserUtils.h"
#include "CDBUtil.h"
static CDBUtil g_db("test.db");

UserInfoBean UserUtils::GetUserInfoByDomainAndName(const std::string& strDomain, const std::string& strUser)
{
	return g_db.QueryUserInfoFromDomainAndName(strDomain, strUser);
}