#include "SmtpConfig.h"

int SmtpConfig::GetSmtpMinDiskSpace()
{
	return 1;
}


int SmtpConfig::GetSmtpMinVirtMemSpace()
{
	return 1;
}

int SmtpConfig::GetSmtpIpMapDropCode()
{
	return 1;
}

bool SmtpConfig::EnableLog()
{
	return true;
}

std::string SmtpConfig::GetSmtpMsgIPBan()
{
	return "IP Baned from XMail";
}

std::string SmtpConfig::GetSmtpMsgIPBanSpammers()
{
	return "IP Baned from XMail Spammers";
}

std::string SmtpConfig::GetSmtpCustMapsList()
{
	return "127.0.0.1";
}

int SmtpConfig::GetSmtpMaxMessageSize()
{
	return 1024;
}

bool SmtpConfig::DisableEmitAuthUser()
{
	return true;
}

std::string SmtpConfig::GetSmtpNoTLSAuths()
{
	return "NoTLSAuth";
}