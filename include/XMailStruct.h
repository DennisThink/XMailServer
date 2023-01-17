#ifndef _XMAIL_STRUCT_H_
#define _XMAIL_STRUCT_H_
#include <string>
#include <spdlog/fmt/fmt.h>
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

class SmtpEmailBean
{
public:
	std::string m_strSmtpDomain;
	std::string m_strMsgId;
	std::string m_strMailFrom;
	std::string m_strReptTo;
	std::string m_strData;
};

template<>
struct fmt::formatter<SmtpEmailBean> :fmt::formatter<std::string>
{
	auto format(SmtpEmailBean my, format_context& ctx)->decltype(ctx.out())
	{
		return format_to(ctx.out(), "[smtpEmail: \n {} \n {} \n {} \n {} \n]", my.m_strMailFrom, my.m_strReptTo, my.m_strMsgId, my.m_strData);
	}
};
#endif