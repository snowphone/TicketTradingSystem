//Class: SignOut
//Description: 로그아웃을 담당하는 control class이다.
//Author: 김상엽
// Created: 2019/06/03
// Mail: natsuko0012@gmail.com

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: add some test code
//
// 		3.	When & Who: 2019/06/03 by 김상엽
// 				What: remove test code and complete whole logic


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
