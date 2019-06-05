//Class: SignIn
//Description: 로그인 기능을 담당하는 control class이다.
//Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file
//
// 		2.	When & Who: 2019/06/03 by 김소연
// 				What: modify some errors
#include "SignIn.h"
#include "UserCollection.h"
#include <algorithm>



SignIn::SignIn()
{
}


SignIn* SignIn::var = nullptr;
SignIn & SignIn::get()
{
	if (!var)
		var = new SignIn();
	return *var; //instance caller
}

const Info * SignIn::putIdPw(std::string id, std::string pw)
{
	std::cout << "2.1. 로그인" << std::endl
		<< "> ";
	auto info = UserCollection::get().find(id, pw);
	if (info) {
		std::cout << id << " " << pw << std::endl;
	}
	return info; //로그인 
}

SignIn::~SignIn()
{
}
