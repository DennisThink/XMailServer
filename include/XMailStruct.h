#ifndef _XMAIL_STRUCT_H_
#define _XMAIL_STRUCT_H_
#include <string>
using userid_t = unsigned int;
class UserInfoBean
{
public:
	UserInfoBean() {
		m_strDomain = "";
		m_userId = 1;
		m_strUserName = "";
		m_strPassword = "";
		m_strPath = "";
		m_strType = "U";
	}
	bool Valid() const {
		if (!m_strUserName.empty())
		{
			return true;
		}
		return false;
	}
public:
	std::string m_strDomain;
	userid_t m_userId;
	std::string m_strUserName;
	std::string m_strPassword;
	std::string m_strPath;
	std::string m_strType;
};
#endif