#ifndef _XMAIL_SMTP_CONFIG_H_
#define _XMAIL_SMTP_CONFIG_H_
#include <string>
class SmtpConfig
{
public:
	static int GetSmtpMinDiskSpace();
	static int GetSmtpMinVirtMemSpace();
	static int GetSmtpIpMapDropCode();
	static bool EnableLog();
	static std::string GetSmtpMsgIPBan();
	static std::string GetSmtpMsgIPBanSpammers();
	static std::string GetSmtpCustMapsList();
	static int GetSmtpMaxMessageSize();
	static bool DisableEmitAuthUser();
	static std::string GetSmtpNoTLSAuths();
};
#endif