#ifndef _XMAIL_CONFIG_UTIL_H_
#define _XMAIL_CONFIG_UTIL_H_
#include <string>
class ConfigUtil
{
public:
    static std::string GetMailMainPath(){
#ifdef WIN32
        return "C:\\Dennis\\XMail";
#else
        return "/home/dennis/XMail/";
#endif
    };
};
#endif