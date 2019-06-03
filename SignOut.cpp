//Class: SignOut
//Description: 로그아웃을 담당하는 control class이다.
//Author: 김상엽
#include "SignOut.h"
#include <iostream>



SignOut::SignOut()
{
}


SignOut* SignOut::var = nullptr;
SignOut & SignOut::get()
{
	if (!var)
		var = new SignOut();
	return *var;
}

void SignOut::requestSignOut(const Info & info)
{

	std::cout << "2.2 로그아웃" << std::endl
		<< "> " << info.getID() << std::endl;
}

SignOut::~SignOut()
{
}
