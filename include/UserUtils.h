//DennisThink
#ifndef _XMAIL_USER_UTILS_H_
#define _XMAIL_USER_UTILS_H_
#include <string>
#include "XMailStruct.h"
class UserUtils
{
public:
	static UserInfoBean GetUserInfoByDomainAndName(const std::string& strDomain, const std::string& strUser);
};
#endif