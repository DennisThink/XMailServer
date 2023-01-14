#include <iostream>
#include "CDBUtil.h"
int main(int argc, char* argv[])
{
	std::cout << "XMailSqliteUtil" << std::endl;
	CDBUtil util("test.db");
	util.InitTest();
	UserInfoBean userInfo = util.QueryUserInfoFromDomainAndName("test.test","test");
	if (userInfo.Valid())
	{
		std::cout << "UserInfoBean Valid" << std::endl;
	}

	UserInfoBean userInfo2 = util.QueryUserInfoFromDomainAndName("test.test", "test2");
	if(userInfo2.Valid())
	{
		std::cout << " UserInfoBean Valid " << std::endl;
	}

	return 0;
}